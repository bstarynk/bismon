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
  `barFoo_x` are good names, but `__`, `_a`, `foo__2` are not. A name denotes some named object at time of parsing.
  
* A C-name is a name in the above sense which does not yet name
  some existing object.

* An object-id or id starts with an underscore then digit, such as
  `_1jJjA6LcXiX_1V4ZcXlje09` or `2QeF5dreQwf_51c3fAJEYqJ`. All object
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

Each load file is named `store[0-9]+.bismon` where the number is small
and unique in the directory. Files are loaded by ascending positive
numbers (e.g. `store1.bismon` first).

Each load file defines a collection of objects. Each object definition
starts with a line beginning with `!*` then immediately the
object-id. After that start-marker we can have other lines.
