<!-- file jscompilnotes.md -->

# internal notes about compiling to Javascript #

Some stuff from `bismon` need to be compiled to Javascript. This is
happening in `bismon` code, in several routines of `first_misc_module`

We try to keep the same *control structure* as in `bismon`-generated C
code, but since Javascript is not typed, we don't care much about
types.

So we compile some jsmodule, instance of `jsmodule_object`. Its components can be

* topvariable definitions (e.g. _4ZTO4xbDxN5_8kRccLMSfOE), of class
  `jscript_topvardef_object` with field `variable` ; if that field is
  some object `_7b4FLPaZXgr_6vcmS00EruO` we emit the Javascript
  declaration `var jsvar_7b4FLPaZXgr_6vcmS00EruO;` (notice that the
  emitted name is related to the variable, not its definition).

* topfunction definitions (e.g. _1dGYpQHFvMA_00Js64eAxrZ), of class
  `jscript_topfunction_object` with fields `arguments`, `body`,
  `locals`. We emit a Javascript function declaration `function
  jtfun_1dGYpQHFvMA_00Js64eAxrZ`

