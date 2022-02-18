// This software is in the public domain.
// adapted from github.com/rui314/minilisp/ (commit c83b57126759ef3)
// for the BISMON project

#include "minilispbismon.h"

void
error (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  vfprintf (stderr, fmt, ap);
  fprintf (stderr, "\n");
  va_end (ap);
  exit (EXIT_FAILURE);
}                               /* end error */

// Constants
Obj *True = &(Obj) {.type = TTRUE,.size = 0 };
Obj *Nil = &(Obj) {.type = TNIL,.size = 0 };
Obj *Dot = &(Obj) {.type = TDOT,.size = 0 };
Obj *Cparen = &(Obj) {.type = TCPAREN,.size = 0 };

// The list containing all symbols. Such data structure is traditionally called the "obarray", but I
// avoid using it as a variable name as this is not an array but a list.
Obj *Symbols;

//======================================================================
// Memory management
//======================================================================

// The size of the heap in byte
#define MEMORY_SIZE (16*1024*1024)

// The pointer pointing to the beginning of the current heap
void *memory;

// The pointer pointing to the beginning of the old heap
void *from_space;

// The number of bytes allocated from the heap
size_t mem_nused = 0;

// Flags to debug GC
bool gc_running = false;
bool debug_gc = false;
bool always_gc = false;

void gc (void *root);

// Currently we are using Cheney's copying GC algorithm, with which the available memory is split
// into two halves and all objects are moved from one half to another every time GC is invoked. That
// means the address of the object keeps changing. If you take the address of an object and keep it
// in a C variable, dereferencing it could cause SEGV because the address becomes invalid after GC
// runs.
//
// In order to deal with that, all access from C to Lisp objects will go through two levels of
// pointer dereferences. The C local variable is pointing to a pointer on the C stack, and the
// pointer is pointing to the Lisp object. GC is aware of the pointers in the stack and updates
// their contents with the objects' new addresses when GC happens.
//
// The following is a macro to reserve the area in the C stack for the pointers. The contents of
// this area are considered to be GC root.
//
// Be careful not to bypass the two levels of pointer indirections. If you create a direct pointer
// to an object, it'll cause a subtle bug. Such code would work in most cases but fails with SEGV if
// GC happens during the execution of the code. Any code that allocates memory may invoke GC.

#define ROOT_END ((void *)-1)

#define ADD_ROOT(size)                          \
    void *root_ADD_ROOT_[size + 2];             \
    root_ADD_ROOT_[0] = root;                   \
    for (int i = 1; i <= size; i++)             \
        root_ADD_ROOT_[i] = NULL;               \
    root_ADD_ROOT_[size + 1] = ROOT_END;        \
    root = root_ADD_ROOT_

#define DEFINE1(var1)                           \
    ADD_ROOT(1);                                \
    Obj **var1 = (Obj **)(root_ADD_ROOT_ + 1)

#define DEFINE2(var1, var2)                     \
    ADD_ROOT(2);                                \
    Obj **var1 = (Obj **)(root_ADD_ROOT_ + 1);  \
    Obj **var2 = (Obj **)(root_ADD_ROOT_ + 2)

#define DEFINE3(var1, var2, var3)               \
    ADD_ROOT(3);                                \
    Obj **var1 = (Obj **)(root_ADD_ROOT_ + 1);  \
    Obj **var2 = (Obj **)(root_ADD_ROOT_ + 2);  \
    Obj **var3 = (Obj **)(root_ADD_ROOT_ + 3)

#define DEFINE4(var1, var2, var3, var4)         \
    ADD_ROOT(4);                                \
    Obj **var1 = (Obj **)(root_ADD_ROOT_ + 1);  \
    Obj **var2 = (Obj **)(root_ADD_ROOT_ + 2);  \
    Obj **var3 = (Obj **)(root_ADD_ROOT_ + 3);  \
    Obj **var4 = (Obj **)(root_ADD_ROOT_ + 4)

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
    error ("Memory exhausted");

  // Allocate the object.
  Obj *obj = memory + mem_nused;
  obj->type = type;
  obj->size = size;
  mem_nused += size;
  return obj;
}

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
inline Obj *
forward (Obj * obj)
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

  // Otherwise, the object has not been moved yet. Move it.
  Obj *newloc = scan2;
  memcpy (newloc, obj, obj->size);
  scan2 = (Obj *) ((uint8_t *) scan2 + obj->size);

  // Put a tombstone at the location where the object used to occupy, so that the following call
  // of forward() can find the object's new location.
  obj->type = TMOVED;
  obj->moved = newloc;
  return newloc;
}

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

  clear_gtk_json_marks (root);

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
        case TCELL:
          scan1->car = forward (scan1->car);
          scan1->cdr = forward (scan1->cdr);
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
          error ("Bug: copy: unknown type %d", scan1->type);
        }
      scan1 = (Obj *) ((uint8_t *) scan1 + scan1->size);
    }

  clean_gc_json_gtk (scan1);

  // Finish up GC.
  munmap (from_space, MEMORY_SIZE);
  size_t old_nused = mem_nused;
  mem_nused = (size_t) ((uint8_t *) scan1 - (uint8_t *) memory);
  if (debug_gc)
    fprintf (stderr, "GC: %zu bytes out of %zu bytes copied.\n", mem_nused,
             old_nused);
  gc_running = false;
}

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
cons (void *root, Obj ** car, Obj ** cdr)
{
  Obj *cell = alloc (root, TCELL, sizeof (Obj *) * 2);
  cell->car = *car;
  cell->cdr = *cdr;
  return cell;
}

Obj *
make_symbol (void *root, char *name)
{
  Obj *sym = alloc (root, TSYMBOL, strlen (name) + 1);
  strcpy (sym->name, name);
  return sym;
}

Obj *
make_string (void *root, char *str)
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
  Obj *strv = alloc (root, TSTRING, slen + 1);
  if (str)
    {
      strcpy (strv->utf8_cstring, str);
      strv->utf8_len = utlen;
    }
  return strv;
}                               /* end make_string */

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
  Obj *r = alloc (root, TPRIMITIVE, sizeof (Primitive *));
  r->prim_fn = fn;
  r->prim_name = name;
  return r;
}

Obj *
make_function (void *root, Obj ** env, int type, Obj ** params, Obj ** body)
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
make_env (void *root, Obj ** vars, Obj ** up)
{
  Obj *r = alloc (root, TENV, sizeof (Obj *) * 2);
  r->vars = *vars;
  r->up = *up;
  return r;
}

// Returns ((x . y) . a)
Obj *
acons (void *root, Obj ** x, Obj ** y, Obj ** a)
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
reverse (Obj * p)
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
  *head = Nil;
  for (;;)
    {
      *obj = fread_expr (f, root);
      if (!*obj)
        error ("Unclosed parenthesis");
      if (*obj == Cparen)
        return reverse (*head);
      if (*obj == Dot)
        {
          *last = fread_expr (f, root);
          if (fread_expr (f, root) != Cparen)
            error ("Closed parenthesis expected after dot");
          Obj *ret = reverse (*head);
          (*head)->cdr = *last;
          return ret;
        }
      *head = cons (root, obj, head);
    }
}

// May create a new symbol. If there's a symbol with the same name, it will not create a new symbol
// but return the existing one.
Obj *
intern (void *root, char *name)
{
  for (Obj * p = Symbols; p != Nil; p = p->cdr)
    if (strcmp (name, p->car->name) == 0)
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
  buf[0] = c;
  int len = 1;
  while (isalnum (fpeek (f)) || strchr (symbol_chars, fpeek (f)))
    {
      if (SYMBOL_MAX_LEN <= len)
        error ("Symbol name too long");
      buf[len++] = fgetc (f);
    }
  buf[len] = '\0';
  return intern (root, buf);
}

/// Basile syntax extension; after a # ...
Obj *
fread_hash (FILE * f, void *root)
{
  int c = fpeek (f);
  if ((c >= '0' && c < '9') || c == '+' || c == '-')
    {
    }
}                               /* end fread_hash */

Obj *
fread_expr (FILE * f, void *root)
{
  for (;;)
    {
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
      if (isdigit (c))
        return make_int (root, fread_number (f, c - '0'));
      if (c == '-' && isdigit (fpeek (f)))
        return make_int (root, -fread_number (f, 0));
      if (isalpha (c) || strchr (symbol_chars, c))
        return fread_symbol (f, root, c);
      error ("Don't know how to handle %c", c);
    }
}                               /* end read_expr */

// Prints the given object.
void
file_print (FILE * fil, Obj * obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL);
  long loff = ftell (fil);
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

#define CASE(type, ...)                         \
      case type:				\
	fprintf(fil,__VA_ARGS__);		\
        return
      CASE (TINT, "%ld", obj->lvalue);
      CASE (TDOUBLE, "%g", obj->dvalue);
      CASE (TSYMBOL, "%s", obj->name);
      CASE (TPRIMITIVE, "<primitive-%s>", obj->prim_name);
      CASE (TFUNCTION, "<function#%ld>", obj->fun_number);
      CASE (TMACRO, "<macro#%ld>", obj->fun_number);
      CASE (TMOVED, "<moved>");
      CASE (TTRUE, "t");
      CASE (TNIL, "()");
#undef CASE
    default:
      error ("Bug: print: Unknown tag type: %d", obj->type);
    }
}                               /* end file_print */

void
print (Obj * obj)
{
  file_print (stdout, obj, 0);
}                               /* end print */

// Returns the length of the given list. -1 if it's not a proper list.
int
length (Obj * list)
{
  int len = 0;
  for (; list->type == TCELL; list = list->cdr)
    len++;
  return list == Nil ? len : -1;
}

//======================================================================
// Evaluator
//======================================================================

Obj *eval (void *root, Obj ** env, Obj ** obj);

void
add_variable (void *root, Obj ** env, Obj ** sym, Obj ** val)
{
  DEFINE2 (vars, tmp);
  *vars = (*env)->vars;
  *tmp = acons (root, sym, val, vars);
  (*env)->vars = *tmp;
}

// Returns a newly created environment frame.
Obj *
push_env (void *root, Obj ** env, Obj ** vars, Obj ** vals)
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
progn (void *root, Obj ** env, Obj ** list)
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
eval_list (void *root, Obj ** env, Obj ** list)
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
is_list (Obj * obj)
{
  return obj == Nil || obj->type == TCELL;
}

Obj *
apply_func (void *root, Obj ** env, Obj ** fn, Obj ** args)
{
  DEFINE3 (params, newenv, body);
  *params = (*fn)->params;
  *newenv = (*fn)->env;
  *newenv = push_env (root, newenv, params, args);
  *body = (*fn)->body;
  return progn (root, newenv, body);
}

// Apply fn with args.
Obj *
apply (void *root, Obj ** env, Obj ** fn, Obj ** args)
{
  if (!is_list (*args))
    error ("argument must be a list");
  if ((*fn)->type == TPRIMITIVE)
    return (*fn)->prim_fn (root, env, args);
  if ((*fn)->type == TFUNCTION)
    {
      DEFINE1 (eargs);
      *eargs = eval_list (root, env, args);
      return apply_func (root, env, fn, eargs);
    }
  error ("not supported");
}

// Searches for a variable by symbol. Returns null if not found.
Obj *
find (Obj ** env, Obj * sym)
{
  for (Obj * p = *env; p != Nil; p = p->up)
    {
      for (Obj * cell = p->vars; cell != Nil; cell = cell->cdr)
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
macroexpand (void *root, Obj ** env, Obj ** obj)
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
eval (void *root, Obj ** env, Obj ** obj)
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
      // Self-evaluating objects
      return *obj;
    case TSYMBOL:
      {
        // Variable
        Obj *bind = find (env, *obj);
        if (!bind)
          error ("Undefined symbol: %s", (*obj)->name);
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
prim_quote (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 1)
    error ("Malformed quote");
  return (*list)->car;
}

// (cons expr expr)
Obj *
prim_cons (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 2)
    error ("Malformed cons");
  Obj *cell = eval_list (root, env, list);
  cell->cdr = cell->cdr->car;
  return cell;
}

// (car <cell>)
Obj *
prim_car (void *root, Obj ** env, Obj ** list)
{
  Obj *args = eval_list (root, env, list);
  if (args->car->type != TCELL || args->cdr != Nil)
    error ("Malformed car");
  return args->car->car;
}

// (cdr <cell>)
Obj *
prim_cdr (void *root, Obj ** env, Obj ** list)
{
  Obj *args = eval_list (root, env, list);
  if (args->car->type != TCELL || args->cdr != Nil)
    error ("Malformed cdr");
  return args->car->cdr;
}

// (setq <symbol> expr)
Obj *
prim_setq (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 2 || (*list)->car->type != TSYMBOL)
    error ("Malformed setq");
  DEFINE2 (bind, value);
  *bind = find (env, (*list)->car);
  if (!*bind)
    error ("Unbound variable %s", (*list)->car->name);
  *value = (*list)->cdr->car;
  *value = eval (root, env, value);
  (*bind)->cdr = *value;
  return *value;
}

// (setcar <cell> expr)
Obj *
prim_setcar (void *root, Obj ** env, Obj ** list)
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
prim_while (void *root, Obj ** env, Obj ** list)
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
prim_gensym (void *root, Obj ** env, Obj ** list)
{
  static int count = 0;
  char buf[10];
  snprintf (buf, sizeof (buf), "G__%d", count++);
  return make_symbol (root, buf);
}

// (+ <integer> ...)
Obj *
prim_plus (void *root, Obj ** env, Obj ** list)
{
  int sum = 0;
  for (Obj * args = eval_list (root, env, list); args != Nil;
       args = args->cdr)
    {
      if (args->car->type != TINT)
        error ("+ takes only numbers");
      sum += args->car->lvalue;
    }
  return make_int (root, sum);
}

// (- <integer> ...)
Obj *
prim_minus (void *root, Obj ** env, Obj ** list)
{
  Obj *args = eval_list (root, env, list);
  for (Obj * p = args; p != Nil; p = p->cdr)
    if (p->car->type != TINT)
      error ("- takes only numbers");
  if (args->cdr == Nil)
    return make_int (root, -args->car->lvalue);
  long r = args->car->lvalue;
  for (Obj * p = args->cdr; p != Nil; p = p->cdr)
    r -= p->car->lvalue;
  return make_int (root, r);
}

// (< <integer> <integer>)
Obj *
prim_lt (void *root, Obj ** env, Obj ** list)
{
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("malformed <");
  Obj *x = args->car;
  Obj *y = args->cdr->car;
  if (x->type != TINT || y->type != TINT)
    error ("< takes only numbers");
  return x->lvalue < y->lvalue ? True : Nil;
}

Obj *
handle_function (void *root, Obj ** env, Obj ** list, int type)
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
prim_lambda (void *root, Obj ** env, Obj ** list)
{
  return handle_function (root, env, list, TFUNCTION);
}

Obj *
handle_defun (void *root, Obj ** env, Obj ** list, int type)
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
prim_defun (void *root, Obj ** env, Obj ** list)
{
  return handle_defun (root, env, list, TFUNCTION);
}

// (define <symbol> expr)
Obj *
prim_define (void *root, Obj ** env, Obj ** list)
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
prim_defmacro (void *root, Obj ** env, Obj ** list)
{
  return handle_defun (root, env, list, TMACRO);
}

// (macroexpand expr)
Obj *
prim_macroexpand (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 1)
    error ("Malformed macroexpand");
  DEFINE1 (body);
  *body = (*list)->car;
  return macroexpand (root, env, body);
}

// (println expr)
Obj *
prim_println (void *root, Obj ** env, Obj ** list)
{
  DEFINE1 (tmp);
  *tmp = (*list)->car;
  print (eval (root, env, tmp));
  printf ("\n");
  return Nil;
}

// (if expr expr expr ...)
Obj *
prim_if (void *root, Obj ** env, Obj ** list)
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

// (= <integer> <integer>)
Obj *
prim_num_eq (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 2)
    error ("Malformed =");
  Obj *values = eval_list (root, env, list);
  Obj *x = values->car;
  Obj *y = values->cdr->car;
  if (x->type != TINT || y->type != TINT)
    error ("= only takes numbers");
  return x->lvalue == y->lvalue ? True : Nil;
}

// (eq expr expr)
Obj *
prim_eq (void *root, Obj ** env, Obj ** list)
{
  if (length (*list) != 2)
    error ("Malformed eq");
  Obj *values = eval_list (root, env, list);
  return values->car == values->cdr->car ? True : Nil;
}

void
add_primitive (void *root, Obj ** env, char *name, Primitive * fn)
{
  DEFINE2 (sym, prim);
  *sym = intern (root, name);
  *prim = make_primitive (root, fn, name);
  add_variable (root, env, sym, prim);
}

void
define_constants (void *root, Obj ** env)
{
  DEFINE1 (sym);
  *sym = intern (root, "t");
  add_variable (root, env, sym, &True);
}

void
define_primitives (void *root, Obj ** env)
{
  add_primitive (root, env, "quote", prim_quote);
  add_primitive (root, env, "cons", prim_cons);
  add_primitive (root, env, "car", prim_car);
  add_primitive (root, env, "cdr", prim_cdr);
  add_primitive (root, env, "setq", prim_setq);
  add_primitive (root, env, "setcar", prim_setcar);
  add_primitive (root, env, "while", prim_while);
  add_primitive (root, env, "gensym", prim_gensym);
  add_primitive (root, env, "+", prim_plus);
  add_primitive (root, env, "-", prim_minus);
  add_primitive (root, env, "<", prim_lt);
  add_primitive (root, env, "define", prim_define);
  add_primitive (root, env, "defun", prim_defun);
  add_primitive (root, env, "defmacro", prim_defmacro);
  add_primitive (root, env, "macroexpand", prim_macroexpand);
  add_primitive (root, env, "lambda", prim_lambda);
  add_primitive (root, env, "if", prim_if);
  add_primitive (root, env, "=", prim_num_eq);
  add_primitive (root, env, "eq", prim_eq);
  add_primitive (root, env, "println", prim_println);
}

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
  if (argc == 2 && !strcmp (argv[1], "--version"))
    {
      printf
        ("%s git %s built on %s at %s (see github.com/btarynk/bismon/ ....)\n",
         argv[0], BISMON_GIT, __DATE__, __TIME__);
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
  DEFINE2 (env, expr);
  *env = make_env (root, &Nil, &Nil);
  define_constants (root, env);
  define_primitives (root, env);

  // The main loop
  for (;;)
    {
      *expr = fread_expr (stdin, root);
      if (!*expr)
        return 0;
      if (*expr == Cparen)
        error ("Stray close parenthesis");
      if (*expr == Dot)
        error ("Stray dot");
      print (eval (root, env, expr));
      printf ("\n");
    }
}

/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/
