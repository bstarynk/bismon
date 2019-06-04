<!-- file dependencies/README-dependencies.md -->

# `bismon` dependencies #

This `dependencies/` subdirectory contains dependencies, installed
with [`git submodule`](https://git-scm.com/book/en/v2/Git-Tools-Submodules), related to `bismon`.

* `libonion` is David Moreno'
  [Onion](http://www.coralbits.com/libonion/) library for HTTP
  service.

* `libbacktrace` is Ian Lance Taylor's [libbacktrace](https://github.com/ianlancetaylor/libbacktrace) - also used inside [GCC](http://gcc.gnu.org/) - to produce symbolic backtraces (using the DWARF debug format).

The [LaTeX system](http://latex-project.org/) is needed (with
[HeVeA](http://hevea.inria.fr/) and [inkscape](https://inkscape.org/)
and many other things, see the `bismon/README.md` file for details) to
generate documentation (notably as a PDF file under your `$HOME/tmp/`
directory) using `make doc`

But [GTK3](http://gtk.org/) is soon an obsolete dependency so is not mentioned here (and is too big...).


## read also the `bismon/README.md` please