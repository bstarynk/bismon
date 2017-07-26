<!-- file bootsyntax.md -->

# Lexical conventions #

* See types `parslexkind_enBM`, `parstoken_stBM` in the ` types_BM.h`
  source file.

* Comments: either starting with `//` till eol, or starting and ending
  with `|`

* A lot of lexical conventions are inspired by C (however `/*`
  comments `*/` are **not supported** !)
  
* A name is nearly like a C identifier, but double underscores or
  initial or final underscores are forbidden. So `foo`, `foo_1`,
  `barFoo_x` are good names, but `__`, `_a`, `foo__2` are not. A name denotes some named object at time of parsing.
  
* A C-identifier is a name in the above sense which does not yet name
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
  the special `+INF`, `-INF`, `+NAN` not followed by a letter.



