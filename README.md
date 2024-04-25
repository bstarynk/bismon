<!-- file README.md -->

# Overview and philosophy #

`bismon` (this is a *temporary* name) is a **persistent monitor**
which (in the future) would interact with the
[GCC](http://gcc.gnu.org/) compiler thru plugins.  It is (or will
become) somehow a successor to my old [GCC
MELT](http://starynkevitch.net/Basile/gcc-melt/) project; the
medium-term goal is also [static program source code
analysis](https://en.wikipedia.org/wiki/Static_program_analysis) with
the help of [GCC](http://gcc.gnu.org/). The source code repository
(GPLv3+ licensed) is on https://github.com/bstarynk/bismon ..  My
([Basile Starynkevitch](http://starynkevitch.net/Basile/), employed at
[CEA, LIST](http://www-list.cea.fr/) in France) work on `bismon` is
partly funded (from start of 2018 to end of 2020) by the European
Union, Horizon H2020 programme, [CHARIOT](http://chariotproject.eu/)
project, under Grant Agreement No 780075. Within CHARIOT I will focus
on analysis of some kind of
[IoT](https://en.wikipedia.org/wiki/Internet_of_things) software coded
in C or C++ and (cross-) compiled by [GCC](http://gcc.gnu.org/) on
some Linux desktop. In 2019 - 2021 the development of `bismon` is also
partly funded by the [DECODER](http://decoder-project.eu/) H2020
project, under Grant Agreement 824231 (related to its *Persistent
Knowledge Monitor* WP1).

Currently (start of 2021) `bismon` still in **beta**-stage, and
it is *free software* under
[GPLv3+](https://www.gnu.org/licenses/gpl-3.0.en.html) license. It is
intended for a Linux x86-64 desktop developer's workstation (won't
work on Windows or MacOSX or Android).

Some *still incomplete* documentation (as a technical report
`doc/bismon-doc.pdf` in PDF) can be generated (with `make`
then `make doc`; that command requires you to have a writable
`$HOME/tmp/` directory). An early (unofficial) draft of that report
might be available on
http://starynkevitch.net/Basile/bismon-doc.pdf


### Potential future usages

While *Bismon* is currently funded by H2020 projects with
static-analysis goals, please **notice that *Bismon* might later**
-when more mature, after 2024- **be probably usable as a** somehow
generic ***framework*, with a *lot of additional work*** (years, not
months), **for many other purposes** (the most significant limit being
your imagination, and the power of your computer), including perhaps
even some kind of
[AI](https://en.wikipedia.org/wiki/Artificial_intelligence) system
(read J.Pitrat's book *Artificial Beings: the conscious of a conscious
machine*, ISBN: 978-1848211018), sophisticated
[desktop](https://en.wikipedia.org/wiki/Desktop_environment)-like
graphical environments, many interactive web-based [collaborative
software](https://en.wikipedia.org/wiki/Collaborative_software) tools
concurrently used by some team, or [object
database](https://en.wikipedia.org/wiki/Object_database)s applications
or relevant problems. Since *Bismon* is GPLv3+ licensed, any future
software using it should, [IMHO](https://en.wiktionary.org/wiki/IMHO),
practically also be GPLv3+ (but other licensing schemes could be
possible, contact me on `basile.starynkevitch@cea.fr` for more;
however, [IANAL](https://en.wiktionary.org/wiki/IANAL) ...)


### Related readings

[Joint Strike Fighter Air Vehicule C++ coding standards]
(https://www.stroustrup.com/JSF-AV-rules.pdf)

[Zero-overhead deterministic exceptions: Throwing values]
(http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0709r4.pdf)

[C++ standardization, papers 2021]
(http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/)

## Approach ##

*Develop some kind of* high-level (more expressive, more declarative)
[**domain-specific
language**](https://en.wikipedia.org/wiki/Domain-specific_language) to
facilitate [static program source code
analysis](https://en.wikipedia.org/wiki/Static_program_analysis) above
[GCC](http://gcc.gnu.org/) and *generate* [GCC plugins](https://gcc.gnu.org/onlinedocs/gccint/Plugins.html) for it, so same motivations as [GCC
MELT](http://starynkevitch.net/Basile/gcc-melt/) (and more broadly
related -in motivations- to [Coccinnelle](http://coccinelle.lip6.fr),
[Frama-C](http://frama-c.com), [Rascal](https://www.rascal-mpl.org/),
[CrossMiner](https://www.crossminer.org/), [Clang
analyser](http://clang-analyzer.llvm.org/), [Clasp](https://github.com/clasp-developers/clasp) etc...).


Important features and goals of that domain-specific language and its implementation include:

* [orthogonal persistence](https://en.wikipedia.org/wiki/Persistence_%28computer_science%29);
this is a *major* feature (useful for *whole program* static source code
analysis of an analyzed program made of *several* translation units, each compiled independently)
which was not realistically addable to [GCC
MELT](http://starynkevitch.net/Basile/gcc-melt/) so requires a
complete redesign. The `bismon` process is expected to be relatively
long-lived -server like- and retains most of its data from one run to
the next (in `store*.bmon` textual files). In the future the `bismon`
process will communicate with `gcc` or `g++` (cross-)compilation
processes (using some [GCC
plugin](https://gcc.gnu.org/onlinedocs/gccint/Plugins.html), to be
generated by `bismon` itself)

* [dynamic typing](https://en.wikipedia.org/wiki/Type_system#DYNAMIC) like in Python, Scheme, Ruby, JavaScript, ... (and somehow MELT).

*
  [multi-threaded](https://en.wikipedia.org/wiki/Thread_%28computing%29)
  but without any
  [GIL](https://en.wikipedia.org/wiki/Global_interpreter_lock). A
  small thread pool of worker threads is repeatedly and concurrently
  fetching tasklets from a global agenda. Each tasklet runs quickly
  (milliseconds) in some worker thread and can update that agenda
  (e.g. by adding itself to be continued).

* [reflexive](https://en.wikipedia.org/wiki/Reflection_%28computer_programming%29)

* [homoiconic](https://en.wikipedia.org/wiki/Homoiconicity)

* precisely [garbage collected](https://en.wikipedia.org/wiki/Garbage_collection_%28computer_science%29)

* [declarative](https://en.wikipedia.org/wiki/Declarative_programming), with good pattern matching and rules formalisms

* [bootstrapped](https://en.wikipedia.org/wiki/Bootstrapping_%28compilers%29),
  and [compiled to C](https://softwareengineering.stackexchange.com/a/257873/40065),
  perhaps some parts using [GCCJIT](https://gcc.gnu.org/onlinedocs/jit/).

* so [metaprogrammed](https://en.wikipedia.org/wiki/Metaprogramming)

* generating GCC plugins (in C++) which would interact with `bismon` by some RPC mechanism

Notice that the syntax and semantics (still undocumented) of `bismon` is *work-in-progress* and subject to change incompatibly.

When `bismon` will be completed to point of being usable, it would be
typically used by a small team of developers working together on some
(common) software project coded mostly in C or C++ (and preferably a
free software project).

# build instructions #

Most of `bismon` is in C99 or C11 (including an increasing amount of
*generated* C code under `modules/`), but some few hand-written code
is in C++14 (notably `misc_BM.cc` and the `BM_makeconst.cc`
metaprogram generating C headers).


**On Linux/x86-64** (e.g. Debian/Unstable or
[Buster](https://www.debian.org/News/2019/20190706) or recent Ubuntu
18 or 19) ***only*** (Without additional patches or work, *Bismon*
won't work on 32 bits machines!) :

## prerequisites ##


You should be able to compile many [open
source](http://opensource.org/) software package for their source
code. You should have a recent
[GNU/Linux](https://www.gnu.org/gnu/why-gnu-linux.en.html) system with
[root](https://geek-university.com/linux/root-account/) acesss,
preferably 32Gigabytes or more of RAM, some
[x86-64](https://en.wikipedia.org/wiki/X86-64) processor with at least
4 [cores](https://en.wikipedia.org/wiki/Multi-core_processor), and at
least 250Gbytes of free disk space. You are expected to be fluent with
the Linux [command-line
interface](https://en.wikipedia.org/wiki/Command-line_interface), and
[unix shells](https://en.wikipedia.org/wiki/Unix_shell) such as [GNU
bash](https://www.gnu.org/software/bash/) or
[zsh](http://zsh.org/). You should be able and allowed to compile [GCC
10](https://gcc.gnu.org/gcc-10/) or preferably even 
[GCC 11](https://gcc.gnu.org/gcc-11/) from its 
[source code](https://en.wikipedia.org/wiki/Source_code) and familiar with
source code editors such as [GNU
emacs](https://www.gnu.org/software/emacs/), [vim](https://vim.org/),
[geany](https://www.geany.org/) etc... You enjoyed reading
[SICP](https://mitpress.mit.edu/sites/default/files/sicp/index.html).

See also the [dependencies](dependencies/) subdirectory and its
[README-dependencies](dependencies//README-dependencies.md) - perhaps
not updated.

* recent [GCC](http://gcc.gnu.org/) (so [GCC 10](https://gcc.gnu.org/gcc-10/)
or *preferably* [GCC 11](https://gcc.gnu.org/gcc-11/) ...), with C and C++ and JIT support
and plugins enabled (check with `gcc -v`; if your system `gcc` and
`g++` lack support for plugins and
[libgccjit](https://gcc.gnu.org/onlinedocs/jit/), you should build and
[install](https://gcc.gnu.org/install/) a recent GCC release from its
source code, and configure it to provide them.). **An old GCC**
(e.g. version 9 or earlier) **cannot be used.**

	* If you compile GCC from its source code, consider using a
      configuration command inspired by :
      `'/usr/src/Lang/gcc-11.1.0/configure' '-v' '--prefix=/usr/local' \
      '--with-gcc-major-version-only' '--program-suffix=-11' \
      '--enable-shared' '--enable-linker-build-id' '--enable-nls' \
      '--enable-bootstrap' '--enable-clocale=gnu' \
      '--enable-libstdcxx-debug' '--enable-libstdcxx-time=yes' \
      '--with-default-libstdcxx-abi=new' '--enable-gnu-unique-object' \
      '--disable-vtable-verify' '--enable-plugin' \
      '--enable-default-pie' '--with-system-zlib' \
      '--enable-libphobos-checking=release' \
      '--with-target-system-zlib=auto' '--enable-objc-gc=auto' \
      '--enable-multiarch' '--disable-werror' '--with-arch-32=i686' \
      '--with-abi=m64' '--with-multilib-list=m32,m64,mx32' \
      '--enable-multilib' '--with-tune=native' \ 
      'CFLAGS=-O2 -g' 'CXXFLAGS=-O2 -g' '--enable-host-shared'
      '--enable-languages=c,c++,d,go,jit,lto'` ....

* a recent [Python 3](http://python.org/) with
  [pip](https://pypi.org/project/pip/) installed.


* the documentation needs a `/usr/bin/mipsel-linux-gnu-gcc-8`
  cross-compiler provided by `gcc-8-mipsel-linux-gnu` Debian
  package. Beware, that package conflicts with `gcc-multilib*`
  packages on Debian.


* [ninja](http://ninja-build.org/) builder, version 1.8 or newer is
  needed (and is started by `make`). Don't use an older one (check with
  `ninja --version`; if that does not work, your `ninja` is too old).

* a recent [Guile](https://www.gnu.org/software/guile/) interpreter is
  required, version 2 or better (preferably Guile 2.2). I don't know
  and strongly dislike [Python](http://python.org/) and the *Guile*
  interpreter is [GNU](https://www.gnu.org/software/software.html),
  [LGPLv3+](http://www.gnu.org/licenses/lgpl.html), and much more
  [familiar to
  me](http://starynkevitch.net/Basile/guile-tutorial-1.html). Also,
  concepts from
  [Lisp](https://en.wikipedia.org/wiki/Lisp_(programming_language))
  dialects such as [Scheme](https://schemers.org/) (the language
  implemented by *Guile*) are strongly relevant to [understand
  *Bismon*](http://starynkevitch.net/Basile/bismon-doc.pdf),
  where *Guile* is used to generate the `build.ninja` script used by
  the [ninja](http://ninja-build.org/) builder.

* a recent Guile-enhanced `mailutils`, that is the Debian
  `mailutils-guile` providing the `/usr/bin/guimb`  executable.

* [Glib](https://developer.gnome.org/glib/stable/) 2.58 or better
  (which is also needed to GTK above), because some low level routines,
  notably [UTF-8](https://utf8everywhere.org/) related, are needed.

* [Jansson](http://www.digip.org/jansson/) 2.12 or better is needed
  for JSON (used in relation to WebSockets).

* [libonion](http://www.coralbits.com/libonion) was needed for the web
  interface, but removed in June, 27, 2022, git commit `a943cf687c748` or
  tag `no-more-ibonion-tag` (with typo: missing `l`). Before that
  commit look for `BISMON_LIBONION` preprocessor flag.

* [GNU make](https://www.gnu.org/software/make/) 4 or better

* [ccache](https://ccache.samba.org/) is used to avoid useless
  recompilations. If you don't have it, you'll need to edit our
  `Makefile` for compilation of generated modules.

* [libbacktrace](https://github.com/ianlancetaylor/libbacktrace) - it is sometimes part of your system *GCC*, but you'll better install it separately (e.g. in your `/usr/local/` prefix)

* [markdown](https://www.markdownguide.org/) is required for some documentation, such as this `README.md`

* GNU [indent](https://www.gnu.org/software/indent/) (2.2.x at last) and [astyle](https://sourceforge.net/projects/astyle/)  (3.1 at least) are useful for `make indent`. `indent` is now **required** for generated modules.

* [tardy](http://tardy.sourceforge.net/) (a `tar` file postprocessor) is used to generate documentation.

* [LaTeX](https://latex.org/) -probably as
  [texlive](https://www.tug.org/texlive/) suite or
  [luatex](http://luatex.org/)- and related utilities (`pdflatex`,
  `makeidx`, `bibtex` ...) with [inkscape](https://inkscape.org/) and
  [hevea](http://hevea.inria.fr/) and  [xindy](http://www.xindy.org/) are needed for documentation.

### relevant Debian/Ubuntu build-dependency packages ###

On Debian/Unstable or recent Ubuntu, `apt-get install build-essential
make ninja-build gcc-8 g++-8 gcc-8-plugin-dev libgccjit-8-dev ccache
gcc-8-mipsel-linux-gnu inkscape hevea texlive-full xindy
fonts-inconsolata ttf-ubuntu-font-family fonts-ubuntu ttfautohint guile-2.2 mailutils-guile` for
the building infrastructure; notice that `gcc-8-mipsel-linux-gnu` is
the MIPSel GCC cross-compiler - it is *conflicting* with
`gcc-multilib*` packages; `inkscape`, `hevea`, `texlive-full` (a
*huge* meta-package), `xindy`, `fonts-inconsolata`, `fonts-ubuntu`,
`ttfautohint` are needed for generating the documentation.



We still need `apt-get install libgtk-3-dev` for GTK 3. This may pull a lot of dependencies.

And `apt-get install libglib2.0-dev libjansson-dev` for our
[Glib](https://developer.gnome.org/glib/stable/) and
[Jansson](http://www.digip.org/jansson/) required dependencies.

The `libbacktrace` is not independently packaged in Debian. I recommend building and installing
it from its source code, or else (not recommended, :unamused: but doable) edit the `Makefile` to uses your system GCC compiler's one.

The `libonion` is not independently packaged in Debian.

`apt-get install markdown indent astyle tardy` and `apt-get install texlive texlive-full hevea` 

The `dependencies/` subdirectory is for `git submodule`-s related to `libbacktrace` and `libonion`

You may need to add `.mjs` as a valid suffix or file extension for
`application/javascript` MIME type in your `/etc/mime.types` system
file. Read about [Javascript modules on the
web](https://developers.google.com/web/fundamentals/primers/modules)
and see [Debian
bug#927300](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=927300).


### Localization

Run `locale` to **be sure that your localization is POSIX compliant or
English** (British or American) **in UTF-8** (it cannot for instance
be Italian or Greek or French). So it should be `POSIX` or `C` or
`en_US.UTF-8` or `en_GB.UTF-8`. You might want to set your environment
variables appropriately (at least `LANG=en_US.UTF-8` and
`LANGUAGE=en_US:en` and `LC_ALL=en_US.UTF-8`, with no other `LC_*`
environment variable). See
[locale(1)](http://man7.org/linux/man-pages/man1/locale.1.html),
[locale(7)](http://man7.org/linux/man-pages/man7/locale.7.html),
[utf-8(7)](http://man7.org/linux/man-pages/man7/utf-8.7.html),
[locale(5)](http://man7.org/linux/man-pages/man5/locale.5.html),
[setlocale(3)](http://man7.org/linux/man-pages/man3/setlocale.3.html). But
don't ask me to understand more these very subtle [internationalizaion
and
localization](https://en.wikipedia.org/wiki/Internationalization_and_localization)
details, that topic is *very* complex. If you still need that work to
be done by me, send me an email at work to
`basile.starynkevitch@cea.fr`. But don't expect it to be done by me
before 2024.


### Additional configuration

The `.mjs` file extension is for [JavaScript
modules](https://developers.google.com/web/fundamentals/primers/modules). If
your `/etc/mime.types` file (used by `libonion`) does not know about
it, you need to add there the following lines (the first line below,
with an hash `#`, is a comment; what is important is the line
mentioning `mjs`).

```
# in your /etc/mime.types for JavaScript modules
application/javascript                                 mjs
```


The documentation generation needs a writable `$HOME/tmp/` directory.

A main human responsible contact should be given in a `contact_BM`
file (comments starting with `#` are accepted inside, but it should
have a line inspired by `John Doe <bismon.master@example.com>`). That
file should be in the current directory or your home directory or
explicitly given with `--contact-file=PATH`. My `~/contact_BM` file could be:

```
# file $HOME/contact_BM
Bismon master (Basile Starynkevitch) <bismon-master@example.com>
```

#### extra `git` configuration

You might want (adapt
[this](https://stackoverflow.com/a/46115809/841108) suggestion and
[define your custom
hunk-header](https://git-scm.com/docs/gitattributes#_defining_a_custom_hunk_header))
to improve the interactive output of `git diff` on `store*.bmon`
persistent data files. Perhaps something inspired from
`git config diff.bismon.xfuncname '"^«_[0-9A-Za-z_]*$"'` might work, but not really.


## building ##

Clone this `git` repository as usual, and build then use `bismon`
inside the obtained source tree.

Look into the `Makefile`, and edit it if needed; perhaps update the
`PREPROFLAGS=` and `LIBES=` lines, e.g. to use your system's GCC
`libbacktrace`, by adding `$(shell gcc-7 -print-file-name=include)`
into the `PREPROFLAGS=` line, and `$(shell gcc-7
-print-file-name=libbacktrace.a)` to the `LIBES=` line. Of course
replace the 7 by 8 if appropriate. Maybe you need to explicitly set
`GCC=` and `GXX=` to your specific GCC *C* and *C++* compilers.

Run `make` or `make -j3`

The persistency mechanism is tested by `make redump`

The `./bismon` program is (temporarily) still using GTK and
libonion. We want to get rid of GTK. It is symlinked as `bismongtk`
and `bismonion`.



Be sure to run `bismon`, `bismongtk` or `bismonion` with `--help` at first to
understand the program options that are available.

## adding yourself as a contributor

`bismon` (at least its Web version) needs to know about you. So you
should register yourself *once* to it (and that would grow its
persistent state). And `bismon` (more exactly `bismonion`) has a login
form, so you should have a password (specific to `bismon`, unrelated
to any other password you have).

You first need to initialize an *empty* password file (the default
password file is `~/passwords_BM`; you could specify another one on
the command line). So run the command `touch ~/passwords_BM` in a
terminal (shell) to create that empty file. Then you need to restrict
its permission (readable and writable by your Unix user only) with
`chmod u+rw,go-rwx ~/passwords_BM`. At last, check with `ls -ls
~/passwords_BM` that this file is empty and readable & writable only
by you.

Then you'll register yourself. If `Alan Turing` is your name or
pseudo, and `alan@fake.email` is your main email, with your secondary
email being `turing@localhost`, you can add yourself to `bismon` by
running it with something similar to
`--contributor='Alan Turing;alan@fake.email;turing@localhost'` and
`--batch` and `--dump-after-load=.` program options. Of course you
should replace `Alan Turing`, `alan@fake.email` and `turing@localhost`
by whatever is appropriate for you. The secondary email (also called
alias) is optional. If you don't use it (so if you don't provide any
alias, which is likely - so replace `turing@localhost` with an empty
string), `bismon` knows no more about you than `git` does (see [git
config](https://git-scm.com/docs/git-config) for `user.email` and
`user.name`). You might even code some shell script to extract that
personal data information from `git` and put it into `bismon`.

At last you need to set your password (it is unrelated to other
passwords in your computer or on the web, but should has at least 10
Unicode characters, and digits, letters, punctuations), as known to
`bismon`, using the `--add-passwords` option (also with `--batch`
and `--dump-after-load=.`). To set your initial password to
`mypass!123456` create some temporary text file (it contains
contributor names and their updated passwords in *clear* text, so you
should not keep it), perhaps `/tmp/addpassbismon`, containing for
example `Alan Turing:mypass!123456` add run `bismonion` with
`--add-passwords=/tmp/addpassbismon --batch` then *remove*
`/tmp/addpassbismon`. Of course you'll better write some shell script
wrapping that, and be sure to have a strong enough password which is
not in this `README.md`.

You might perhaps add a few other users (probably less than a dozen)
that you trust and that can work with you.  Every user could mess or
abuse the `bismon` system as easily as you could.  Be then sure to be
compliant with the [GDPR](https://www.eugdpr.org/) if any of your
users is European (and GDPR compliance is then *your
responsability*). The login form is templated (with code from
`web_ONIONBM.c`) from source file `login_ONIONBM.thtml` (and you might
improve the text inside that file if you want).

## using `bismon` ##

It is **not really usable yet** except by me (Basile) in july 2018 (no
static source code analysis yet, no generation of GCC plugins yet). If
you want to see something using GTK, run `./bismongtk` then type
`the_system` in the command window labelled *new-bismon*, then both
*Ctrl* and *Return* keys pressed together. If you want to see
something thru the web interface, run `./bismonion` then open its URL
(perhaps `localhost:8086/` or whatever has been specified with
`--web-base`) in your web browser.

It is recommended to run `make clean` once in a while (e.g. daily or
weekly). When generating files, `bismon` makes a backup of their
previous version.

Ask me (Basile Starynkevitch,
[`basile@starynkevitch.net`](mailto:basile@starynkevitch.net) or
[`basile.starynkevitch@cea.fr`](mailto:basile.starynkevitch@cea.fr)...)
for details.

#### Caveat

This `git` repository also contains, for convenience, the
[jqueryui](http://jqueryui.com/) 1.12 framework (which has a different
MIT license) under `webroot/jquery-ui`

#### A shell script to stop Bismon

Use it (as `stopbismon`) your own risk, if `$HOME/bismon` contains Bismon source code and executable:

```
#!/bin/bash -x
# script stopbismon
if [ -f $HOME/bismon/_bismon.pid ]; then
   kill -TERM $(/bin/head -1  $HOME/bismon/_bismon.pid)
else
   pkill bismon
fi	
```

#### N.B.


**This is unreleased free software**

The license (GPLv3+) is likely to not change (it is contractually
specified in the [CHARIOT](http://chariotproject.eu/) grant).  The
copyright notice is probably wrong: in generated files, it is not yet
conforming to GPL expectations.  These details are pending bugs, but
there are much more other bugs too.

#### P.S.

The author is fully aware -in mid 2019- of **several bugs** in this
`bismon` system - a research project -, but correcting them is *not* a
priority (since continuing the progressive bootstrap of *Bismon* is
**much more important**, and is not yet achieved). The GTK interface
is buggy *by design* and crashes often (that won't be corrected), and
should be as quickly as possible replaced by a more usable web
interface - and that is work in progress in mid 2019. Please contact
by email the author to get possible workarounds. Notice that such
temporary bugs known to the author are *not* registered as [Bismon
`gitlab` issues](https://github.com/bstarynk/bismon/issues), since
this software is yet unreleased.


#### Bug in documentation

In commit 24e400e4b25ea8fbd91 the documentation fails to be generated.

* observation 1

Removing `\input{appendix-bm}` from file `bismon-doc.tex` dont solve that bug.

# Reporting bugs, feature requests, issues #

The preferred way to report them is to add some new [issue](https://github.com/bstarynk/bismon/issues) on https://github.com/bstarynk/bismon

Of course, an issue should be self-contained. Please give *explicitly*
the output of `bismon --version` on your computer if you have been
able to build `bismon`.

If the issue is related to building the `bismon` executable, give
*explicitly* all the Linux commands you have run (after having
examined and *successfully* run the `distclean-script.bash` script, or
just after some *fresh* `git clone` command). Mention the output of
`git log -3`.

Alternatively (if you don't want to add a `github` issue), send an
email (UTF-8 encoded, HTML5 is preferable) in English, or in French,
(or perhaps in Russian, only if you cannot send an email in English or
French) to
[`basile@starynkevitch.net`](mailto:basile@starynkevitch.net) or
[basile.starynkevitch@cea.fr](mailto:basile.starynkevitch@cea.fr).  I
will try to answer in English or in French (since my written Russian
is so bad).

If you need to send a screenshot, attach some image encoded as JPEG or
PNG to your email.

If you want or need to send several files, archive all of them in a
unique directory (whose
[basename(1)](https://man7.org/linux/man-pages/man1/basename.1.html)
contains only letters, digits, and some underscore `_`) and make some
[tar(1)](https://man7.org/linux/man-pages/man1/tar.1.html) archive of
them. Give me explicitly the `tar` command I need to run (on Linux) to
extract your archive. You could assume I have [GNU
tar](https://www.gnu.org/software/tar/) version 1.30 or better on my
Linux computer.

If you send me some C or C++ code to be processed by `bismon`, allow
me *explicitly* to compile it and add comments (UTF8 encoded) in
English, French or Russian.

If possible, add some shell script (for [GNU
bash](https://www.gnu.org/software/bash/) or for
[zsh](https://zsh.org/) ....) which enables me to reproduce that bug,
and name that script in your email or bug report.

My employer (if you are outside of [CEA](https://www.cea.fr/) ....)
could prefer also some information related to funding, formal
collaboration, etc... If possible mention them explicitly in English
or in French in your email.


