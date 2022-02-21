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

#include <glib.h>


extern void error (char *fmt, ...) __attribute__((noreturn));

//======================================================================
// Lisp objects
//======================================================================

// The Lisp object type
enum
{
  // Regular objects visible from the user
  TINT = 1,
  TDOUBLE,
  TCELL,
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

// Constants
extern Obj *True;
extern Obj *Nil;
extern Obj *Dot;
extern Obj *Cparen;

// The list containing all symbols. Such data structure is traditionally called the "obarray", but I
// avoid using it as a variable name as this is not an array but a list.
extern Obj *Symbols;

// Allocates memory block. This may start GC if we don't have enough memory.
extern Obj *alloc (void *root, int type, size_t size);

// Implements Cheney's copying garbage collection algorithm.
// http://en.wikipedia.org/wiki/Cheney%27s_algorithm
extern void gc (void *root);
extern Obj *forward_for_gc (Obj *);

extern void clear_gtk_json_marks (void *root);
extern void mark_json_ref (void *root, Obj * jsob);
extern void mark_gtk_ref (void *root, Obj * gtkob);
extern void clean_gc_json_gtk (void *root);
extern Obj *prim_scalar_eq (void *root, Obj ** env, Obj ** list);
extern Obj *prim_json_eq (void *root, Obj ** env, Obj ** list);
extern Obj *prim_gtk_eq (void *root, Obj ** env, Obj ** list);

//======================================================================
// Constructors
//======================================================================

extern Obj *make_int (void *root, long ivalue);
extern Obj *make_double (void *root, double dvalue);
extern Obj *cons (void *root, Obj ** car, Obj ** cdr);
extern Obj *make_symbol (void *root, char *name);
extern Obj *make_string (void *root, char *buf);
extern Obj *make_json (void *root, json_t * json);
extern Obj *make_sprintf (void *root, const char *fmt, ...)
  __attribute__((format (printf, 2, 3)));
extern Obj *make_primitive (void *root, Primitive * fn, const char *name);
extern Obj *make_function (void *root, Obj ** env, int type,
                           Obj ** params, Obj ** body);
struct Obj *make_env (void *root, Obj ** vars, Obj ** up);

// Returns ((x . y) . a)
extern Obj *acons (void *root, Obj ** x, Obj ** y, Obj ** a);


//// reader
extern Obj *fread_expr (FILE * fil, void *root);


// Evaluates all the list elements and returns their return values as a new list.
extern Obj *eval_list (void *root, Obj ** env, Obj ** list);

/// printer
extern void print (Obj * obj);
extern void file_print (FILE * fil, Obj * obj, unsigned depth);
extern void file_json_print (FILE * fil, Obj * obj, unsigned depth);
extern void file_gtk_print (FILE * fil, Obj * obj, unsigned depth);
#endif /*MINILISPBISMON_HEADER */
