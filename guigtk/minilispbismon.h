// file minilispbismon.h
// SPDX-License-Identifier: LGPL-3.0-or-later
#ifndef MINILISPBISMON_HEADER
#define MINILISPBISMON_HEADER 1

// adapted from github.com/rui314/minilisp/ (commit c83b57126759ef3)
// for the BISMON project

#define _GNU_SOURCE 1

#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <execinfo.h>

#include <glib.h>

extern char *program_name;
extern char *scriptfile;
extern pthread_t main_pthread;

extern void error (char *fmt, ...) __attribute__((noreturn));



//======================================================================
// Lisp objects
//======================================================================

// The Lisp object type
enum objtype_en
{
  // Regular objects visible from the user
  TINT = 1,
  TDOUBLE,
  TCELL,
  TVECTOR,
  TSYMBOL,
  TSTRING,
  TJSONREF,
  TGTKREF,
  TPRIMITIVE,
  TFUNCTION,
  TMACRO,
  TENV,
  // The marker that indicates the object has been moved to other location by GC. The new location
  // can be found at the forwarding pointer. Only the functions to do garbage collection set and
  // handle the object of this type. Other functions will never see the object of this type.
  TMOVED,
  // Const objects. They are statically allocated and will never be managed by GC.
  TTRUE,
  TNIL,
  TDOT,
  TCPAREN,
};

typedef struct json_t json_t;   /// in file <jansson.h>

// Typedef for the primitive function
struct Obj;
typedef struct Obj *Primitive (void *root, struct Obj **env,
                               struct Obj **args);

// The object type
typedef struct Obj
{
  // The first word of the object represents the type of the object. Any code that handles object
  // needs to check its type first, then access the following union members.
  int type;

  // The total size in bytes of the object, including "type" field,
  // this field, the contents, and the padding at the end of the
  // object.
  int size;

  // Object values.
  union
  {
    // Int °TINT
    long lvalue;
    // Double °TDOUBLE
    double dvalue;
    // Cons Cell °TCELL
    struct
    {
      struct Obj *car;
      struct Obj *cdr;
    };
    // vector °TVECTOR
    struct
    {
      unsigned vec_len;
      unsigned vec_flavor;
      struct Obj *vec_comparr[];
    };
    // Symbol °TSYMB
    char sy_name[1];
    // strings °TSTRING
    struct
    {
      unsigned utf8_len;        // number of UTF8 characters (not bytes)
      char utf8_cstring[1];
    };
    // JSON reference for °TJSONREF
    int json_index;
    // GTK reference for °TGTKREF
    int gtk_index;
    // 
    // Primitive °TPRIMITIVE
    struct
    {
      Primitive *prim_fn;
      const char *prim_name;
    };
    // Function °TFUNCTION or Macro °TMACRO
    struct
    {
      struct Obj *params;
      struct Obj *body;
      struct Obj *env;
      long fun_number;          /* unique number, to ease printing */
    };
    // Environment frame °TENV. This is a linked list of association lists
    // containing the mapping from symbols to their value.
    struct
    {
      struct Obj *vars;
      struct Obj *up;
    };
    // Forwarding pointer, internal to GC, see °°TMOVED
    void *moved;
  };
} Obj;                          // end struct Obj


#define MAX_VECTOR_LEN (128*1024)

extern bool recursive_equal (Obj *x, Obj *y, unsigned depth);

enum json_magic_en
{
  JSONMAG_true = -1,
  JSONMAG_false = -2,
  JSONMAG_null = -3
};

// Constants
extern Obj *True;
extern Obj *Nil;
extern Obj *Dot;
extern Obj *Cparen;
extern Obj *Jsonv_True;
extern Obj *Jsonv_False;
extern Obj *Jsonv_Null;



// The size of the heap in byte
#define MEMORY_SIZE (16*1024*1024)

// The pointer pointing to the beginning of the current heap
extern void *memory;

// The pointer pointing to the beginning of the old heap
extern void *from_space;

// The number of bytes allocated from the heap
extern size_t mem_nused;

// Flags to debug GC
extern bool gc_running;
extern bool debug_gc;
extern bool always_gc;
extern bool verbose_ilisp;

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

#define MAX_RECURSIVE_DEPTH 64

// The list containing all symbols. Such data structure is traditionally called the "obarray", but I
// avoid using it as a variable name as this is not an array but a list.
extern Obj *Symbols;

// Allocates memory block. This may start GC if we don't have enough memory.
extern Obj *alloc (void *root, int type, size_t size);

/// some function are special casing small size less than...
#define SMALL_SIZE 64

// Implements Cheney's copying garbage collection algorithm.
// http://en.wikipedia.org/wiki/Cheney%27s_algorithm
extern void gc (void *root);
extern Obj *forward_for_gc (Obj *);

extern void add_primitive (void *root, Obj **env, char *name, Primitive * fn);
extern void define_primitives (void *root, Obj **env);
extern void define_json_primitives (void *root, Obj **env);
extern void define_gtk_primitives (void *root, Obj **env);

extern void clear_json_marks (void *root);
extern void clear_gtk_marks (void *root);
extern void mark_json_ref (void *root, Obj *jsob);
extern void mark_gtk_ref (void *root, Obj *gtkob);
extern void clean_gc_json (void *root);
extern void clean_gc_gtk (void *root);
extern Obj *prim_scalar_eq (void *root, Obj **env, Obj **list);
extern Obj *prim_json_eq (void *root, Obj **env, Obj **list);
extern Obj *prim_gtk_eq (void *root, Obj **env, Obj **list);

//======================================================================
// Constructors
//======================================================================

extern Obj *make_int (void *root, long ivalue);
extern Obj *make_double (void *root, double dvalue);
extern Obj *cons (void *root, Obj **car, Obj **cdr);
extern Obj *make_symbol (void *root, const char *name);
extern Obj *make_string (void *root, const char *buf);

// May create a new symbol. If there's a symbol with the same name, it will not create a new symbol
// but return the existing one.
extern Obj *intern (void *root, char *name);

// if doincref is set, jansson's function json_incref is called.
extern Obj *make_json (void *root, json_t *json, bool doincref);
#define KEEP_REFCNT_JANSSON false
#define INCR_REFCNT_JANSSON true
extern Obj *make_sprintf (void *root, const char *fmt, ...)
  __attribute__((format (printf, 2, 3)));
extern Obj *make_primitive (void *root, Primitive * fn, const char *name);
extern Obj *make_function (void *root, Obj **env, int type,
                           Obj **params, Obj **body);
struct Obj *make_env (void *root, Obj **vars, Obj **up);

// Returns ((x . y) . a)
extern Obj *acons (void *root, Obj **x, Obj **y, Obj **a);


//// reader
extern Obj *fread_expr (FILE * fil, void *root);
//// for JSON notation; example #json { "a" : 1, "b" : [true,false,null]}
extern Obj *fread_json (FILE * fil, void *root);


// Evaluates all the list elements and returns their return values as a new list.
extern Obj *eval_list (void *root, Obj **env, Obj **list);

// Evaluate inside a GTK callback, using env & list from prim_gtk_loop
extern Obj *eval_in_gtk_callback (Obj **obj);

// Evaluates all the list elements and returns their return values as a new list, in  GTK callback
extern Obj *eval_list_in_gtk_callback (Obj **env, Obj **list);

// Returns the length of the given list. -1 if it's not a proper list.
extern int length (Obj *list);

/// if jsob is a TJSON, get it; otherwise NULL
extern json_t *get_json (Obj *jsob);

/// this is in <gtk/gtk.h> which we want to avoid including
typedef struct _GtkWidget GtkWidget;
/// if ob is a GTK widget get it, else NULL
extern GtkWidget *get_gtk_widget (Obj *ob);


/// this is in <gobject.h>
typedef struct _GObject GObject;
/// if ob is a GObject, get it
extern GObject *get_g_object (Obj *);


/// printer
extern void print_val (Obj *obj);
extern void print_val_nl (Obj *obj);
extern void file_print (FILE * fil, Obj *obj, unsigned depth);
extern void file_json_print (FILE * fil, Obj *obj, unsigned depth);
extern void file_gtk_print (FILE * fil, Obj *obj, unsigned depth);
extern bool recursive_equal (Obj *x, Obj *y, unsigned depth);

/// gives the JSON value inside some Obj, or else NULL; inverse of make_json
extern json_t *json_in_obj (Obj *obj);



/// initialize support got JSON references
extern void initialize_json (void);


/// initialize support for GTK
extern void initialize_gtk (int *pargc, char ***pargv);


/// load a file, evaluating each s-expr, and return -1 on error, and
/// the number of evaluated expressions otherwise. If skiphead is
/// true, ignore first lines up to a line like ;;;+++
#define SKIP_HEAD_LOADED_FILE true
#define LOAD_FULL_LOADED_FILE false
extern int load_file (const char *filnam, bool skiphead, void *root,
                      Obj **env);

//// two unsafe and non-reentrant utilities to print file names; usable
//// with error(...)
extern const char *static1_file_name (FILE * f);
extern const char *static2_file_name (FILE * f);

//// show backtrace of MAX_RECURSIVE_DEPTH  calls on stderr
extern void show_backtrace_stderr (void);

#endif /*MINILISPBISMON_HEADER */
///// end of file bismon/gtkgui/minilispbismon.h
