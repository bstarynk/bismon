<!-- file bootsyntax.md -->

# Lexical conventions #

* See types `parslexkind_enBM`, `parstoken_stBM` in the ` types_BM.h`
  source file.

* Comments: either starting with `//` till eol, or starting and ending
  with `|`

* some lexical conventions are inspired by C (however `/*`
  comments `*/` are **not supported** !)
  
* A name is nearly like a C identifier, but double underscores or
  initial or final underscores are forbidden. So `foo`, `foo_1`,
  `barFoo_x` are good names, but `__`, `_a`, `foo__2` are not.  
  A name denotes some named object at time of parsing.
  
* A C-name is a name in the above sense which does not yet name
  some existing object.

* An object-id or id starts with an underscore then digit, such as
  `_1jJjA6LcXiX_1V4ZcXlje09` or `_2QeF5dreQwf_51c3fAJEYqJ`. All object
  ids have underscores in the same relative place and have the same
  length (24 signs).
  
* The delimiters are listed in `_bm_delim.h` (should appear in UTF8
  ascending order) and include parenthesis, braces, brackets, comma,
  semi-colon, colon, star etc... Some are UTF8, and some others have
  several characters. The *nilid* delimiter `__` (double underscore)
  denotes the nil id.
  
* A floating-point number should have a decimal point, or otherwise be
  the special `+INF`, `-INF`, `+NAN` not followed by a
  letter. However, `1e2` is not valid (no decimal point), you need to
  type `1.e2` or `100.`; and `.2` is also invalid (don't start with a
  digit), it should be `0.2`.

* Strings are made of cords. Most of them have just one cord, like
  `"abc"` or `"some\ttab"` where the `\t` is an escape for the tab. A
  raw cord starts with a `/"` followed by at most 16 letter-or-digits
  run followed by an open parenthesis, and ending with a closing parenthesis
  followed by the same run then `"/`  and may contain unescaped
  control characters. So `/"XY(no\ttab)XY"/` is a raw cord with run of
  `XY` and denotes the same string as `"no\\ttab"` and does not
  contain any tab (but has a backslash). A cord may be *immediately*
  followed by `&` or by `+` (and then some optional spaces or
  comments) and then by some other cord, thus making a literal string
  of several cords. If a cord is followed by `&` the next cord is
  immediately concatenated. If it is followed by `+` the next cord is
  concatenated with a newline in between. So `"ab\ncd"` and `"ab"+
  |some comment| "cd"` and `"ab"&"\ncd"` all represents the *same
  string* of five characters, with a newline at its center.

## boot syntax

Each load file is named `store[0-9]+.bmon` where the number is small
and unique in the directory. Files are loaded by ascending positive
numbers (e.g. `store1.bmon` first), the number being the space of
objects defined in them (so `store1.bmon` is for predefined objects,
`store2.bmon` for global objects).

Each load file requires some modules -perhaps none- then defines a
collection of objects. A module requirement line starts with `!^`
followed by the module's id.  Each object definition starts with a
line beginning with `!(` then immediately the object-id. After that
start-marker we can have other lines. They are ended by the
end-marker, i.e. `!)` followed by the same object-id or the nil id.

The possible boot directives inside an object definition include
object complemented:

* `!:` *attr-object* *attr-value* to add an attribute and its value

* `!-` *attr-object* to remove an attribute

* `!&` *comp-value* to append a component

* `!#` *size* to reserve space for components

* `!@` *mtime*  to set the modification time

* `!$` *classobj* to set the class

* `!~` *name* `(~` .... modification .... `~)` for some other modification

* `!>` *selector-object* `(` ... `)` to send a message (for side effects)

The `class`  modification is built-in:

*class-modification* = *superclass-obj* ( `~:` *selector-obj* *method-closure* ) *


The `name` modification is built-in:

*name-modification* = *namedobj-or-cname*

The `value` modification is built-in:

*value-modification* = *value*


Values can be :

* Scalars, i.e. objects (by name or by id), integers, strings, nil

* Sets (of objects) are between braces `{` elements ... `}`.  A set
can also be a name matching set, e.g. `~: *` for the set of all named
objects, `~: foo` for the set of named objects starting or prefixed
with with `foo`, `~: "a*b*"` for the set of named objects
*fnmatch*-ing (à la shell globbing) the `a*b*` glob pattern (so
starting with `a` and later containing `b`); if the string starts with
`~` the matching is case-insensitive, so `~: "~ab*"` is the set of
names starting with upper or lower case `ab`.

* Tuples (of objects) are between brackets `[` components ... `]`

* Nodes start with a `*` then the object connective then a parenthesis
  with sons
  
* Closures start with a `%` then the object connective then a parenthesis
  with sons

## GUI command syntax

We display (in the browser text view widget) a set of objects (ordered
by name or else by id) and a sequence of named non-null values
(ordered by name). There is at most one focused object.

`$a` denotes the value named by `a`. `$:a` denote the object named by
`a` (or nil if `$a` is a non-object value).

Two semicolons `;;` stop the command parsing.

`?*` *object* displays and sets the focus on the given *object*

`?.` *object* or just *object* displays the given *object*

`?-` *object* hides that object

`?$` *name* *value* binds the name to the value, e.g. after `?$x {a}` the `x` name (refered by `$x`) is bound to the singleton set `{a}` and displayed

`?$-` *name* hides and unbinds the given *name*

`?#` *depth* changes the default browsed depth (at start `?# 7`)

`$(` *value* `)` displays the given *value* and bind it to `$result`

An object complement (i.e. `!*`, `!-`, `!&`, `!@`, `!$`, `!~`, `!>`
...) apply to the focused object.

`!^ 2` moves the focus object to space 2 (global) and is the same as
`!^ *`.  `!^ :` moves the focus object to space 3 (userA), like does
`!^ 3`; `!^ ;` moves it to space 4 (userB) like `!^ 4`. `!^ %` moves
it to space 0 (transient) like `!^ 0`. `!^ !$` makes it predefined
(space 1) like `!^ 1`

`$% xx` binds the focus object to named value `$xx` 


An object (in the command widget) can also be `$[` ... `]`.  Inside
the braces, `*` *name* creates a named UserE object, and `!*` *name*
creates a named global object; `:` creates a transient anonymous
object, `~` creates a global anonymous object, `%` creates a UserE
anonymous object. Then object complements could follow.

A value (in the command) can also be `$(` ... `)`. Inside the
parenthesis, `!>` *object-selector* `(` ...  `)` sends a message for
its result. `(` ... `)` can be used for function application. `!.`
*obattr* is fetching some attribute. `!@` *index* is retrieving a
component of given index. `$%` *name* is showing and binding a name.
