<!-- file userlogin.md -->

# Users and login #

Temporary notes about users. We need some limited user related
information and some kind of authentication (e.g. a login web form).

We care about having only a few users (typically a few dozens at most,
that is the developers of some common software project, and probably
less than ten). In the unlikely case we have -after several years-
many users, many things should be redesigned later for that. So
scalability to many users is not a concern.

**All the users of some `bismon` system** (that is, a particular
running instance on some Linux machine, perhaps accessed thru
HTTP/HTTPS by browsers on some *local* area network) **are trusted**
(once they have been able to login). Protecting one user against the
mistakes of another one is not a concern. The persistent state of
`bismon` is expected to be somehow dumped every few hours (and
probably backed up or `git commit`-ed that often). Users are expected
to behave responsibly.

Notice that a git repository can dump the author name and email with
`git log --format '%an / %ae'`. See the *PRETTY FORMAT* section of
[`git log` documentation](https://git-scm.com/docs/git-log.html). In
practice, semicolons are forbidden in both. The author name often
contains a space inside it. For example my author name is `Basile
Starynkevitch` and my author email is `basile@starynkevitch.net`. It
looks like underscores is never used in author names, but dot is
occasionally used.

A `bismon` user name should contain (case sensitively) letters and
digits and dots, dashes, and underscores and start with a letter. We
might make such a name from the `git` author name, replacing inside
spaces by underscores. The letters can be UTF-8 letters. Punctuation
signs are not allowed (other than dots, dashes, underscores which
cannot be doubled).

A `bismon` user (or `bismon` login) is defined by:

* a `bismon` user name, as above.

* the primary email (which should be valid).

* an optional secondary email (it could be empty, i.e. missing)

* the object-id unique to that user (e.g. something like
  `_3sQID0mxoew_16uOC0jEIpe`). That id is expected to be world-wide
  unique and is "randomly" generated.
  
Each `bismon` login has some password, which is stored in some
encrypted fashion in some other file (which should *never* go to `git`
repository).

The bismon login database (supposed to be short, perhaps less than a
dozen entries) is kept into several files. There is one file for
"contributors" - those which could appear in the `git` repository of
`bismon`
and a last file (with a different format) for encrypted passwords.

The `contributors_BM` file has the same textual format, and
 is expected to be `git commit`-ed:

* empty lines, or lines starting with a hash-sign `#` are ignored and
  skipped.
  
* login lines starts have fields separated by semi-colons. The first
  field is the `bismon` user name; the second field is the object-id;
  the third field is the primary email; the last optional field is the
  secondary email.
  
So I (Basile) might be described by a login line in the `contributors`
file such as:
`Basile Starynkevitch;_3sQID0mxoew_16uOC0jEIpe;basile@starynkevitch.net;basile.starynkevitch@cea.fr`
and of course the persistent store would have some object of id
`_3sQID0mxoew_16uOC0jEIpe`


Pseudonimization (in the GDPR sense) might be done by moving (if he
was a contributor) a login line to the `users` file and using a
fictuous username and some `nobody@localhost` email.

Removing a user could be done by also making his object temporary at
dump time.

Dump should also write some `dumped_user_ids` file?  Not sure of that!

The password file `passwords_BM` would contain (semi-colon separated)
lines with object-id, encrypted password, optional username and should
be in `.gitigore`

