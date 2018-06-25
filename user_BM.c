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

static objectval_tyBM *add_contributor_name_email_alias_BM
  (const char *name,
   const char *email,
   const char *alias, bool verbose, struct stackframe_stBM *stkf);

#warning we also need a valid_name_BM and the verbose flag should be replaced by some char** pointer...
static bool valid_email_BM (const char *email, bool verbose);

bool
valid_email_BM (const char *email, bool verbose)
{
  if (!email)
    return false;
  if (!isalpha (email[0]))
    {
      if (verbose)
        fprintf (stderr, "mail address %s don't start with letter\n", email);
      return false;
    }
  const char *at = strchr (email, '@');
  if (!at || !at[1])
    {
      if (verbose)
        fprintf (stderr, "mail address %s don't have at-sign\n", email);
      return false;
    }
  if (strchr (at + 1, '@'))
    {
      if (verbose)
        fprintf (stderr, "mail address %s has more than one at-sign\n",
                 email);
      return false;
    }
  for (const char *pc = email; pc < at; pc++)
    {
      if (isalnum (*pc))
        continue;
      if (*pc == '.' || *pc == '+' || *pc == '-' || *pc == '_')
        {
          if (!isalnum (pc[-1]) || !isalnum (pc[1]))
            {
              if (verbose)
                fprintf (stderr,
                         "mail address %s with bad . + - or _ occurrences before at-sign\n",
                         email);
              return false;
            }
          else
            continue;
        }
      if (verbose)
        fprintf (stderr,
                 "mail address %s with unexpected characters before at-sign\n",
                 email);
      return false;
    }
  for (const char *pc = at + 1; pc < at; pc++)
    {
      if (isalnum (*pc))
        continue;
      if (*pc == '.' || *pc == '+' || *pc == '-' || *pc == '_')
        {
          if (!isalnum (pc[-1]) || !isalnum (pc[1]))
            {
              fprintf (stderr,
                       "mail address %s with bad . + - or _ occurrences after at-sign\n",
                       email);
              return false;
            }
          else
            continue;
        }
      if (verbose)
        fprintf (stderr,
                 "mail address %s with unexpected characters after at-sign\n",
                 email);
      return false;
    }
  struct addrinfo *res = NULL;
  int err = getaddrinfo (at + 1, "mail", NULL, &res);
  if (err)
    {
      if (verbose)
        fprintf (stderr,
                 "mail address %s domain %s failed on getaddrinfo: %s\n",
                 email, at + 1, gai_strerror (err));
      return false;
    }
  if (res)
    freeaddrinfo (res);
  else
    {
      if (verbose)
        fprintf (stderr,
                 "mail address %s domain %s invalid\n", email, at + 1);
      return false;
    }
  return true;
}                               /* end valid_email_BM */




objectval_tyBM *
add_contributor_name_email_alias_BM (const char *name,
                                     const char
                                     *email,
                                     const char
                                     *alias,
                                     bool verbose,
                                     struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  if (!alias)
    alias = "";
  DBGPRINTF_BM
    ("add_contributor_name_email_alias start name='%s' email='%s' alias='%s' verbose %s",
     name, email, alias, verbose ? "yes" : "no");
  ASSERT_BM (name && name[0]);
  ASSERT_BM (email && email[0]);
  const char *end = NULL;
  if (!g_utf8_validate (name, -1, &end) && end && *end)
    {
      if (verbose)
        fprintf (stderr, "invalid UTF8 in contributor name '%s'\n", name);
      LOCALRETURN_BM (NULL);
    }
  end = NULL;
  if (!g_utf8_validate (email, -1, &end) && end && *end)
    {
      if (verbose)
        fprintf (stderr,
                 "invalid UTF8 in contributor (for %s) email '%s'\n",
                 name, email);
      LOCALRETURN_BM (NULL);
    }
  end = NULL;
  if (!g_utf8_validate (alias, -1, &end) && end && *end)
    {
      if (verbose)
        fprintf (stderr,
                 "invalid UTF8 in contributor (for %s)  alias '%s'\n",
                 name, alias);
      LOCALRETURN_BM (NULL);
    }
  // validate the name:
  gunichar uc = 0;
  gunichar prevuc = 0;
  for (const char *p = name;
       *p && (uc = g_utf8_get_char (p)) != 0;
       (p = g_utf8_next_char (p)), (prevuc = uc))
    {
      if (g_unichar_isalpha (uc))
        continue;
      else if (g_unichar_isalnum (uc) && p > name)
        continue;
      else
        if ((uc == '_' || uc == '-' || uc == '+' || uc == ' ')
            && g_unichar_isalnum (prevuc) && *g_utf8_next_char (p))
        continue;
      if (verbose)
        fprintf (stderr, "invalid contributor name '%s'\n", name);
      LOCALRETURN_BM (NULL);
    }
  // validate the email and the alias (if given)
  if (!valid_email_BM (email, verbose))
    {
      if (verbose)
        fprintf (stderr,
                 "invalid email %s for contributor %s\n", email, name);
      LOCALRETURN_BM (NULL);
    };
  if (alias && alias[0] && !valid_email_BM (alias, verbose))
    {
      if (verbose)
        fprintf (stderr,
                 "invalid alias %s for contributor %s\n", alias, name);
      LOCALRETURN_BM (NULL);
    }
  FILE *fil = fopen (CONTRIBUTORS_FILE_BM, "r+");
  if (!fil)
    {
      if (verbose)
        fprintf (stderr, "fail to open %s : %m\n", CONTRIBUTORS_FILE_BM);
      LOCALRETURN_BM (NULL);
    }
  int fd = fileno (fil);
  if (flock (fd, LOCK_EX))
    FATAL_BM ("failed to flock fd#%d for %s", fd, CONTRIBUTORS_FILE_BM);
#warning add_contributor_name_email_alias unimplemented
  FATAL_BM
    ("add_contributor_name_email_alias unimplemented user name '%s' email '%s' alias '%s'",
     name, email, alias);
}                               /* end add_contributor_name_email_alias_BM */



objectval_tyBM *
add_contributor_user_BM (const char *str,
                         bool verbose, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  const char *namestr = NULL;
  const char *emailstr = NULL;
  const char *aliasstr = NULL;
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
    if (*pc == '\n' || *pc == '\r' || *pc == '\t'
        || *pc == '\r' || *pc == '\v' || *pc == '\f'
        || (*pc != ' ' && (isspace (*pc) || iscntrl (*pc))))
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
      namestr = strndup (str, namend - str + 1);
      if (!namestr)
        FATAL_BM ("strndup failed, when extracting name from %s", str);
      emailstr = strndup (lt + 1, gt - lt - 1);
      if (!emailstr)
        FATAL_BM ("strndup failed, when extracting email from %s", str);
      DBGPRINTF_BM
        ("add_contributor_user_BM namestr='%s' emailstr='%s'",
         namestr, emailstr);
      _.userob =
        add_contributor_name_email_alias_BM (namestr,
                                             emailstr, NULL,
                                             verbose, CURFRAME_BM);
      DBGPRINTF_BM
        ("add_contributor_user_BM userob=%s for namestr='%s' emailstr='%s'",
         objectdbg_BM (_.userob), namestr, emailstr);
      free ((void *) namestr), namestr = NULL;
      free ((void *) emailstr), emailstr = NULL;
      LOCALRETURN_BM (_.userob);
    }
  // or like: 'First Lastname;email@example.com;aliasmail@example.org'
  // or just: 'First Lastname;email@example.com'
  const char *semcol1 = strchr (str, ';');
  const char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
  if (semcol1)
    {
      char *namend = semcol1 - 1;
      while (namend > str && *namend == ' ')
        namend--;
      namestr = strndup (str, namend - str + 1);
      if (!namestr)
        FATAL_BM ("strndup failed, when extracting name from %s", str);
      if (semcol2)
        {
          emailstr = strndup (semcol1 + 1, semcol2 - semcol1 - 1);
          if (!emailstr)
            FATAL_BM ("strndup failed, when extracting email from %s", str);
          aliasstr = strdup (semcol2 + 1);
          if (!aliasstr)
            FATAL_BM ("strndup failed, when extracting alias from %s", str);
          DBGPRINTF_BM
            ("add_contributor_user_BM namestr='%s' emailstr='%s' aliasstr='%s'",
             namestr, emailstr, aliasstr);
        }
      else
        {
          emailstr = strdup (semcol1 + 1);
          DBGPRINTF_BM
            ("add_contributor_user_BM namestr='%s' emailstr='%s'",
             namestr, emailstr);
        }
      _.userob =
        add_contributor_name_email_alias_BM (namestr,
                                             emailstr,
                                             aliasstr, verbose, CURFRAME_BM);
      if (aliasstr)
        DBGPRINTF_BM
          ("add_contributor_user_BM userob=%s for namestr='%s' emailstr='%s' aliasstr='%s'",
           objectdbg_BM (_.userob), namestr, emailstr, aliasstr);
      else
        DBGPRINTF_BM
          ("add_contributor_user_BM userob=%s for namestr='%s' emailstr='%s'",
           objectdbg_BM (_.userob), namestr, emailstr);
      free ((void *) namestr), namestr = NULL;
      free ((void *) emailstr), emailstr = NULL;
      free ((void *) aliasstr), aliasstr = NULL;
      LOCALRETURN_BM (_.userob);
    }
  if (verbose)
    fprintf (stderr,
             "invalid user string '%s',\n"
             "... expecting 'First Lastname <email@example.com>'\n"
             "... or 'First Lastname;email@example.com;aliasmail@example.org'\n",
             str);
  LOCALRETURN_BM (NULL);
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
