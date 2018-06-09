<!-- file dependencies/README-dependencies.md -->

# `bismon` dependencies #

This `dependencies/` subdirectory contains dependencies, installed
with [`git submodule`](https://git-scm.com/book/en/v2/Git-Tools-Submodules), related to `bismon`.

* `libonion` is David Moreno'
  [Onion](http://www.coralbits.com/libonion/) library for HTTP
  service.

* `libbacktrace` is Ian Lance Taylor's [libbacktrace](https://github.com/ianlancetaylor/libbacktrace) - also used inside [GCC](http://gcc.gnu.org/) - to produce symbolic backtraces (using the DWARF debug format).


But [GTK3](http://gtk.org/) is soon an obsolete dependency so is not mentioned here (and is too big...).
