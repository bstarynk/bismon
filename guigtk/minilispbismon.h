// file minilispbismon.h
// SPDX-License-Identifier: LGPL-3.0-or-later
#ifndef MINILISPBISMON_HEADER
#define MINILISPBISMON_HEADER 1

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

__attribute ((noreturn))
     void error (char *fmt, ...);

//======================================================================
// Lisp objects
//======================================================================

// The Lisp object type
     enum
     {
       // Regular objects visible from the user
       TINT = 1,
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

     typedef struct json_t json_t;      /// in file <jansson.h>

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

       // The total size of the object, including "type" field, this field, the contents, and the
       // padding at the end of the object.
       int size;

       // Object values.
       union
       {
         // Int
         int value;
         // Cell
         struct
         {
           struct Obj *car;
           struct Obj *cdr;
         };
         // Symbol
         char name[1];
         // strings
         char cstring[1];
         // JSON reference
         int json_index;
         // GTK reference
         int gtk_index;
         // 
         // Primitive
         struct
         {
           Primitive *prim_fn;
           const char *prim_name;
         };
         // Function or Macro
         struct
         {
           struct Obj *params;
           struct Obj *body;
           struct Obj *env;
         };
         // Environment frame. This is a linked list of association lists
         // containing the mapping from symbols to their value.
         struct
         {
           struct Obj *vars;
           struct Obj *up;
         };
         // Forwarding pointer
         void *moved;
       };
     } Obj;                     // end struct Obj

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




//======================================================================
// Constructors
//======================================================================

     extern Obj *make_int (void *root, int value);
     extern Obj *cons (void *root, Obj ** car, Obj ** cdr);
     extern Obj *make_symbol (void *root, char *name);
     extern Obj *make_string (void *root, char *buf);
     extern Obj *make_sprintf (void *root, const char *fmt, ...)
  __attribute__((format (printf, 2, 3)));
     extern Obj *make_primitive (void *root, Primitive * fn,
                                 const char *name);
     extern Obj *make_function (void *root, Obj ** env, int type,
                                Obj ** params, Obj ** body);
     struct Obj *make_env (void *root, Obj ** vars, Obj ** up);

// Returns ((x . y) . a)
     extern Obj *acons (void *root, Obj ** x, Obj ** y, Obj ** a);


//// reader
     extern Obj *fread_expr (FILE * fil, void *root);

#endif /*MINILISPBISMON_HEADER */
