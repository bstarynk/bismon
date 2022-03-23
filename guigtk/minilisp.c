// This software is in the public domain.
// adapted from github.com/rui314/minilisp/ (commit c83b57126759ef3)
// for the BISMON project

#include "minilispbismon.h"

char *program_name;
char *scriptfile;
pthread_t main_pthread;

// The pointer pointing to the beginning of the current heap
void *memory;

// The pointer pointing to the beginning of the old heap
void *from_space;

// The number of bytes allocated from the heap
size_t mem_nused;


bool gc_running;
bool debug_gc;
bool always_gc;
bool verbose_ilisp;
void
error (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  vfprintf (stderr, fmt, ap);
  fprintf (stderr, "\n");
  va_end (ap);
  show_backtrace_stderr ();
  exit (EXIT_FAILURE);
}                               /* end error */

// Constants
Obj *True = &(Obj)
{.type = TTRUE,.size = 0 };

Obj *Nil = &(Obj)
{.type = TNIL,.size = 0 };

Obj *Dot = &(Obj)
{.type = TDOT,.size = 0 };

Obj *Cparen = &(Obj)
{.type = TCPAREN,.size = 0 };

// The list containing all symbols. Such data structure is traditionally called the "obarray", but I
// avoid using it as a variable name as this is not an array but a list.
Obj *Symbols;

const char *static1_file_name (FILE * f);
const char *static2_file_name (FILE * f);
//======================================================================
// Memory management
//======================================================================

// Round up the given value to a multiple of size. Size must be a power of 2. It adds size - 1
// first, then zero-ing the least significant bits to make the result a multiple of size. I know
// these bit operations may look a little bit tricky, but it's efficient and thus frequently used.
static inline size_t
roundup (size_t var, size_t size)
{
  return (var + size - 1) & ~(size - 1);
}

long allocation_counter;

//// every 1024 allocations force a GC
#define GC_ALLOCATION_PERIOD 1024

// Allocates memory block. This may start GC if we don't have enough memory.
Obj *
alloc (void *root, int type, size_t size)
{

  allocation_counter++;

  // The object must be large enough to contain a pointer for the forwarding pointer. Make it
  // larger if it's smaller than that.
  size = roundup (size, sizeof (void *));

  // Add the size of the type tag and size fields.
  size += offsetof (Obj, lvalue);

  // Round up the object size to the nearest alignment boundary, so that the next object will be
  // allocated at the proper alignment boundary. Currently we align the object at the same
  // boundary as the pointer.
  size = roundup (size, sizeof (void *));

  // If the debug flag is on, allocate a new memory space to force all the existing objects to
  // move to new addresses, to invalidate the old addresses. By doing this the GC behavior becomes
  // more predictable and repeatable. If there's a memory bug that the C variable has a direct
  // reference to a Lisp object, the pointer will become invalid by this GC call. Dereferencing
  // that will immediately cause SEGV.
  if (always_gc && !gc_running)
    gc (root);

  // Otherwise, run GC only when the available memory is not large enough, or once every GC_ALLOCATION_PERIOD
  if (!always_gc
      && (MEMORY_SIZE < mem_nused + size
          || allocation_counter % GC_ALLOCATION_PERIOD == 0))
    gc (root);

  // Terminate the program if we couldn't satisfy the memory request. This can happen if the
  // requested size was too large or the from-space was filled with too many live objects.
  if (MEMORY_SIZE < mem_nused + size)
    error ("Memory exhausted, requested %zd", size);

  // Allocate the object.
  Obj *obj = memory + mem_nused;
  obj->type = type;
  obj->size = size;
  mem_nused += size;
  return obj;
}                               /* end alloc */


const char *
minilisp_type_name (enum objtype_en ty)
{
  switch (ty)
    {
#define TYCASE(Ty) case Ty : return #Ty;
      TYCASE (TINT);
      TYCASE (TDOUBLE);
      TYCASE (TCELL);
      TYCASE (TVECTOR);
      TYCASE (TSYMBOL);
      TYCASE (TSTRING);
      TYCASE (TJSONREF);
      TYCASE (TGTKREF);
      TYCASE (TGLIBREF);
      TYCASE (TPRIMITIVE);
      TYCASE (TFUNCTION);
      TYCASE (TMACRO);
      TYCASE (TENV);
      TYCASE (TMOVED);
      TYCASE (TTRUE);
      TYCASE (TNIL);
      TYCASE (TDOT);
      TYCASE (TCPAREN);
    default:
      {
        static char tybuf[32];
        memset (tybuf, 0, sizeof (tybuf));
        snprintf (tybuf, sizeof (tybuf) - 1, "?BadType%d?", (int) ty);
        return tybuf;
      };
    };
}                               /* end minilisp_type_name */

//======================================================================
// Garbage collector
//======================================================================

// Cheney's algorithm uses two pointers to keep track of GC status. At first both pointers point to
// the beginning of the to-space. As GC progresses, they are moved towards the end of the
// to-space. The objects before "scan1" are the objects that are fully copied. The objects between
// "scan1" and "scan2" have already been copied, but may contain pointers to the from-space. "scan2"
// points to the beginning of the free space.
Obj *scan1;
Obj *scan2;

// Moves one object from the from-space to the to-space. Returns the object's new address. If the
// object has already been moved, does nothing but just returns the new address.
static inline Obj *
forward (Obj *obj)
{
  // If the object's address is not in the from-space, the object is not managed by GC nor it
  // has already been moved to the to-space.
  ptrdiff_t offset = (uint8_t *) obj - (uint8_t *) from_space;
  if (offset < 0 || MEMORY_SIZE <= offset)
    return obj;

  // The pointer is pointing to the from-space, but the object there was a tombstone. Follow the
  // forwarding pointer to find the new location of the object.
  if (obj->type == TMOVED)
    return obj->moved;

  /// magic JSON references for {null, true, false} JSON values
  if (obj->type == TJSONREF
      && (obj == Jsonv_True || obj == Jsonv_False || obj == Jsonv_Null))
    return obj;
  // Otherwise, the object has not been moved yet. Move it.
  Obj *newloc = scan2;
  memcpy (newloc, obj, obj->size);
  scan2 = (Obj *) ((uint8_t *) scan2 + obj->size);

  // Put a tombstone at the location where the object used to occupy, so that the following call
  // of forward() can find the object's new location.
  obj->type = TMOVED;
  obj->moved = newloc;
  return newloc;
}                               /* end inline routine forward */

Obj *
forward_for_gc (Obj *ob)
{
  return forward (ob);
}                               /* end forward_for_gc */

void *
alloc_semispace ()
{
  return mmap (NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE,
               MAP_PRIVATE | MAP_ANON, -1, 0);
}

// Copies the root objects.
void
forward_root_objects (void *root)
{
  Symbols = forward (Symbols);
  for (void **frame = root; frame; frame = *(void ***) frame)
    for (int i = 1; frame[i] != ROOT_END; i++)
      if (frame[i])
        frame[i] = forward (frame[i]);
}

// Implements Cheney's copying garbage collection algorithm.
// http://en.wikipedia.org/wiki/Cheney%27s_algorithm
void
gc (void *root)
{
  assert (!gc_running);
  gc_running = true;

  clear_gtk_marks (root);
  clear_json_marks (root);

  // Allocate a new semi-space.
  from_space = memory;
  memory = alloc_semispace ();

  // Initialize the two pointers for GC. Initially they point to the beginning of the to-space.
  scan1 = scan2 = memory;

  // Copy the GC root objects first. This moves the pointer scan2.
  forward_root_objects (root);

  // Copy the objects referenced by the GC root objects located between scan1 and scan2. Once it's
  // finished, all live objects (i.e. objects reachable from the root) will have been copied to
  // the to-space.
  while (scan1 < scan2)
    {
      switch (scan1->type)
        {
          /// scalar values
        case TINT:
        case TSYMBOL:
        case TPRIMITIVE:
        case TDOUBLE:
        case TSTRING:
          // Any of the above types does not contain a pointer to a GC-managed object.
          break;
          /// reference values
        case TJSONREF:
          mark_json_ref (root, scan1);
          break;
        case TGTKREF:
          mark_gtk_ref (root, scan1);
          break;
        case TGLIBREF:
          mark_glib_ref (root, scan1);
          break;
          /// composite values
        case TCELL:
          scan1->car = forward (scan1->car);
          scan1->cdr = forward (scan1->cdr);
          break;
        case TVECTOR:
          {
            unsigned vlen = scan1->vec_len;
            for (int vix = 0; vix < (int) vlen; vix++)
              scan1->vec_comparr[vix] = forward (scan1->vec_comparr[vix]);
          }
          break;
        case TFUNCTION:
        case TMACRO:
          scan1->params = forward (scan1->params);
          scan1->body = forward (scan1->body);
          scan1->env = forward (scan1->env);
          break;
        case TENV:
          scan1->vars = forward (scan1->vars);
          scan1->up = forward (scan1->up);
          break;
        default:
          error ("Bug: copy: unknown type %d @%p",
                 scan1->type, (void *) scan1);
        }
      scan1 = (Obj *) ((uint8_t *) scan1 + scan1->size);
    }

  clean_gc_json (scan1);
  clean_gc_gtk (scan1);

  // Finish up GC.
  munmap (from_space, MEMORY_SIZE);
  size_t old_nused = mem_nused;
  mem_nused = (size_t) ((uint8_t *) scan1 - (uint8_t *) memory);
  if (debug_gc)
    {
      fprintf (stderr, "GC: %zu bytes out of %zu bytes copied.\n", mem_nused,
               old_nused);
      show_backtrace_stderr ();
    }
  gc_running = false;
}                               /* end function gc */

//======================================================================
// Constructors
//======================================================================

Obj *
make_int (void *root, long lval)
{
  Obj *r = alloc (root, TINT, sizeof (long));
  r->lvalue = lval;
  return r;
}

Obj *
cons (void *root, Obj **car, Obj **cdr)
{
  Obj *cell = alloc (root, TCELL, sizeof (Obj *) * 2);
  cell->car = *car;
  cell->cdr = *cdr;
  return cell;
}

Obj *
make_vector (void *root, unsigned len, Obj **comparr)
{
  if (len > MAX_VECTOR_LEN)
    error ("too big vector %u", len);
  Obj *vec =
    alloc (root, TVECTOR, 2 * sizeof (unsigned) + len * sizeof (Obj *));
  vec->vec_len = len;
  vec->vec_flavor = 0;
  if (comparr)
    {
      for (int ix = 0; ix < (int) len; ix++)
        vec->vec_comparr[ix] = comparr[ix];
    }
  else
    for (int ix = 0; ix < (int) len; ix++)
      vec->vec_comparr[ix] = Nil;
  return vec;
}                               /* end make_vector */

Obj *
make_symbol (void *root, const char *name)
{
  Obj *sym = alloc (root, TSYMBOL, strlen (name) + 1);
  strcpy (sym->sy_name, name);
  return sym;
}

Obj *
make_string (void *root, const char *str)
{
  long slen = str ? strlen (str) : 0;
  long utlen = 0;
  if (slen > 0)
    {
      if (slen > MEMORY_SIZE / 3)
        error ("too long string of %ld bytes starting with %.16s", slen, str);
      if (!g_utf8_validate (str, slen, NULL))
        error ("invalid non UTF8 string of %ld bytes starting with %.16s",
               slen, str);
      utlen = g_utf8_strlen (str, slen);
    }
  Obj *strv = alloc (root, TSTRING,
                     (slen | 7) + 1 + sizeof (strv->utf8_cstring) +
                     sizeof (strv->utf8_len));
  if (str)
    {
      strncpy (strv->utf8_cstring, str, slen);
      strv->utf8_len = utlen;
    }
  return strv;
}                               /* end make_string */

const char *
utf8string_in_obj (Obj *obj)
{
  if (!obj)
    return NULL;
  if (obj->type == TSTRING)
    return obj->utf8_cstring;
  return NULL;
}                               /* end utf8string_in_obj */


Obj *
make_double (void *root, double dbl)
{
  Obj *res = NULL;
  res = alloc (root, TDOUBLE, sizeof (double));
  res->dvalue = dbl;
  return res;
}                               /* end make_double */

Obj *
make_sprintf (void *root, const char *fmt, ...)
{
  char *buf = NULL;
  Obj *strv = NULL;
  int buflen = -1;
  va_list args;
  va_start (args, fmt);
  buflen = vasprintf (&buf, fmt, args);
  if (buflen >= 0 && buf)
    strv = make_string (root, buf);
  va_end (args);
  return strv;
}                               /* end make_sprintf */


Obj *
make_primitive (void *root, Primitive * fn, const char *name)
{
  Obj *r = alloc (root, TPRIMITIVE, sizeof (Primitive *) + sizeof (char *));
  r->prim_fn = fn;
  r->prim_name = name;
  return r;
}

Obj *
make_function (void *root, Obj **env, int type, Obj **params, Obj **body)
{
  static long fun_counter;
  assert (type == TFUNCTION || type == TMACRO);
  Obj *r = alloc (root, type, sizeof (Obj *) * 3 + sizeof (long));
  r->params = *params;
  r->body = *body;
  r->env = *env;
  r->fun_number = ++fun_counter;
  return r;
}

struct Obj *
make_env (void *root, Obj **vars, Obj **up)
{
  Obj *r = alloc (root, TENV, sizeof (Obj *) * 2);
  r->vars = *vars;
  r->up = *up;
  return r;
}

// Returns ((x . y) . a)
Obj *
acons (void *root, Obj **x, Obj **y, Obj **a)
{
  DEFINE1 (cell);
  *cell = cons (root, x, y);
  return cons (root, cell, a);
}

//======================================================================
// Parser
//
// This is a hand-written recursive-descendent parser.
//======================================================================

#define SYMBOL_MAX_LEN 200
const char symbol_chars[] = "~!@$%^&*-_=+:/?<>";

Obj *fread_expr (FILE * f, void *root);

int
fpeek (FILE * f)
{
  int c = fgetc (f);
  ungetc (c, f);
  return c;
}

// Destructively reverses the given list.
Obj *
reverse (Obj *p)
{
  Obj *ret = Nil;
  while (p != Nil)
    {
      Obj *head = p;
      p = p->cdr;
      head->cdr = ret;
      ret = head;
    }
  return ret;
}

// Skips the input until newline is found. Newline is one of \r, \r\n or \n.
void
skip_line (FILE * f)
{
  for (;;)
    {
      int c = fgetc (f);
      if (c == EOF || c == '\n')
        return;
      if (c == '\r')
        {
          if (fpeek (f) == '\n')
            fgetc (f);
          return;
        }
    }
}

// Reads a list. Note that '(' has already been read.
Obj *
fread_list (FILE * f, void *root)
{
  DEFINE3 (obj, head, last);
  long ofs = -1;
  assert (f != NULL);
  *head = Nil;
  for (;;)
    {
      ofs = ftell (f);
      *obj = fread_expr (f, root);
      if (!*obj)
        error ("Unclosed parenthesis in %s offset %ld",
               static1_file_name (f), ofs);
      if (*obj == Cparen)
        return reverse (*head);
      if (*obj == Dot)
        {
          *last = fread_expr (f, root);
          if (fread_expr (f, root) != Cparen)
            error ("Closed parenthesis expected after dot in %s offset %ld",
                   static1_file_name (f), ofs);
          Obj *ret = reverse (*head);
          (*head)->cdr = *last;
          return ret;
        }
      *head = cons (root, obj, head);
    }
}                               /* end fread_list */

// May create a new symbol. If there's a symbol with the same name, it will not create a new symbol
// but return the existing one.
Obj *
intern (void *root, char *name)
{
  for (Obj *p = Symbols; p != Nil; p = p->cdr)
    if (strcmp (name, p->car->sy_name) == 0)
      return p->car;
  DEFINE1 (sym);
  *sym = make_symbol (root, name);
  Symbols = cons (root, sym, &Symbols);
  return *sym;
}

// Reader marcro ' (single quote). It reads an expression and returns (quote <expr>).
Obj *
fread_quote (FILE * f, void *root)
{
  DEFINE2 (sym, tmp);
  *sym = intern (root, "quote");
  *tmp = fread_expr (f, root);
  *tmp = cons (root, tmp, &Nil);
  *tmp = cons (root, sym, tmp);
  return *tmp;
}

int
fread_number (FILE * f, int val)
{
  while (isdigit (fpeek (f)))
    val = val * 10 + (fgetc (f) - '0');
  return val;
}

Obj *
fread_symbol (FILE * f, void *root, char c)
{
  char buf[SYMBOL_MAX_LEN + 1];
  assert (f != NULL);
  buf[0] = c;
  int len = 1;
  long ofs = ftell (f);
  while (isalnum (fpeek (f)) || strchr (symbol_chars, fpeek (f)))
    {
      if (SYMBOL_MAX_LEN <= len)
        error ("Symbol name too long '%c%s' at %s offset %ld",
               c, buf, static1_file_name (f), ofs);
      buf[len++] = fgetc (f);
    }
  buf[len] = '\0';
  return intern (root, buf);
}

/// Basile syntax extension; after a # ...
/// Examples:

/***
 * #3.14  ; a double value
 * #json { "a": 2 } ; a JSON value
 ***/
Obj *
fread_hash (FILE * f, void *root)
{
  Obj *res = NULL;
  assert (f != NULL);
  int c = 0;
  int pos = -1;
  long off = 0;
  char ec = 0;
  bool ended = false;
  int bsiz = 0, blen = 0;
  char *buf = NULL;
  int delta = 0;
  int newsiz = 0;
  char *newbuf = NULL;
  double db = 0.0;
  size_t linsiz = 0;
  ssize_t linlen = 0;
  char *linbuf = NULL;
  char prefix[8];
  char endb[12];
  memset (endb, 0, sizeof (endb));
  memset (prefix, 0, sizeof (prefix));
  c = fpeek (f);
  off = ftell (f);
  if ((c >= '0' && c < '9') || c == '+' || c == '-')
    {
      db = 0.0;
      pos = -1;
      if (fscanf (f, "%lg%n", &db, &pos) > 0 && pos > 0)
        {
          return make_double (root, db);
        }
    }
  else if (c == 'j')
    {
      pos = -1;
      if (fscanf (f, "json%n", &pos) >= 0 && pos > 0)
        {
          return fread_json (f, root);
        }
    }
  /* raw string, perhaps multiline, e.g. #"ABC(xxy\tk)ABC" is the string of 6 characters xxy\tk */
  else if (c == '"' && fscanf (f, "\"%6[A-Za-z0-9](%n", prefix, &pos) >= 1
           && prefix[1] && pos > 0)
    {
      memset (endb, 0, sizeof (endb));
      snprintf (endb, sizeof (endb), ")%s\"", prefix);
      bsiz = 256;
      blen = 0;
      buf = calloc (bsiz, 1);
      if (!buf)
        {
          fprintf (stderr,
                   "calloc failed for raw string buffer of %d bytes (%m) - file %s offset %ld",
                   bsiz, static1_file_name (f), ftell (f));
          show_backtrace_stderr ();
          exit (EXIT_FAILURE);
        };
      linsiz = 128;
      linlen = 0;
      ended = false;
      off = -1;
      ec = 0;
      linbuf = calloc (linsiz, 1);
      if (!linbuf)
        {
          fprintf (stderr,
                   "calloc failed for line buffer of %zd bytes (%m) - file %s offset %ld",
                   linsiz, static1_file_name (f), ftell (f));
          show_backtrace_stderr ();
          exit (EXIT_FAILURE);
        };
      while (!ended)
        {
          assert (buf != NULL);
          assert (blen < bsiz);
          off = ftell (f);
          assert (linbuf != NULL);
          assert (linsiz > 0 && (size_t) linlen < linsiz);
          memset (linbuf, 0, linsiz);
          linlen = getline (&linbuf, &linsiz, f);
          assert (off >= 0);
          if (linlen > 0)
            {
              assert (linbuf != NULL);
              assert (linsiz > 0 && (size_t) linlen < linsiz);
              linbuf[linlen] = (char) 0;
            }
          else
            error ("unterminated raw string literal at %s offset %ld",
                   (char) c, static1_file_name (f), off);
          char *ends = strstr (linbuf, endb);
          if (ends)
            {
              ended = true;
              delta = linbuf + linlen - ends;
              fseek (f, -delta, SEEK_CUR);
              int pos = ftell (f);
              assert (pos > 0);
              *ends = (char) 0;
              linlen -= strlen (endb);
              ec = fpeek (f);
              assert (ec > 0);
            };
          if (blen + linlen + 3 >= bsiz)
            {
              newsiz = ((blen + linlen + blen / 16 + linlen / 8 + 5)
                        | 0x1f) + 1;
              assert (newsiz > bsiz);
              assert (newsiz > blen);
              newbuf = calloc (newsiz, 1);
              if (!newbuf)
                {
                  fprintf (stderr,
                           "calloc failed for new raw string buffer of %d bytes (%m) - file %s offset %ld",
                           newsiz, static1_file_name (f), ftell (f));
                  show_backtrace_stderr ();
                  exit (EXIT_FAILURE);
                };
              memcpy (newbuf, buf, blen);
              free (buf), buf = newbuf;
              bsiz = newsiz;
              buf = newbuf;
            };
          if (linlen > 0)
            {
              assert (blen + linlen + 2 < bsiz);
              strncpy (buf + blen, linbuf, linlen);
              blen += linlen;
            }
        };                      /* end while !ended */
      res = make_string (root, buf);
      fseek (f, strlen (endb), SEEK_CUR);
      off = ftell (f);
      ec = fpeek (f);
      free (buf), buf = NULL;
      assert (off > 0);
      assert (ec > 0);
      return res;
    }
#warning incomplete fread_hash
  error ("unimplemented hash syntax #%c at %s offset %ld",
         (char) c, static1_file_name (f), off);
  return NULL;
}                               /* end fread_hash */



//// read a single-lined string, whose initial double-quote °" has been read
Obj *
fread_string (FILE * f, void *root)
{
  Obj *obs = NULL;
  int c = -2;
  char smallbuf[64];
  memset (smallbuf, 0, sizeof (smallbuf));
  assert (f != NULL);
  char *buf = smallbuf;
  int blen = 0;
  int bsiz = sizeof (smallbuf) - 1;
  long ofs = ftell (f);
#define APPEND_BYTE(By) do {					\
    char by = By;						\
    if (blen >= bsiz) {						\
      char*oldbuf = buf;					\
      int newsiz = ((3*bsiz/2+2)|0x1f)+1;			\
      buf = calloc(newsiz, 1);					\
      if (!buf)							\
	error("out of memory reading string of %d bytes"	\
	      " at %s offset %ld (%m)",				\
	      blen, static1_file_name(f), ofs);			\
      memcpy(buf, oldbuf, blen);				\
      bsiz = newsiz;						\
    };								\
    buf[blen++] = by;						\
  } while(0)
  while ((c = fpeek (f)) > 0)
    {
      if (c == '"')
        {
          fgetc (f);
          break;
        };
      if (c == '\n' || c == '\r')
        error ("unterminated single-line string starting with %s"
               " at %s offset %ld (%m)", buf, static1_file_name (f), ofs);
      if (c == '\\')
        {
          c = fgetc (f);        // consume the backslash
          c = fgetc (f);        // get the next ...
          switch (c)
            {
            case '"':
              APPEND_BYTE ('\"');
              break;
            case '\'':
              APPEND_BYTE ('\'');
              break;
            case '\\':
              APPEND_BYTE ('\\');
              break;
            case 'a':
              APPEND_BYTE ('\a');
              break;
            case 'b':
              APPEND_BYTE ('\b');
              break;
            case 'e':
              APPEND_BYTE ('\e');
              break;
            case 'f':
              APPEND_BYTE ('\f');
              break;
            case 'n':
              APPEND_BYTE ('\n');
              break;
            case 'r':
              APPEND_BYTE ('\r');
              break;
            case 't':
              APPEND_BYTE ('\t');
              break;
            case 'v':
              APPEND_BYTE ('\v');
              break;
            case 'x':
              {
                int h = 0;
                if (fscanf (f, "%02x", &h) < 0)
                  error ("failed to read backslash-x escape for buffer %s"
                         " at %s offset %ld",
                         buf, static1_file_name (f), ofs);
                APPEND_BYTE ((char) h);
                break;
              }
            }
        }
      else if (c != 0)
        {
          APPEND_BYTE (c);
          c = fgetc (f);
          continue;
        }
    }
  obs = make_string (root, buf);
  if (buf != smallbuf)
    free (buf);
  return obs;
}                               /* end fread_string */

Obj *
fread_expr (FILE * f, void *root)
{
  assert (f != NULL);
  for (;;)
    {
      long off = ftell (f);
      int c = fgetc (f);
      if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
        continue;
      if (c == EOF)
        return NULL;
      if (c == ';')
        {
          skip_line (f);
          continue;
        }
      if (c == '(')
        return fread_list (f, root);
      if (c == ')')
        return Cparen;
      if (c == '.')
        return Dot;
      if (c == '\'')
        return fread_quote (f, root);
      if (c == '#')
        return fread_hash (f, root);
      if (c == '"')
        return fread_string (f, root);
      if (isdigit (c))
        return make_int (root, fread_number (f, c - '0'));
      if (c == '-' && isdigit (fpeek (f)))
        return make_int (root, -fread_number (f, 0));
      if (isalpha (c) || strchr (symbol_chars, c))
        return fread_symbol (f, root, c);
      error ("Don't know how to handle %c at %s offset %ld",
             c, static1_file_name (f), off);
    }
}                               /* end read_expr */

#define MAX_PRINT_DEPTH 20
// Prints the given object.
void
file_print (FILE * fil, Obj *obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL);
  long loff = ftell (fil);
  if (depth > MAX_PRINT_DEPTH)
    {
      fputs ("…", fil);
      return;
    }
#define LINE_WIDTH 72
#define MAYBE_NEWLINE() do {				\
    if (ftell(fil) > loff + LINE_WIDTH) {		\
      fputc('\n', fil);					\
      for (int i = (int)(depth & 0xf); i>0; i--)	\
	fputc(' ', fil);				\
      loff = ftell(fil);				\
    }							\
  } while(0)
  switch (obj->type)
    {
    case TCELL:
      fputc ('(', fil);
      for (;;)
        {
          file_print (fil, obj->car, depth + 1);
          if (obj->cdr == Nil)
            break;
          MAYBE_NEWLINE ();
          if (obj->cdr->type != TCELL)
            {
              fputs (" . ", fil);
              file_print (fil, obj->cdr, depth + 1);
              break;
            }
          fputs (" ", fil);
          obj = obj->cdr;
        }
      fputc (')', fil);
      return;
    case TVECTOR:
      fputs ("#[", fil);
      if (obj->vec_flavor != 0)
        {
          fprintf (fil, "°%d", obj->vec_flavor);
          if (obj->vec_len > 0)
            fputc (' ', fil);
        };
      {
        unsigned vlen = obj->vec_len;
        for (int vix = 0; vix < (int) vlen; vix++)
          {
            if (vix > 0)
              {
                fputs (" ", fil);
                MAYBE_NEWLINE ();
              }
            file_print (fil, obj->vec_comparr[vix], depth + 1);
          }
      }
      fputs ("]#", fil);
      return;
    case TSTRING:
      {
        const char *cstr = obj->utf8_cstring;
        unsigned ulen = obj->utf8_len;
        unsigned ucnt = 0;
        fputc ('"', fil);
        for (const char *pc = cstr; *pc; ucnt++, (pc = g_utf8_next_char (pc)))
          {
            if (ucnt % 8 == 0 && ucnt + 2 < ulen
                && ftell (fil) > loff + LINE_WIDTH)
              {
                fputs ("\\\n", fil);
                loff = ftell (fil);
              };
            switch (*pc)
              {
              case '\\':
                fputs ("\\\\", fil);
                break;
              case '\n':
                fputs ("\\n", fil);
                break;
              case '\a':
                fputs ("\\a", fil);
                break;
              case '\r':
                fputs ("\\r", fil);
                break;
              case '\t':
                fputs ("\\t", fil);
                break;
              case '\v':
                fputs ("\\v", fil);
                break;
              case '\f':
                fputs ("\\f", fil);
                break;
              case '\e':
                fputs ("\\e", fil);
                break;
              case '"':
                fputs ("\\\"", fil);
                break;
              case ' ':
                fputc (' ', fil);
                break;
              case 'a' ... 'z':
              case 'A' ... 'Z':
              case '\'':
              case '+':
              case '-':
              case '*':
              case '/':
              case '(':
              case ')':
              case '[':
              case ']':
              case '@':
              case '~':
              case '&':
              case '$':
              case '%':
              case '?':
              case ';':
              case '0' ... '9':
                fputc (*pc, fil);
                break;
              default:
                {
                  const char *nc = g_utf8_next_char (pc);
                  char buf[8];
                  memset (buf, 0, sizeof (buf));
                  strncpy (buf, pc, nc - pc);
                  fputs (buf, fil);
                }
                break;
              }
          }

        fputc ('"', fil);
      }
      return;
    case TJSONREF:
      return file_json_print (fil, obj, depth);
    case TGTKREF:
      return file_gtk_print (fil, obj, depth);
    case TGLIBREF:
      return file_glib_print (fil, obj, depth);
    case TDOT:
      if (obj == Dot)
        fprintf (fil, "<Dot>");
      else
        fprintf (fil, "<?dot@%p?>", obj);
      break;
    case TCPAREN:
      if (obj == Cparen)
        fprintf (fil, "<ClosParen>");
      else
        fprintf (fil, "<?closparen@%p?>", obj);
      break;
#define CASE(type, ...)                         \
      case type:				\
	fprintf(fil,__VA_ARGS__);		\
        return
      CASE (TINT, "%ld", obj->lvalue);
      CASE (TDOUBLE, "#%g", obj->dvalue);
      CASE (TSYMBOL, "%s", obj->sy_name);
      CASE (TPRIMITIVE, "<primitive-%s>", obj->prim_name);
      CASE (TFUNCTION, "<function#%ld>", obj->fun_number);
      CASE (TMACRO, "<macro#%ld>", obj->fun_number);
      CASE (TMOVED, "<moved>");
      CASE (TTRUE, "t");
      CASE (TNIL, "()");
#undef CASE
    default:
      error ("Bug: file_print: Unknown tag type: %d", obj->type);
    }
}                               /* end file_print */

void
print_val (Obj *obj)
{
  file_print (stdout, obj, 0);
  fflush (stdout);
}                               /* end print_val */

void
print_val_nl (Obj *obj)
{
  if (obj == NULL)
    fputs ("*nulobj*", stdout);
  else
    file_print (stdout, obj, 0);
  fputc ('\n', stdout);
  fflush (stdout);
}                               /* end print_val_nl */

// Returns the length of the given list. -1 if it's not a proper list.
int
length (Obj *list)
{
  int len = 0;
  for (; list->type == TCELL; list = list->cdr)
    len++;
  return list == Nil ? len : -1;
}

//======================================================================
// Evaluator
//======================================================================


void
add_variable (void *root, Obj **env, Obj **sym, Obj **val)
{
  DEFINE2 (vars, tmp);
  *vars = (*env)->vars;
  *tmp = acons (root, sym, val, vars);
  (*env)->vars = *tmp;
}

// Returns a newly created environment frame.
Obj *
push_env (void *root, Obj **env, Obj **vars, Obj **vals)
{
  DEFINE3 (map, sym, val);
  *map = Nil;
  for (; (*vars)->type == TCELL; *vars = (*vars)->cdr, *vals = (*vals)->cdr)
    {
      if ((*vals)->type != TCELL)
        error ("Cannot apply function: number of argument does not match");
      *sym = (*vars)->car;
      *val = (*vals)->car;
      *map = acons (root, sym, val, map);
    }
  if (*vars != Nil)
    *map = acons (root, vars, vals, map);
  return make_env (root, map, env);
}

// Evaluates the list elements from head and returns the last return value.
Obj *
progn (void *root, Obj **env, Obj **list)
{
  DEFINE2 (lp, r);
  for (*lp = *list; *lp != Nil; *lp = (*lp)->cdr)
    {
      *r = (*lp)->car;
      *r = eval (root, env, r);
    }
  return *r;
}

// Evaluates all the list elements and returns their return values as a new list.
Obj *
eval_list (void *root, Obj **env, Obj **list)
{
  DEFINE4 (head, lp, expr, result);
  *head = Nil;
  for (lp = list; *lp != Nil; *lp = (*lp)->cdr)
    {
      *expr = (*lp)->car;
      *result = eval (root, env, expr);
      *head = cons (root, result, head);
    }
  return reverse (*head);
}

bool
is_list (Obj *obj)
{
  return obj == Nil || obj->type == TCELL;
}

Obj *
apply_func (void *root, Obj **env, Obj **fn, Obj **args)
{
  assert (fn != NULL);
  if ((*fn)->type != TFUNCTION && (*fn)->type != TMACRO)
    error ("bad function to apply");
  if (!env)
    error ("missing environment in apply_func for fn#%d", (*fn)->fun_number);
  DEFINE3 (params, newenv, body);
  *params = (*fn)->params;
  *newenv = (*fn)->env;
  *newenv = push_env (root, newenv, params, args);
  *body = (*fn)->body;
  return progn (root, newenv, body);
}

// Apply fn with args.
Obj *
apply (void *root, Obj **env, Obj **fn, Obj **args)
{
  if (!is_list (*args))
    error ("argument must be a list");
  switch ((*fn)->type)
    {
    case TINT:
      error ("cannot apply integer %ld", (*fn)->lvalue);
    case TDOUBLE:
      error ("cannot apply double %g", (*fn)->dvalue);
    case TCELL:
      error ("cannot apply cons cell");
    case TVECTOR:
      error ("cannot apply vector sized %u", (*fn)->vec_len);
    case TSYMBOL:
      error ("cannot apply symbol %s", (*fn)->sy_name);
    case TSTRING:
      error ("cannot apply string %s", (*fn)->utf8_cstring);
    case TJSONREF:
      error ("cannot apply json ref#%d", (*fn)->json_index);
    case TGTKREF:
      error ("cannot apply gtk ref#%d", (*fn)->json_index);
    case TPRIMITIVE:
      return (*fn)->prim_fn (root, env, args);
    case TFUNCTION:
      {
        DEFINE1 (eargs);
        *eargs = eval_list (root, env, args);
        return apply_func (root, env, fn, eargs);
      }
    case TMACRO:
      error ("cannot apply macro #%ld", (*fn)->fun_number);
    case TENV:
      error ("cannot apply environment");
    default:
      error ("unexpected type#%d to apply", (*fn)->type);
    }
}                               /* end function apply */


// Searches for a variable by symbol. Returns null if not found.
Obj *
find (Obj **env, Obj *sym)
{
  for (Obj *p = *env; p != Nil; p = p->up)
    {
      for (Obj *cell = p->vars; cell != Nil; cell = cell->cdr)
        {
          Obj *bind = cell->car;
          if (sym == bind->car)
            return bind;
        }
    }
  return NULL;
}

// Expands the given macro application form.
Obj *
macroexpand (void *root, Obj **env, Obj **obj)
{
  if ((*obj)->type != TCELL || (*obj)->car->type != TSYMBOL)
    return *obj;
  DEFINE3 (bind, macro, args);
  *bind = find (env, (*obj)->car);
  if (!*bind || (*bind)->cdr->type != TMACRO)
    return *obj;
  *macro = (*bind)->cdr;
  *args = (*obj)->cdr;
  return apply_func (root, env, macro, args);
}

// Evaluates the S expression.
Obj *
eval (void *root, Obj **env, Obj **obj)
{
  switch ((*obj)->type)
    {
    case TINT:
    case TDOUBLE:
    case TSTRING:
    case TPRIMITIVE:
    case TFUNCTION:
    case TTRUE:
    case TNIL:
    case TGTKREF:
    case TJSONREF:
      // Self-evaluating objects
      return *obj;
    case TSYMBOL:
      {
        // Variable
        Obj *bind = find (env, *obj);
        if (!bind)
          error ("Undefined symbol: %s", (*obj)->sy_name);
        return bind->cdr;
      }
    case TCELL:
      {
        // Function application form
        DEFINE3 (fn, expanded, args);
        *expanded = macroexpand (root, env, obj);
        if (*expanded != *obj)
          return eval (root, env, expanded);
        *fn = (*obj)->car;
        *fn = eval (root, env, fn);
        *args = (*obj)->cdr;
        if ((*fn)->type != TPRIMITIVE && (*fn)->type != TFUNCTION)
          error ("The head of a list must be a function");
        return apply (root, env, fn, args);
      }
    default:
      error ("Bug: eval: Unknown tag type: %d", (*obj)->type);
    }
}

//======================================================================
// Primitive functions and special forms
//======================================================================

// 'expr
Obj *
prim_quote (void *root, Obj **env, Obj **list)
{
  assert (root != NULL);
  assert (env != NULL);
  if (length (*list) != 1)
    error ("Malformed quote");
  return (*list)->car;
}

// (cons expr expr)
Obj *
prim_cons (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed cons");
  Obj *cell = eval_list (root, env, list);
  cell->cdr = cell->cdr->car;
  return cell;
}

// (vector <expr....>)
Obj *
prim_vector (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln > MAX_VECTOR_LEN)
    error ("too big vector %u to make", ln);
  if (ln < SMALL_SIZE)
    {
      Obj *comparr[SMALL_SIZE];
      memset (comparr, 0, sizeof (comparr));
      for (int ix = 0; args && args != Nil; args = args->cdr, ix++)
        comparr[ix] = args->car;
      vec = make_vector (root, ln, comparr);
      return vec;
    }
  else
    {
      vec = make_vector (root, ln, NULL);
      for (int ix = 0; args && args != Nil; args = args->cdr, ix++)
        vec->vec_comparr[ix] = args->car;
      return vec;
    }
}                               /* end prim_vector */

/// (vector_make <length>)
Obj *
prim_vector_make (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 1)
    error ("vector_make expects a single argument - the length");
  Obj *lenarg = args->car;
  if (lenarg->type != TINT)
    error ("vector_make expects an integer length");
  int vlen = lenarg->lvalue;
  if (vlen < 0 || vlen > MAX_VECTOR_LEN)
    error ("vector_make with bad length %d", vlen);
  vec = make_vector (root, vlen, NULL);
  return vec;
}                               /* end prim_vector_make */


// (vector_length <expr>)
Obj *
prim_vector_length (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 1)
    error ("vector_length expects a single argument");
  vec = args->car;
  if (vec->type != TVECTOR)
    return Nil;
  unsigned vln = vec->vec_len;
  return make_int (root, (int) vln);
}                               /* end prim_vector_length */

// (vector_flavor <expr>)
Obj *
prim_vector_flavor (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 1)
    error ("vector_flavor expects a single argument");
  vec = args->car;
  if (vec->type != TVECTOR)
    return Nil;
  unsigned flav = vec->vec_flavor;
  return make_int (root, (int) flav);
}                               /* end prim_vector_flavor */


// (vector_put_flavor <expr-vec> <expr-flavor>)
Obj *
prim_vector_put_flavor (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 2)
    error ("vector_put_flavor expects two arguments: vector & flavor#");
  vec = args->car;
  Obj *flav = args->cdr->car;
  if (vec->type != TVECTOR)
    error ("vector_put_flavor requires a vector as first arg");
  if (flav->type != TINT)
    error ("vector_put_flavor requires a flavor# as second arg");
  vec->vec_flavor = (unsigned) flav->lvalue;
  return vec;
}                               /* end prim_vector_put_flavor */

// (vector_slice <expr-vect> <expr-startpos> <expr-endpos>)
Obj *
prim_vector_slice (void *root, Obj **env, Obj **list)
{
  Obj *vec = NULL;
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 3)
    error ("vector_slice expects three arguments: vector startpos endpos");
  vec = args->car;
  Obj *startp = args->cdr->car;
  Obj *endp = args->cdr->cdr->car;
  if (vec->type != TVECTOR)
    error ("vector_slice requires a vector as first arg");
  int vln = vec->vec_len;
  if (startp->type != TINT)
    error ("vector_slice requires a startpos as second arg");
  if (endp->type != TINT)
    error ("vector_slice requires an endpos as third arg");
  int startix = startp->lvalue;
  int endix = endp->lvalue;
  if (startix < 0)
    startix += vln;
  if (endix < 0)
    endix += vln;
  if (endix >= vln)
    endix = vln - 1;
  if (startix >= 0 && startix <= endix && endix < vln)
    return make_vector (root, endix - startix, vec->vec_comparr + startix);
  return Nil;
}                               /* end prim_vector_slice */



// (vector_fetch <expr-vec> <expr-rank>)
Obj *
prim_vector_fetch (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 2)
    error ("vector_fetch expects two arguments: the vector and the rank");
  Obj *vectarg = args->car;
  Obj *rankarg = args->cdr->car;
  if (vectarg->type != TVECTOR)
    error ("vector_fetch with non-vector first argument");
  if (rankarg->type != TINT)
    error ("vector_fetch with non-int rank second argument");
  unsigned vln = vectarg->vec_len;
  int rk = rankarg->lvalue;
  if (rk < 0)
    rk += vln;
  if (rk >= 0 && rk < (int) vln)
    return vectarg->vec_comparr[rk];
  error ("vector_fetch out of bounds: rk=%d, vln=%u", rk, vln);
}                               /* end prim_vector_fetch */


// (vector_put <expr-vec> <expr-rank> <expr-comp>) => oldcomp
Obj *
prim_vector_put (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  unsigned ln = length (args);
  if (ln != 3)
    error
      ("vector_put expects three arguments: the vector, the rank, the component");
  Obj *vectarg = args->car;
  Obj *rankarg = args->cdr->car;
  Obj *comparg = args->cdr->cdr->car;
  if (vectarg->type != TVECTOR)
    error ("vector_put with non-vector first argument");
  if (rankarg->type != TINT)
    error ("vector_put with non-int rank second argument");
  unsigned vln = vectarg->vec_len;
  int rk = rankarg->lvalue;
  if (rk < 0)
    rk += vln;
  if (rk >= 0 && rk < (int) vln)
    {
      Obj *old = vectarg->vec_comparr[rk];
      vectarg->vec_comparr[rk] = comparg;
      return old;
    };
  error ("vector_put out of bounds: rk=%d, ln=%u", rk, ln);
}                               /* end prim_vector_put */


// (car <cell>)
Obj *
prim_car (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (args->car->type != TCELL || args->cdr != Nil)
    error ("Malformed car");
  return args->car->car;
}

// (cdr <cell>)
Obj *
prim_cdr (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (args->car->type != TCELL || args->cdr != Nil)
    error ("Malformed cdr");
  return args->car->cdr;
}

// (setq <symbol> expr)
Obj *
prim_setq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2 || (*list)->car->type != TSYMBOL)
    error ("Malformed setq");
  DEFINE2 (bind, value);
  *bind = find (env, (*list)->car);
  if (!*bind)
    error ("Unbound variable %s", (*list)->car->sy_name);
  *value = (*list)->cdr->car;
  *value = eval (root, env, value);
  (*bind)->cdr = *value;
  return *value;
}

// (setcar <cell> expr)
Obj *
prim_setcar (void *root, Obj **env, Obj **list)
{
  DEFINE1 (args);
  *args = eval_list (root, env, list);
  if (length (*args) != 2 || (*args)->car->type != TCELL)
    error ("Malformed setcar");
  (*args)->car->car = (*args)->cdr->car;
  return (*args)->car;
}

// (while cond expr ...)
Obj *
prim_while (void *root, Obj **env, Obj **list)
{
  if (length (*list) < 2)
    error ("Malformed while");
  DEFINE2 (cond, exprs);
  *cond = (*list)->car;
  while (eval (root, env, cond) != Nil)
    {
      *exprs = (*list)->cdr;
      eval_list (root, env, exprs);
    }
  return Nil;
}

// (gensym)
Obj *
prim_gensym (void *root, Obj **env, Obj **list)
{
  static long int count = 0;
  assert (env != NULL);
  assert (list != NULL);
  char buf[32];
  memset (buf, 0, sizeof (buf));
  snprintf (buf, sizeof (buf) - 4, "G__%ld", count++);
  return make_symbol (root, buf);
}

// (gitid)
Obj *
prim_gitid (void *root, Obj **env, Obj **list)
{
  assert (env != NULL);
  assert (list != NULL);
  return make_string (root, BISMON_GIT);
}

// (+ <number> ...)
Obj *
prim_plus (void *root, Obj **env, Obj **list)
{
  long sum = 0;
  double dsum = 0.0;
  bool dblres = false;
  DEFINE1 (evalargs);
  *evalargs = eval_list (root, env, list);
  for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
    {
      if (args->car->type != TINT && args->car->type != TDOUBLE)
        error ("+ takes only numbers");
      if (args->car->type == TDOUBLE)
        dblres = true;
    };
  if (dblres)
    {
      for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
        {
          if (args->car->type == TINT)
            {
              dsum += (double) args->car->lvalue;
            }
          else if (args->car->type == TDOUBLE)
            {
              dsum += args->car->dvalue;
            }
        };
      return make_double (root, dsum);
    }
  else                          /*no dblres */
    {
      for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
        {
          sum += args->car->lvalue;
        };
      return make_int (root, sum);
    };
}                               /* end prim_plus */



// (- <number> ...)
Obj *
prim_minus (void *root, Obj **env, Obj **list)
{
  long sub = 0;
  double dbsub = 0.0;
  bool dblres = false;
  DEFINE1 (evalargs);
  *evalargs = eval_list (root, env, list);
  if (*evalargs == Nil || !*evalargs)
    return Nil;
  // is the result a double or an integer?
  for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
    {
      if (args->car->type != TINT && args->car->type != TDOUBLE)
        error ("- takes only numbers");
      if (args->car->type == TDOUBLE)
        dblres = true;
    };
  if (dblres)
    {
      if ((*evalargs)->car->type == TINT)
        dbsub = (double) ((*evalargs)->car->lvalue);
      else
        dbsub = (*evalargs)->car->dvalue;
      for (Obj *args = (*evalargs)->cdr;
           args && args != Nil; args = args->cdr)
        {
          if (args->car->type == TINT)
            {
              dbsub -= (double) args->car->lvalue;
            }
          else if (args->car->type == TDOUBLE)
            {
              dbsub -= args->car->dvalue;
            }
        };
      return make_double (root, dbsub);
    }
  else                          /*no dblres */
    {
      sub = (*evalargs)->car->lvalue;
      for (Obj *args = (*evalargs)->cdr;
           args && args != Nil; args = args->cdr)
        {
          sub -= args->car->lvalue;
        };
      return make_int (root, sub);
    };
}                               /* end prim_minus */



// (* <number> ...)
Obj *
prim_mult (void *root, Obj **env, Obj **list)
{
  long iprod = 1;
  double dprod = 1.0;
  bool dblres = false;
  DEFINE1 (evalargs);
  *evalargs = eval_list (root, env, list);
  for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
    {
      if (args->car->type != TINT && args->car->type != TDOUBLE)
        error ("* takes only numbers");
      if (args->car->type == TDOUBLE)
        dblres = true;
    };
  if (dblres)
    {
      for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
        {
          if (args->car->type == TINT)
            {
              dprod *= (double) args->car->lvalue;
            }
          else if (args->car->type == TDOUBLE)
            {
              dprod *= args->car->dvalue;
            }
        };
      return make_double (root, dprod);
    }
  else                          /*no dblres */
    {
      for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
        {
          iprod *= args->car->lvalue;
        };
      return make_int (root, iprod);
    };
  return Nil;
}                               /* end prim_mult */


// (/ <number> ...)
Obj *
prim_div (void *root, Obj **env, Obj **list)
{
  long idiv = 0;
  double dbdiv = 0.0;
  bool dblres = false;
  DEFINE1 (evalargs);
  *evalargs = eval_list (root, env, list);
  if (*evalargs == Nil || !*evalargs)
    return Nil;
  // is the result a double or an integer?
  for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
    {
      if (args->car->type != TINT && args->car->type != TDOUBLE)
        error ("- takes only numbers");
      if (args->car->type == TDOUBLE)
        dblres = true;
    };
  if (dblres)
    {
      if ((*evalargs)->car->type == TINT)
        dbdiv = (double) ((*evalargs)->car->lvalue);
      else
        dbdiv = (*evalargs)->car->dvalue;
      for (Obj *args = (*evalargs)->cdr;
           args && args != Nil; args = args->cdr)
        {
          if (args->car->type == TINT)
            {
              if (args->car->lvalue == 0)
                return Nil;
              dbdiv /= (double) args->car->lvalue;
            }
          else if (args->car->type == TDOUBLE)
            {
              if (args->car->dvalue == 0.0)
                return Nil;
              dbdiv /= args->car->dvalue;
            }
        };
      return make_double (root, dbdiv);
    }
  else                          /*no dblres */
    {
      idiv = (*evalargs)->car->lvalue;
      for (Obj *args = (*evalargs)->cdr;
           args && args != Nil; args = args->cdr)
        {
          if (args->car->lvalue == 0)
            return Nil;
          idiv /= args->car->lvalue;
        };
      return make_int (root, idiv);
    };
  return Nil;
}                               /* end prim_div */


// (% <number> ...) - modulus
Obj *
prim_mod (void *root, Obj **env, Obj **list)
{
  long imod = 0;
  DEFINE1 (evalargs);
  *evalargs = eval_list (root, env, list);
  if (*evalargs == Nil || !*evalargs)
    return Nil;
  // fail if some argument are not numbers
  for (Obj *args = *evalargs; args && args != Nil; args = args->cdr)
    {
      if (args->car->type != TINT && args->car->type != TDOUBLE)
        error ("% takes only numbers");
    };
  if ((*evalargs)->car->type == TINT)
    imod = (*evalargs)->car->lvalue;
  else
    imod = (long) ((*evalargs)->car->dvalue);
  for (Obj *args = (*evalargs)->cdr; args && args != Nil; args = args->cdr)
    {
      if (args->car->type == TINT)
        {
          if (args->car->lvalue == 0)
            return Nil;
          imod %= args->car->lvalue;
        }
      else if (args->car->type == TDOUBLE)
        {
          if (args->car->dvalue == 0.0)
            return Nil;
          if (isnan (args->car->dvalue))
            return Nil;
          if (isinf (args->car->dvalue))
            return Nil;
          imod %= (long) args->car->dvalue;
        };
    }
  return make_int (root, imod);
}                               /* end prim_mod */




// (< <number> <number>)    or    (< <string> <string>)   or (< <symbol> <symbol>)
Obj *
prim_lt (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("malformed <");
  Obj *x = args->car;
  Obj *y = args->cdr->car;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        {
          return x->lvalue < y->lvalue ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return ((double) x->lvalue < y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        {
          return (x->dvalue < (double) y->lvalue) ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return (x->dvalue < y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TSTRING && y->type == TSTRING)
    {
      int cmp = strcmp (x->utf8_cstring, y->utf8_cstring);
      return (cmp < 0) ? True : Nil;
    }
  else if (x->type == TSYMBOL && y->type == TSYMBOL)
    {
      int cmp = strcmp (x->sy_name, y->sy_name);
      return (cmp < 0) ? True : Nil;
    }
fail:
  error ("< takes only two numbers or two strings or two symbols");
}                               /* end prim_lt */

// (<= <number> <number>)   or  (<= <string> <string>)  or  (<= <symbol> <symbol>)
Obj *
prim_lessequal (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("malformed <=");
  Obj *x = args->car;
  Obj *y = args->cdr->car;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        {
          return x->lvalue <= y->lvalue ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return ((double) x->lvalue <= y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        {
          return (x->dvalue <= (double) y->lvalue) ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return (x->dvalue <= y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TSTRING && y->type == TSTRING)
    {
      int cmp = strcmp (x->utf8_cstring, y->utf8_cstring);
      return (cmp <= 0) ? True : Nil;
    }
  else if (x->type == TSYMBOL && y->type == TSYMBOL)
    {
      int cmp = strcmp (x->sy_name, y->sy_name);
      return (cmp <= 0) ? True : Nil;
    }
fail:
  error ("<= takes only two numbers or two strings");
}                               /* end prim_lessequal */



// (> <number> <number>)   or  (> <string> <string>)  or (> <symbol> <symbol>)
Obj *
prim_gt (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("malformed >");
  Obj *x = args->car;
  Obj *y = args->cdr->car;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        {
          return x->lvalue > y->lvalue ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return ((double) x->lvalue > y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        {
          return (x->dvalue > (double) y->lvalue) ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return (x->dvalue > y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TSTRING && y->type == TSTRING)
    {
      int cmp = strcmp (x->utf8_cstring, y->utf8_cstring);
      return (cmp > 0) ? True : Nil;
    }
  else if (x->type == TSYMBOL && y->type == TSYMBOL)
    {
      int cmp = strcmp (x->sy_name, y->sy_name);
      return (cmp > 0) ? True : Nil;
    }
fail:
  error ("> takes only two numbers or two strings or two symbols");
}                               /* end prim_gt */



// (>= <number> <number>)  or  (>= <string> <string>)  or (>= <symbol> <symbol>)
Obj *
prim_greaterequal (void *root, Obj **env, Obj **list)
{
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("malformed >=");
  Obj *x = args->car;
  Obj *y = args->cdr->car;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        {
          return x->lvalue >= y->lvalue ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return ((double) x->lvalue >= y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        {
          return (x->dvalue >= (double) y->lvalue) ? True : Nil;
        }
      else if (y->type == TDOUBLE)
        {
          return (x->dvalue >= y->dvalue) ? True : Nil;
        }
      else
        goto fail;
    }
  else if (x->type == TSTRING && y->type == TSTRING)
    {
      int cmp = strcmp (x->utf8_cstring, y->utf8_cstring);
      return (cmp >= 0) ? True : Nil;
    }
  else if (x->type == TSYMBOL && y->type == TSYMBOL)
    {
      int cmp = strcmp (x->sy_name, y->sy_name);
      return (cmp > 0) ? True : Nil;
    }
fail:
  error (">= takes only two numbers or two strings or two symbols");
}                               /* end prim_greaterequal */



Obj *
handle_function (void *root, Obj **env, Obj **list, int type)
{
  if ((*list)->type != TCELL || !is_list ((*list)->car)
      || (*list)->cdr->type != TCELL)
    error ("Malformed lambda");
  Obj *p = (*list)->car;
  for (; p->type == TCELL; p = p->cdr)
    if (p->car->type != TSYMBOL)
      error ("Parameter must be a symbol");
  if (p != Nil && p->type != TSYMBOL)
    error ("Parameter must be a symbol");
  DEFINE2 (params, body);
  *params = (*list)->car;
  *body = (*list)->cdr;
  return make_function (root, env, type, params, body);
}

// (lambda (<symbol> ...) expr ...)
Obj *
prim_lambda (void *root, Obj **env, Obj **list)
{
  return handle_function (root, env, list, TFUNCTION);
}

Obj *
handle_defun (void *root, Obj **env, Obj **list, int type)
{
  if ((*list)->car->type != TSYMBOL || (*list)->cdr->type != TCELL)
    error ("Malformed defun");
  DEFINE3 (fn, sym, rest);
  *sym = (*list)->car;
  *rest = (*list)->cdr;
  *fn = handle_function (root, env, rest, type);
  add_variable (root, env, sym, fn);
  return *fn;
}

// (defun <symbol> (<symbol> ...) expr ...)
Obj *
prim_defun (void *root, Obj **env, Obj **list)
{
  return handle_defun (root, env, list, TFUNCTION);
}

// (define <symbol> expr)
Obj *
prim_define (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2 || (*list)->car->type != TSYMBOL)
    error ("Malformed define");
  DEFINE2 (sym, value);
  *sym = (*list)->car;
  *value = (*list)->cdr->car;
  *value = eval (root, env, value);
  add_variable (root, env, sym, value);
  return *value;
}

// (defmacro <symbol> (<symbol> ...) expr ...)
Obj *
prim_defmacro (void *root, Obj **env, Obj **list)
{
  return handle_defun (root, env, list, TMACRO);
}

// (macroexpand expr)
Obj *
prim_macroexpand (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 1)
    error ("Malformed macroexpand");
  DEFINE1 (body);
  *body = (*list)->car;
  return macroexpand (root, env, body);
}

// (println expr)
Obj *
prim_println (void *root, Obj **env, Obj **list)
{
  DEFINE1 (tmp);
  *tmp = (*list)->car;
  print_val (eval (root, env, tmp));
  printf ("\n");
  return Nil;
}


// (list ....)
Obj *
prim_list (void *root, Obj **env, Obj **list)
{
  Obj *values = eval_list (root, env, list);
  return values;
}                               /* end prim_list */

// (if expr expr expr ...)
Obj *
prim_if (void *root, Obj **env, Obj **list)
{
  if (length (*list) < 2)
    error ("Malformed if");
  DEFINE3 (cond, then, els);
  *cond = (*list)->car;
  *cond = eval (root, env, cond);
  if (*cond != Nil)
    {
      *then = (*list)->cdr->car;
      return eval (root, env, then);
    }
  *els = (*list)->cdr->cdr;
  return *els == Nil ? Nil : progn (root, env, els);
}


bool
recursive_equal (Obj *x, Obj *y, unsigned depth)
{
  if (x == y)
    return true;
  if (depth > MAX_RECURSIVE_DEPTH)
    return false;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        return x->lvalue == y->lvalue;
      else if (y->type == TDOUBLE)
        return (double) x->lvalue == y->dvalue;
      else
        return false;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        return x->dvalue == (double) y->lvalue;
      else if (y->type == TDOUBLE)
        return x->dvalue == y->dvalue;
      else
        return false;
    }
  if (x->type != y->type)
    return false;
  switch (x->type)
    {
    case TSTRING:
      if (x->utf8_len == y->utf8_len
          && !strcmp (x->utf8_cstring, y->utf8_cstring))
        return true;
      else
        return false;
    case TSYMBOL:
    case TTRUE:
    case TNIL:
    case TDOT:
    case TCPAREN:
      return false;
    case TCELL:
      if (length (x) != length (y))
        return false;
      {
        Obj *curx = x;
        Obj *cury = y;
        int count = 0;
        while (curx && cury)
          {
            if (!recursive_equal (curx->car, cury->car, depth + 1))
              return false;
            if (count++ > 2 * MAX_VECTOR_LEN)
              return false;
            curx = x->cdr;
            cury = y->cdr;
          }
      }
      return true;
    case TVECTOR:
      if (x->vec_len != y->vec_len)
        return false;
      if (x->vec_flavor != y->vec_flavor)
        return false;
      {
        unsigned ln = x->vec_len;
        for (int i = 0; i < (int) ln; i++)
          if (!recursive_equal
              (x->vec_comparr[i], y->vec_comparr[i], depth + 1))
            return false;
        return true;
      }
    case TENV:
      if (recursive_equal (x->vars, y->vars, depth + 1))
        return true;
      if (recursive_equal (x->up, y->up, depth + 1))
        return true;
      return false;
    case TJSONREF:
      if (x->json_index == y->json_index)
        return true;
      else
        {
          extern bool jsonref_recursive_equal (Obj *x, Obj *y,
                                               unsigned depth);
          return jsonref_recursive_equal (x, y, depth);
        };
      return false;
    case TGTKREF:
      if (x->gtk_index == y->gtk_index)
        return true;
      else
        {
          extern bool gtkref_recursive_equal (Obj *x, Obj *y, unsigned depth);
          return gtkref_recursive_equal (x, y, depth);
        };
      return false;
    case TPRIMITIVE:
    case TFUNCTION:
    case TMACRO:
      if (!recursive_equal (x->params, y->params, depth + 1))
        return false;
      if (!recursive_equal (x->body, y->body, depth + 1))
        return false;
      if (!recursive_equal (x->env, y->env, depth + 1))
        return false;
      return true;
    default:
      return false;
    }
  return false;
}                               /* end recursive_equal */


// (= <scalar> <scalar>)
Obj *
prim_scalar_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed =");
  Obj *values = eval_list (root, env, list);
  Obj *x = values->car;
  Obj *y = values->cdr->car;
  if (x->type == TINT)
    {
      if (y->type == TINT)
        return x->lvalue == y->lvalue ? True : Nil;
      else if (y->type == TDOUBLE)
        return (double) x->lvalue == y->dvalue ? True : Nil;
      else
        goto fail;
    }
  else if (x->type == TDOUBLE)
    {
      if (y->type == TINT)
        return x->dvalue == (double) y->lvalue ? True : Nil;
      else if (y->type == TDOUBLE)
        return x->dvalue == y->dvalue ? True : Nil;
      else
        goto fail;
    }
  else if (x->type == TSTRING && y->type == TSTRING)
    {
      if (x->utf8_len == y->utf8_len
          && !strcmp (x->utf8_cstring, y->utf8_cstring))
        return True;
      else
        return Nil;
    }
  else if (x->type == TJSONREF && y->type == TJSONREF)
    return prim_json_eq (root, env, list);
  else if (x->type == TGTKREF && y->type == TGTKREF)
    return prim_gtk_eq (root, env, list);
fail:
  error ("= only takes scalars");
}                               /* end prim_scalar_eq for = */

// (eq expr expr)
Obj *
prim_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed eq");
  Obj *values = eval_list (root, env, list);
  return values->car == values->cdr->car ? True : Nil;
}

// (load "filename")
Obj *
prim_load (void *root, Obj **env, Obj **list)
{
  char filnam[256];
  memset (filnam, 0, sizeof (filnam));
  if (length (*list) != 1)
    error ("load requires a single argument");
  Obj *values = eval_list (root, env, list);
  Obj *firstarg = values->car;
  if (firstarg->type == TSTRING
      && firstarg->utf8_len < 3 * sizeof (filnam) / 4
      && strlen (firstarg->utf8_cstring) < sizeof (filnam))
    {
      strcpy (filnam, firstarg->utf8_cstring);
      int nbscrexpr = load_file (filnam, LOAD_FULL_LOADED_FILE, root, env);
      if (nbscrexpr >= 0)
        return make_int (root, nbscrexpr);
    }
  return Nil;
}                               /* end prim_load */


// (load_skipped "filename")
Obj *
prim_load_skipped (void *root, Obj **env, Obj **list)
{
  char filnam[256];
  memset (filnam, 0, sizeof (filnam));
  if (length (*list) != 1)
    error ("load_skipped requires a single argument");
  Obj *values = eval_list (root, env, list);
  Obj *firstarg = values->car;
  if (firstarg->type == TSTRING
      && firstarg->utf8_len < 3 * sizeof (filnam) / 4
      && strlen (firstarg->utf8_cstring) < sizeof (filnam))
    {
      strcpy (filnam, firstarg->utf8_cstring);
      int nbscrexpr = load_file (filnam, SKIP_HEAD_LOADED_FILE, root, env);
      if (nbscrexpr >= 0)
        return make_int (root, nbscrexpr);
    }
  return Nil;
}                               /* end prim_load_skipped */


void
add_primitive (void *root, Obj **env, char *name, Primitive * fn)
{
  DEFINE2 (sym, prim);
  *sym = intern (root, name);
  *prim = make_primitive (root, fn, name);
  add_variable (root, env, sym, prim);
}

void
define_constants (void *root, Obj **env)
{
  DEFINE1 (sym);
  *sym = intern (root, "t");
  add_variable (root, env, sym, &True);
}

void
define_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "quote", prim_quote);
  add_primitive (root, env, "cons", prim_cons);
  add_primitive (root, env, "car", prim_car);
  add_primitive (root, env, "cdr", prim_cdr);
  add_primitive (root, env, "setq", prim_setq);
  add_primitive (root, env, "setcar", prim_setcar);
  add_primitive (root, env, "while", prim_while);
  add_primitive (root, env, "gensym", prim_gensym);
  add_primitive (root, env, "gitid", prim_gitid);
  add_primitive (root, env, "+", prim_plus);
  add_primitive (root, env, "-", prim_minus);
  add_primitive (root, env, "*", prim_mult);
  add_primitive (root, env, "/", prim_div);
  add_primitive (root, env, "%", prim_mod);
  add_primitive (root, env, "<", prim_lt);
  add_primitive (root, env, ">", prim_gt);
  add_primitive (root, env, "<=", prim_lessequal);
  add_primitive (root, env, ">=", prim_greaterequal);
  add_primitive (root, env, "define", prim_define);
  add_primitive (root, env, "defun", prim_defun);
  add_primitive (root, env, "defmacro", prim_defmacro);
  add_primitive (root, env, "macroexpand", prim_macroexpand);
  add_primitive (root, env, "lambda", prim_lambda);
  add_primitive (root, env, "list", prim_list);
  add_primitive (root, env, "load", prim_load);
  add_primitive (root, env, "load_skipped", prim_load_skipped);
  add_primitive (root, env, "if", prim_if);
  add_primitive (root, env, "=", prim_scalar_eq);
  add_primitive (root, env, "eq", prim_eq);
  add_primitive (root, env, "println", prim_println);
  add_primitive (root, env, "vector", prim_vector);
  add_primitive (root, env, "vector_make", prim_vector_make);
  add_primitive (root, env, "vector_length", prim_vector_length);
  add_primitive (root, env, "vector_flavor", prim_vector_flavor);
  add_primitive (root, env, "vector_fetch", prim_vector_fetch);
  add_primitive (root, env, "vector_put", prim_vector_put);
  add_primitive (root, env, "vector_put_flavor", prim_vector_put_flavor);
  add_primitive (root, env, "vector_slice", prim_vector_slice);
}                               /* end define_primitives */


/// load a file, evaluating each s-expr, and return -1 on error, and
/// the number of evaluated expressions otherwise. If skiphead is
/// true, ignore first lines up to a line like ;;;+++
int
load_file (const char *filnam, bool skiphead, void *root, Obj **env)
{
  FILE *fil = filnam ? fopen (filnam, "r") : stdin;
  char linbuf[256];
  memset (linbuf, 0, sizeof (linbuf));
  if (!filnam)
    {
      if (isatty (STDIN_FILENO))
        filnam = "*terminal*";
      else
        filnam = "*stdin*";
    };
  if (!fil)
    {
      fprintf (stderr, "%s: cannot open file %s to load - %m", program_name,
               filnam);
      show_backtrace_stderr ();
      return -1;
    };
  assert (filnam != NULL);
  DEFINE1 (expr);
  if (skiphead)
    {
      if (verbose_ilisp)
        {
          printf (";;%s git %s start reading %s\n", program_name,
                  BISMON_GIT, filnam);
          fflush (NULL);
        };
      do
        {
          memset (linbuf, 0, sizeof (linbuf));
          char *li = fgets (linbuf, sizeof (linbuf) - 1, fil);
          if (!li)
            break;
          if (!strncmp (linbuf, ";;;+++", 6))
            break;
        }
      while (!feof (fil));
    };
  int nbexpr = 0;
  if (skiphead)
    {
      if (verbose_ilisp)
        {
          if (ftell (fil) > 0)
            printf (";;%s git %s start reading at offset #%ld of %s\n",
                    program_name, BISMON_GIT, ftell (fil), filnam);
          else
            printf (";;%s git %s start reading terminal\n",
                    program_name, BISMON_GIT);
        }
    };
  while (!feof (fil))
    {
      long off = ftell (fil);
      *expr = fread_expr (fil, root);
      nbexpr++;
      if (off >= 0 && verbose_ilisp)
        printf (";; %s: expression#%d at offset %ld of %s\n",
                program_name, nbexpr, off, filnam);
      else if (verbose_ilisp)
        printf (";; %s: expression#%d of %s\n", program_name, nbexpr, filnam);
      if (!*expr)
        return nbexpr;
      if (*expr == Cparen)
        error ("Stray close parenthesis in %s offset %ld", filnam, off);
      if (*expr == Dot)
        error ("Stray dot in %s offset %ld", filnam, off);
      if (verbose_ilisp)
        printf
          (";; %s git %s at offset #%ld of scriptfile %s expression...\n",
           program_name, BISMON_GIT, off, filnam);
      print_val (*expr);
      printf ("  => ");
      print_val_nl (eval (root, env, expr));
    };
  if (verbose_ilisp)
    {
      if (ftell (fil) > 0)
        printf
          (";; %s git %s evaluated %d expressions in %s (offset %ld)\n",
           program_name, BISMON_GIT, nbexpr, filnam, ftell (fil));
      else
        printf
          (";; %s git %s evaluated %d expressions in %s\n", program_name,
           BISMON_GIT, nbexpr, filnam);
    };
  if (fil != stdin)
    fclose (fil);
  return nbexpr;
}                               /* end load_file */

//======================================================================
// Entry point
//======================================================================

// Returns true if the environment variable is defined and not the empty string.
bool
getEnvFlag (char *name)
{
  char *val = getenv (name);
  return val && val[0];
}

int
main (int argc, char **argv)
{
#define MAX_ARGV_LEN 1024

  program_name = basename (argv[0]);
  main_pthread = pthread_self ();
  char *gtkargs[MAX_ARGV_LEN];
  memset (gtkargs, 0, sizeof (gtkargs));
  int gtkargc = 0;
  bool help_wanted = false;
  if (argc == 2 && !strcmp (argv[1], "--version"))
    {
      printf
        ("%s git %s built on %s at %s (see github.com/btarynk/bismon/ ....)\n",
         program_name, BISMON_GIT, __DATE__, __TIME__);
      exit (EXIT_SUCCESS);
    };
  if (argc + 1 > MAX_ARGV_LEN)
    {
      fprintf (stderr,
               "%s git %s built on %s at %s (see github.com/btarynk/bismon/ ....) accepts no more that %d arguments but got %d\n",
               program_name, BISMON_GIT, __DATE__, __TIME__, MAX_ARGV_LEN - 2,
               argc);
      exit (EXIT_FAILURE);
    }
  gtkargs[0] = program_name;
  gtkargc = 1;
  for (int i = 1; i < argc; i++)
    {
      if (!argv[i])
        continue;
      if (!strcmp (argv[i], "-v") || !strcmp (argv[1], "--verbose"))
        {
          verbose_ilisp = true;
          continue;
        }
      else if (!strcmp (argv[i], "-h") || !strcmp (argv[i], "--help"))
        {
          help_wanted = true;
          continue;
        }
      else if (!strcmp (argv[i], "--debug-gc"))
        {
          debug_gc = true;
          continue;
        }
      else if (!strcmp (argv[i], "--always-gc"))
        {
          always_gc = true;
          continue;
        }
      if (i + 1 < argc
          && argv[i + 1] != NULL
          && (!strcmp (argv[i], "-s") || !strcmp (argv[i], "--script")))
        {
          scriptfile = argv[i + 1];
          i++;
          continue;
        }
      else
        gtkargs[gtkargc++] = argv[i];
    }
  initialize_json ();
  initialize_gtk (&gtkargc, &gtkargv);
  initialize_glib ();

  if (help_wanted)
    {
      printf ("%s (a minilisp interpreter) usage:\n", program_name);
      printf ("\t -v | --verbose     # verbose interaction\n");
      printf ("\t -h | --help        # this help\n");
      printf ("\t --debug-gc         # debug garbage collector\n");
      printf ("\t --always-gc        # always run a GC\n");
      printf ("See source code on github.com/bstarynk/bismon/ in\n"
              "\t its guigtk/ subdirectory\n");
      printf
        ("*NO WARRANTY* since GPLv3+ licensed; see www.gnu.org/licenses/\n");
      printf ("Environment variables:\n"
              "\t MINILISP_DEBUG_GC same as --debug-gc\n"
              "\t MINILISP_ALWAYS_GC same as --always-gc\n");
      printf ("git %s built at %s@%s\n", BISMON_GIT, __DATE__, __TIME__);
      printf
        ("Contact <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>\n");
      printf ("Adapted from github.com/rui314/minilisp/ (public domain)\n");
      printf ("That Minilisp was by Rui Ueyama, <rui314@gmail.com>\n");
      fflush (NULL);
      exit (EXIT_SUCCESS);
    }
  // Debug flags
  debug_gc = getEnvFlag ("MINILISP_DEBUG_GC");
  always_gc = getEnvFlag ("MINILISP_ALWAYS_GC");


  // Memory allocation
  memory = alloc_semispace ();

  // Constants and primitives
  Symbols = Nil;
  void *root = NULL;
  DEFINE1 (env);
  *env = make_env (root, &Nil, &Nil);
  define_constants (root, env);
  define_primitives (root, env);
  define_json_primitives (root, env);
  define_gtk_primitives (root, env);

  if (scriptfile)
    {
      if (verbose_ilisp)
        {
          printf (";;%s (git %s) reading script file %s\n",
                  program_name, BISMON_GIT, scriptfile);
          fflush (NULL);
        }
      int nbscrexpr =
        load_file (scriptfile, SKIP_HEAD_LOADED_FILE, root, env);
      if (nbscrexpr <= 0)
        exit (EXIT_FAILURE);
      if (verbose_ilisp)
        printf (";;%s (git %s) did load %d expressions from script file %s\n",
                program_name, BISMON_GIT, nbscrexpr, scriptfile);
    }
  else
    {
      if (verbose_ilisp)
        {
          printf (";;%s (git %s) reading stdin\n", program_name, BISMON_GIT);
          fflush (NULL);
        }
      int nbreplexpr = load_file (NULL, LOAD_FULL_LOADED_FILE, root, env);
      if (nbreplexpr <= 0)
        exit (EXIT_FAILURE);
      if (verbose_ilisp)
        printf (";;%s (git %s) did load %d expressions from stdin\n",
                program_name, BISMON_GIT, nbreplexpr);
    }
  fflush (NULL);
  exit (EXIT_SUCCESS);
}                               /* end main */





/// Linux specific, see proc(5)
const char *
static1_file_name (FILE * f)
{
  static char nambuf1[256];
  if (!f)
    return "[no-file]";
  if (f == stdin)
    return "[stdin]";
  if (f == stdout)
    return "[stdout]";
  if (f == stderr)
    return "[stderr]";
  int fino = fileno (f);
  if (fino > 0)
    {
      char fbuf[64];
      memset (fbuf, 0, sizeof (fbuf));
      memset (nambuf1, 0, sizeof (nambuf1));
      snprintf (fbuf, sizeof (fbuf), "/proc/self/fd/%d", fino);
      if (readlink (fbuf, nambuf1, sizeof (nambuf1) - 1) > 0)
        return nambuf1;
      snprintf (nambuf1, sizeof (nambuf1) - 1, "[fd#%d]", fino);
    }
  else
    snprintf (nambuf1, sizeof (nambuf1) - 1, "[FILE@%p]", f);
  return nambuf1;
}                               /// end static1_file_name


const char *
static2_file_name (FILE * f)
{
  static char nambuf2[256];
  if (!f)
    return "[no-file]";
  if (f == stdin)
    return "[stdin]";
  if (f == stdout)
    return "[stdout]";
  if (f == stderr)
    return "[stderr]";
  int fino = fileno (f);
  if (fino > 0)
    {
      char fbuf[64];
      memset (fbuf, 0, sizeof (fbuf));
      memset (nambuf2, 0, sizeof (nambuf2));
      snprintf (fbuf, sizeof (fbuf), "/proc/self/fd/%d", fino);
      if (readlink (fbuf, nambuf2, sizeof (nambuf2) - 1) > 0)
        return nambuf2;
      snprintf (nambuf2, sizeof (nambuf2) - 1, "[fd#%d]", fino);
    }
  else
    snprintf (nambuf2, sizeof (nambuf2) - 1, "[FILE@%p]", f);
  return nambuf2;
}                               /// end static2_file_name


void
show_backtrace_stderr (void)
{
  void *backbuf[MAX_RECURSIVE_DEPTH + 2];
  memset (backbuf, 0, sizeof (backbuf));
  fflush (NULL);
  int nb = backtrace (backbuf, MAX_RECURSIVE_DEPTH);
  if (nb < 0)
    nb = 0;
  else if (nb > MAX_RECURSIVE_DEPTH)
    nb = MAX_RECURSIVE_DEPTH;
  backtrace_symbols_fd (backbuf, nb, STDERR_FILENO);
}                               /* end show_backtrace_stderr */

/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/
