// file user_BM.c; management of European GDPR related personal data; see userlogin.md

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
***/
#include "bismon.h"
#include "user_BM.const.h"

static
  objectval_tyBM *add_contributor_name_email_alias_BM (const char *name,
                                                       const char *email,
                                                       const char *alias,
                                                       bool verbose,
                                                       struct stackframe_stBM
                                                       *stkf);

objectval_tyBM *
add_contributor_name_email_alias_BM (const char *name, const char *email,
                                     const char *alias, bool verbose,
                                     struct stackframe_stBM *stkf)
{
}                               /* end add_contributor_name_email_alias_BM */

objectval_tyBM *
add_contributor_user_BM (const char *str, bool verbose,
                         struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  if (!str)
    return NULL;
  DBGPRINTF_BM ("add_contributor_user_BM str='%s'", str);
  if (!str[0])
    {
      if (verbose)
        fprintf (stderr, "empty user string\n");
      return NULL;
    }
  if (isspace (str[0]))
    {
      if (verbose)
        fprintf (stderr, "user string '%s' cannot start with a space\n", str);
      return NULL;
    }
  if (isdigit (str[0]) || str[0] == '_')
    {
      if (verbose)
        fprintf (stderr,
                 "user string '%s' cannot start with a digit or underscore\n",
                 str);
      return NULL;
    }
  for (const char *pc = str; *pc; pc++)
    if (*pc == '\n' || *pc == '\r' || *pc == '\t' || *pc == '\r'
        || *pc == '\v' || *pc == '\f' || (*pc != ' '
                                          && (isspace (*pc)
                                              || iscntrl (*pc))))
      {
        if (verbose)
          fprintf (stderr,
                   "user string '%s' cannot contain control or tab, return or weird space characters",
                   str);
        return NULL;
      }
  const char *endstr = str + strlen (str);
  const char *lt = strchr (str, '<');
  const char *at = lt ? strchr (lt, '@') : NULL;
  const char *gt = at ? strchr (at, '>') : NULL;
  if (lt && at && gt && lt > str && gt == endstr - 1)
    {
      // str could be like 'First Lastname <email@example.com>'
      char *namend = lt - 1;
      while (namend > str && *namend == ' ')
        namend--;
    }
  // or like: 'First Lastname;email@example.com;aliasmail@example.org'
  FATAL_BM ("unimplemented add_contributor_user_BM str %s", str);
#warning unimplemented add_contributor_user_BM
}                               /* end add_contributor_user_BM */

objectval_tyBM *
remove_contributor_user_by_string_BM (const char *str,
				      bool verbose,
                                      struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  FATAL_BM ("unimplemented remove_contributor_user_by_string_BM str %s", str);
#warning unimplemented remove_contributor_user_by_string_BM
}                               /* end remove_contributor_user_by_string_BM */
