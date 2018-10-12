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


static void
write_password_file_BM (FILE * passfil, objectval_tyBM * assocobarg,
                        struct stackframe_stBM *stkf);

////////////////////////////////////////////////////////////////
//// user support; might be relevant to GDPR

void
usergcmark_BM (struct garbcoll_stBM *gc,
               struct user_stBM *us, objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) us) == typayl_user_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  ASSERT_BM (!fromob || !us->user_ownobj || us->user_ownobj == fromob);
  ASSERT_BM (depth >= 0);
  uint8_t oldmark = ((typedhead_tyBM *) us)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) us)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  DBGPRINTF_BM
    ("usergcmark_BM us@%p, usname %s, fromob %s, usownobj %s, depth %d", us,
     bytstring_BM (us->user_namev), objectdbg_BM (fromob),
     objectdbg1_BM (us->user_ownobj), depth);
  if (us->user_ownobj)
    gcobjmark_BM (gc, us->user_ownobj);
  if (us->user_namev)
    EXTENDEDGCPROC_BM (gc, us->user_namev, fromob, depth + 1);
}                               /* end usergcmark_BM */

void
usergcdestroy_BM (struct garbcoll_stBM *gc, struct user_stBM *us)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) us) == typayl_user_BM);
  DBGPRINTF_BM ("usergcdestroy_BM us@%p, usname %s, usownobj %s",
                us, bytstring_BM (us->user_namev),
                objectdbg1_BM (us->user_ownobj));
  if (us->user_ownobj)
    {
      objectval_tyBM *ownerob = us->user_ownobj;
      us->user_ownobj = NULL;
      objlock_BM (ownerob);
      if (objpayload_BM (ownerob) == (extendedval_tyBM) us)
        objclearpayload_BM (ownerob);
      objunlock_BM (ownerob);
    }
  memset ((void *) us, 0, sizeof (*us));
  free (us);
  gc->gc_freedbytes += sizeof (*us);
}                               /* end usergcdestroy_BM */

void
usergckeep_BM (struct garbcoll_stBM *gc, struct user_stBM *us)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((value_tyBM) us) == typayl_user_BM);
  DBGPRINTF_BM ("usergckeep_BM us@%p, usname %s, usownobj %s",
                us, bytstring_BM (us->user_namev),
                objectdbg1_BM (us->user_ownobj));
  gc->gc_keptbytes += sizeof (*us);
}                               /* end usergckeep_BM */


const stringval_tyBM *
objcontributornamepayl_BM (const objectval_tyBM * obj)
{
  if (!objhascontributorpayl_BM (obj))
    return NULL;
  struct user_stBM *usp = objpayload_BM (obj);
  if (valtype_BM ((extendedval_tyBM) usp) != typayl_user_BM)
    return NULL;
  return usp->user_namev;
}                               /* end objcontributornamepayl_BM */


static void
overwrite_contributor_file_BM (FILE * fil,
                               objectval_tyBM * assocobarg,
                               struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //current contributor object 
                 objectval_tyBM * assocob;      //  assoc-object
                 // mapping
                 // contributors-objects to
                 // *contributors(<email>,<alias>)
                 // nodes
                 value_tyBM namev;      // the name string
                 value_tyBM emailv;     // the email string value
                 value_tyBM aliasv;     // the alias string value
                 value_tyBM nodev;      // the node
                 value_tyBM keysetv;    // the set of keys
    );
  _.assocob = assocobarg;
  ASSERT_BM (isobject_BM (assocobarg) && objhasassocpayl_BM (assocobarg));
  rewind (fil);
  int nbcontrib = 0;
  _.keysetv = (value_tyBM) objassocsetattrspayl_BM (_.assocob);
  {
    nbcontrib = objassocnbkeyspayl_BM (_.assocob);
    ASSERT_BM ((int) setcardinal_BM (_.keysetv) == nbcontrib);
    char nowtimbuf[80];
    memset (nowtimbuf, 0, sizeof (nowtimbuf));
    time_t nowt = 0;
    time (&nowt);
    struct tm nowtm = { };
    memset (&nowtm, 0, sizeof (nowtm));
    localtime_r (&nowt, &nowtm);
    strftime (nowtimbuf, sizeof (nowtimbuf), "%c", &nowtm);
    char *baspath = basename (contributors_filepath_BM);
    if (strcmp (baspath, CONTRIBUTORS_FILE_BM))
      fprintf (fil, "## BISMON contributors file %s (really %s)\n",
               CONTRIBUTORS_FILE_BM, contributors_filepath_BM);
    else
      fprintf (fil, "## BISMON contributors file %s\n", CONTRIBUTORS_FILE_BM);
    fprintf (fil,
             "## when BISMON is running, don't edit manually this file; it could be flock-ed.\n");
    fprintf (fil,
             "## use preferably the --contributor or --remove-contributor BISMON  ...\n");
    fprintf (fil,
             "## ... program options of BISMON to change that file at startup\n");
    fprintf (fil, "###############################################\n");
    fprintf (fil, "## written by BISMON built at %s\n", bismon_timestamp);
    fprintf (fil, "## BISMON lastgitcommit %s\n", bismon_lastgitcommit);
    fprintf (fil, "## BISMON checksum %s\n", bismon_checksum);
    fprintf (fil, "##- emitted at %s on %s for %d contributors.\n", nowtimbuf,
             myhostname_BM, nbcontrib);
    fprintf (fil,
             "## format: one login line per user or contributor like:\n");
    fprintf (fil, "## <user-name>;<oid>;<email>;<alias>\n");
    for (int cix = 0; cix < nbcontrib; cix++)
      {
        _.contribob = setelemnth_BM (_.keysetv, cix);
        _.nodev = objassocgetattrpayl_BM (_.assocob, _.contribob);
        ASSERT_BM (nodeconn_BM (_.nodev) == BMP_contributors
                   && nodewidth_BM (_.nodev) == 2);
        _.emailv = nodenthson_BM (_.nodev, 0);
        _.aliasv = nodenthson_BM (_.nodev, 1);
        objlock_BM (_.contribob);
        _.namev = (value_tyBM) objcontributornamepayl_BM (_.contribob);
        objunlock_BM (_.contribob);
        char idbuf[32];
        memset (idbuf, 0, sizeof (idbuf));
        idtocbuf32_BM (objid_BM (_.contribob), idbuf);
        ASSERT_BM (isstring_BM (_.namev));
        ASSERT_BM (isstring_BM (_.emailv));
        ASSERT_BM (!_.aliasv || isstring_BM (_.aliasv));
        ASSERT_BM (valid_contributor_name_BM (bytstring_BM (_.namev), NULL));
        ASSERT_BM (valid_email_BM
                   (bytstring_BM (_.emailv), DONTCHECKDNS_BM, NULL));
        ASSERT_BM (!_.aliasv
                   || valid_email_BM (bytstring_BM (_.aliasv),
                                      DONTCHECKDNS_BM, NULL));
        if (!_.aliasv)
          fprintf (fil, "%s;%s;%s;\n", bytstring_BM (_.namev), idbuf,
                   bytstring_BM (_.emailv));
        else
          fprintf (fil, "%s;%s;%s;%s\n", bytstring_BM (_.namev), idbuf,
                   bytstring_BM (_.emailv), bytstring_BM (_.aliasv));
      }
    fprintf (fil, "#### end of file %s with %d contributors sorted by oid\n",
             CONTRIBUTORS_FILE_BM, nbcontrib);
  }
}                               /* end overwrite_contributor_file_BM */



static objectval_tyBM *add_contributor_name_email_alias_BM
  (const char *name,
   const char *email,
   const char *alias, char **perrmsg, struct stackframe_stBM *stkf);




bool
valid_email_BM (const char *email, bool checkdns, char **perrmsg)
{
  if (perrmsg)
    *perrmsg = NULL;
  if (!email)
    {
      if (perrmsg)
        asprintf (perrmsg, "no email");
      return false;
    }
  const char *end = NULL;
  if (!g_utf8_validate (email, -1, &end) && end && *end)
    {
      if (perrmsg)
        asprintf (perrmsg, "invalid utf8 email %s", email);
      return false;
    }
  if (!isalpha (email[0]))
    {
      if (perrmsg)
        asprintf (perrmsg, "mail address %s don't start with letter", email);
      return false;
    }
  const char *at = strchr (email, '@');
  if (!at || !at[1])
    {
      if (perrmsg)
        asprintf (perrmsg, "mail address %s don't have at-sign", email);
      return false;
    }
  if (strchr (at + 1, '@'))
    {
      if (perrmsg)
        asprintf (perrmsg, "mail address %s has more than one at-sign",
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
              if (perrmsg)
                asprintf (perrmsg,
                          "mail address %s with bad . + - or _ occurrences before at-sign",
                          email);
              return false;
            }
          else
            continue;
        }
      if (perrmsg)
        asprintf (perrmsg,
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
              if (perrmsg)
                asprintf (perrmsg,
                          "mail address %s with bad . + - or _ occurrences after at-sign",
                          email);
              return false;
            }
          else
            continue;
        }
      if (perrmsg)
        asprintf (perrmsg,
                  "mail address %s with unexpected characters after at-sign",
                  email);
      return false;
    }
  if (!strcmp (at + 1, "fake.email") || !strcmp (at + 1, "localhost"))
    return true;
  if (checkdns)
    {
      struct addrinfo *res = NULL;
      int err = getaddrinfo (at + 1, "mail", NULL, &res);
      if (err)
        {
          if (perrmsg)
            asprintf (perrmsg,
                      "mail address %s domain %s failed on getaddrinfo: %s",
                      email, at + 1, gai_strerror (err));
          return false;
        }
      if (res)
        freeaddrinfo (res);
      else
        {
          if (perrmsg)
            asprintf (perrmsg,
                      "mail address %s domain %s invalid\n", email, at + 1);
          return false;
        }
    }
  return true;
}                               /* end valid_email_BM */

bool
valid_contributor_name_BM (const char *name, char **perrmsg)
{
  if (perrmsg)
    *perrmsg = NULL;
  if (!name)
    {
      if (perrmsg)
        asprintf (perrmsg, "no contributor name");
      return false;
    }
  const char *end = NULL;
  if (!g_utf8_validate (name, -1, &end) && end && *end)
    {
      if (perrmsg)
        asprintf (perrmsg, "invalid utf8 contributor name %s", name);
      return false;
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
      if (perrmsg)
        asprintf (perrmsg, "invalid contributor name '%s'", name);
      return false;
    }
  return true;
}                               /* end valid_contributor_name_BM */


objectval_tyBM *
find_contributor_BM (const char *str, struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //current contributor object
    );
  if (!str || !str[0])
    return NULL;
  bool withemail = valid_email_BM (str, DONTCHECKDNS_BM, NULL);
  DBGPRINTF_BM ("find_contributor str='%s' %s email", str,
                withemail ? "with" : "without");
  if (!withemail)
    {
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (str, &errmsg))
        {
          if (errmsg)
            {
              WARNPRINTF_BM ("contributor name %s is not valid: %s", str,
                             errmsg);
              free (errmsg), errmsg = NULL;
            }
          else
            WARNPRINTF_BM ("invalid contributor name %s", str);
          return NULL;
        }
    }
  FILE *fil = fopen (contributors_filepath_BM, "r+");
  if (!fil)
    FATAL_BM ("find_contributor_BM cannot open contributors file %s  : %m",
              contributors_filepath_BM);
  int fd = fileno (fil);
  if (flock (fd, LOCK_EX))
    FATAL_BM ("failed to flock fd#%d for contributors file %s", fd,
              contributors_filepath_BM);
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  if (!linbuf)
    FATAL_BM ("find_contributor_BM can't alloc line of %zd bytes", linsiz);
  /// read loop
  for (;;)
    {
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in %s line#%d is invalid UTF8: %s",
                  contributors_filepath_BM, lincnt, linbuf);
      // linbuf should be like: <username>;<oid>;<email>;<alias>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      char *semcol3 = semcol2 ? strchr (semcol2 + 1, ';') : NULL;
      if (!semcol3)
        FATAL_BM
          ("in %s line#%d should be like <username>;<oid>;<email>;<alias> but is %s",
           contributors_filepath_BM, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      *semcol3 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curemail = semcol2 + 1;
      const char *curalias = semcol3 + 1;
      DBGPRINTF_BM
        ("find_contributor line#%d curcontrib '%s' curoidstr '%s' curemail '%s' curalias '%s'",
         lincnt, curcontrib, curoidstr, curemail, curalias);
      if ((withemail && !strcmp (curemail, str))
          || (!withemail && !strcmp (curcontrib, str)))
        {
          const char *endid = NULL;
          rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
          if (!endid || *endid || !curid.id_hi || !curid.id_lo)
            FATAL_BM ("in %s line#%d has invalid oid %s for contributor %s",
                      contributors_filepath_BM, lincnt, curoidstr,
                      curcontrib);
          _.contribob = findobjofid_BM (curid);
          DBGPRINTF_BM ("find_contributor str '%s' contribob %s", str,
                        objectdbg_BM (_.contribob));
          break;
        }
    }                           // end forloop
  if (flock (fd, LOCK_UN))
    FATAL_BM ("failed to un-flock fd#%d for %s", fd,
              contributors_filepath_BM);
  DBGPRINTF_BM ("find_contributor str '%s' contribob %s", str,
                objectdbg_BM (_.contribob));
  if (_.contribob)
    {
      bool okcontrib = false;
      objlock_BM (_.contribob);
      okcontrib = objhascontributorpayl_BM (_.contribob);
      objunlock_BM (_.contribob);
      DBGPRINTF_BM
        ("find_contributor contribob %s has %s contributor payload",
         objectdbg_BM (_.contribob), okcontrib ? "a" : "no");
      if (!okcontrib)
        _.contribob = NULL;
    }
  DBGPRINTF_BM ("find_contributor str '%s' contribob %s", str,
                objectdbg_BM (_.contribob));
  if (_.contribob)
    {
      objlock_BM (BMP_contributors);
      if (!objhashsetcontainspayl_BM (BMP_contributors, _.contribob))
        {
          DBGPRINTF_BM ("find_contributor contribob %s not in `contributors`",
                        objectdbg_BM (_.contribob));
          _.contribob = NULL;
        }
      objunlock_BM (BMP_contributors);
    }
  // sleep a tiny random amount of time, to make this call unpredictable and a bit costly
  usleep (100 + g_random_int () % 1024);
  DBGPRINTF_BM ("find_contributor_BM str '%s' gives %s",
                str, objectdbg_BM (_.contribob));
  return _.contribob;
}                               /* end find_contributor_BM */





// this check is done only once, during load...
void
check_and_load_contributors_file_BM (struct loader_stBM *ld,
                                     struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_contributor_class = BMK_5BAqWtmxAH6_9rCGuxiNbfc;
  struct stat mystat = { };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //current contributor object
                 objectval_tyBM * hsetob;       //hash set of parsed contributors
                 value_tyBM namev;      /* string value, name of contributor object */
                 value_tyBM contribsetv;        /* set of keys in hsetob */
                 value_tyBM tmpv;       /* temporary */
    );
  ASSERT_BM (valtype_BM ((const value_tyBM) ld) == typayl_loader_BM);
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  if (!ld || ld->ld_magic != LOADERMAGIC_BM)
    FATAL_BM
      ("check_and_load_contributors_file_BM invalid loader for path %s",
       contributors_filepath_BM);
  const char *rcpath = contributors_filepath_BM;
  ASSERT_BM (rcpath != NULL && rcpath[0] == '/');
  FILE *fil = fopen (rcpath, "r+");
  if (!fil)
    {
      FATAL_BM ("cannot open contributors file %s  : %m", rcpath);
      return;
    }
  DBGPRINTF_BM ("check_and_load_contributors_file_BM rcpath='%s'", rcpath);
  _.hsetob = makeobj_BM ();
  int fd = fileno (fil);
  memset (&mystat, 0, sizeof (mystat));
  if (fstat (fd, &mystat))
    FATAL_BM ("failed to fstat fd#%d for %s", fd, rcpath);
  // the file size gives a guess on the initial size of hashset
  objputhashsetpayl_BM (_.hsetob, prime_above_BM (mystat.st_size / 64 + 10));
  if (flock (fd, LOCK_EX))
    FATAL_BM ("failed to flock fd#%d for %s", fd, rcpath);
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  int nbcontrib = 0;
  if (!linbuf)
    FATAL_BM
      ("check_and_load_contributors_file_BM can't alloc line of %zd bytes",
       linsiz);
  /// read loop
  for (;;)
    {
      _.contribob = NULL;
      _.namev = NULL;
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in %s line#%d is invalid UTF8: %s", rcpath,
                  lincnt, linbuf);
      // linbuf should be like: <username>;<oid>;<email>;<alias>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      char *semcol3 = semcol2 ? strchr (semcol2 + 1, ';') : NULL;
      if (!semcol3)
        FATAL_BM
          ("in %s line#%d should be like <username>;<oid>;<email>;<alias> but is %s",
           rcpath, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      *semcol3 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curemail = semcol2 + 1;
      const char *curalias = semcol3 + 1;
      DBGPRINTF_BM
        ("check_and_load_contributors_file line#%d curcontrib '%s' curoidstr '%s' curemail '%s' curalias '%s'",
         lincnt, curcontrib, curoidstr, curemail, curalias);
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM ("in %s line#%d has invalid contributor name %s : %s",
                  rcpath, lincnt, curcontrib, errmsg);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM ("in %s line#%d has invalid oid %s for contributor %s",
                  rcpath, lincnt, curoidstr, curcontrib);
      if (!valid_email_BM (curemail, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid email %s for contributor %s : %s",
           rcpath, lincnt, curemail, curcontrib, errmsg);
      if (curalias[0] && !isspace (curalias[0])
          && !valid_email_BM (curalias, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid alias %s for contributor %s : %s",
           rcpath, lincnt, curalias, curcontrib, errmsg);
      _.contribob = findobjofid_BM (curid);
      if (!_.contribob)
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s is missing in persistent heap,"
           " so remove or comment out that line, then add that contributor",
           rcpath, lincnt, curcontrib, curoidstr);
      if (objhashsetcontainspayl_BM (_.hsetob, _.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s is duplicated",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (!objhashsetcontainspayl_BM (BMP_contributors, _.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s in not in `contributors` hashset-object",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      objlock_BM (_.contribob);
      if (!objectisinstance_BM (_.contribob, k_contributor_class))
        FATAL_BM
          ("in %s line#%d for contributor %s of oid %s the object %s is not of `contributor_class`",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      objclearpayload_BM (_.contribob);
      {
        struct user_stBM *us =
          allocgcty_BM (typayl_user_BM, sizeof (struct user_stBM));
        us->user_ownobj = _.contribob;
        us->user_namev = _.namev = (value_tyBM) makestring_BM (curcontrib);
        objputpayload_BM (_.contribob, us);
        DBGPRINTF_BM
          ("check_and_load_contributors_file lincnt#%d contribob %s with name %s, us@%p",
           lincnt, objectdbg_BM (_.contribob), curcontrib, us);
        ASSERT_BM (objpayload_BM (_.contribob) == us);
      }
      objunlock_BM (_.contribob);
      objhashsetaddpayl_BM (_.hsetob, _.contribob);
      if (!isstring_BM (_.namev))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s has no user-name",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (strcmp (bytstring_BM (_.namev), curcontrib))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s which has unexpected name %s",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob),
           bytstring_BM (_.namev));
      _.namev = NULL;
      _.contribob = NULL;
      nbcontrib++;
    }
  if (flock (fd, LOCK_UN))
    FATAL_BM ("failed to un-flock fd#%d for %s", fd, rcpath);
  DBGPRINTF_BM ("check_and_load_contributors_file nbcontrib=%d", nbcontrib);
  // check that all the contributors in BMP_contributors are also in hsetob
  _.contribob = NULL;
  _.contribsetv = (value_tyBM) objhashsettosetpayl_BM (BMP_contributors);
  if (!isset_BM (_.contribsetv))
    FATAL_BM ("the `contributors` object has no hashset payload as expected");
  int csetsiz = setcardinal_BM (_.contribsetv);
  ASSERT_BM (objhashashsetpayl_BM (_.hsetob));
  {
    _.tmpv = (value_tyBM) objhashsettosetpayl_BM (_.hsetob);
    DBGPRINTF_BM ("check_and_load_contributors_file hsetob %s with %s", objectdbg_BM (_.hsetob),        //
                  debug_outstr_value_BM (_.tmpv, CURFRAME_BM, 0));
    _.tmpv = NULL;
  }
  for (int cix = 0; cix < csetsiz; cix++)
    {
      _.contribob = setelemnth_BM (_.contribsetv, cix);
      if (!objhashsetcontainspayl_BM (_.hsetob, _.contribob))
        FATAL_BM
          ("contributor object %s (of name %s) is in `contributors` but don't appear in %s",
           objectdbg_BM (_.contribob),
           bytstring_BM (objcontributornamepayl_BM (_.contribob)), rcpath);
    }
  if (fclose (fil))
    FATAL_BM ("failed to fclose %s", rcpath);
  fil = NULL;
  INFOPRINTF_BM
    ("check and load of %d contributors in file %s completed successfully\n",
     nbcontrib, rcpath);
}                               /* end check_and_load_contributors_file_BM */

////////////////

void
check_passwords_file_BM (struct loader_stBM *ld, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //current contributor object
                 value_tyBM namev;      /* string value, name of contributor object */
    );
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  if (!ld || ld->ld_magic != LOADERMAGIC_BM)
    FATAL_BM
      ("check_passwords_file_BM invalid loader for path %s",
       passwords_filepath_BM);
  ASSERT_BM (passwords_filepath_BM && passwords_filepath_BM[0] == '/');
  FILE *passfil = fopen (passwords_filepath_BM, "r");
  if (!passfil)
    FATAL_BM ("check_contributor_password fopen %s failed: %m",
              passwords_filepath_BM);
  if (flock (fileno (passfil), LOCK_EX))
    FATAL_BM ("check_contributor_password failed to flock fd#%d for %s",
              fileno (passfil), passwords_filepath_BM);
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  if (!linbuf)
    FATAL_BM ("check_contributor_password failed to calloc line of %zd",
              linsiz);
  /// read password file loop
  for (;;)
    {
      ssize_t linlen = getline (&linbuf, &linsiz, passfil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in password file %s line#%d is invalid UTF8: %s",
                  passwords_filepath_BM, lincnt, linbuf);
      // linbuf should be like: <contribname>;<oid>;<encrypted-password>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      if (!semcol2)
        FATAL_BM
          ("in password file %s line#%d should be like <contributor-name>;<oid>;<encrypted-password> but is %s",
           passwords_filepath_BM, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curcryptpass = semcol2 + 1;
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM
          ("in password file %s line#%d has invalid contributor name %s : %s",
           passwords_filepath_BM, lincnt, curcontrib, errmsg);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM
          ("in password file %s line#%d has invalid oid %s for contributor %s",
           passwords_filepath_BM, lincnt, curoidstr, curcontrib);
      _.contribob = findobjofid_BM (curid);
      if (!_.contribob)
        {
          WARNPRINTF_BM
            ("in password file %s line#%d has unknown oid %s for contributor %s, skipping...\n",
             passwords_filepath_BM, lincnt, curoidstr, curcontrib);
          continue;
        }
      objlock_BM (_.contribob);
      if (!objhascontributorpayl_BM (_.contribob))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s and object %s is not a contributor-object",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr,
           objectdbg_BM (_.contribob));
      _.namev = (value_tyBM) objcontributornamepayl_BM (_.contribob);
      objunlock_BM (_.contribob);
      if (!isstring_BM (_.namev)
          || strcmp (bytstring_BM (_.namev), curcontrib))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s and object %s which has unexpected name %s",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr,
           objectdbg_BM (_.contribob), bytstring_BM (_.namev) ? : "**none**");
      if (strncmp (curcryptpass, "$6$", 3))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s and object %s has bad encrypted password %s",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr,
           objectdbg_BM (_.contribob), curcryptpass);

    }
  if (linbuf)
    free (linbuf), linbuf = NULL;
  if (passfil)
    {
      if (flock (fileno (passfil), LOCK_UN))
        FATAL_BM ("failed to un-flock fd#%d for %s", fileno (passfil),
                  passwords_filepath_BM);
      if (fclose (passfil))
        FATAL_BM ("failed to fclose %s", passwords_filepath_BM);
      passfil = NULL;
    }
}                               /* end check_passwords_file_BM */

////////////////

objectval_tyBM *add_contributor_name_email_alias_BM
  (const char *name, const char *email, const char *alias,
   char **perrmsg, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_contributor_class = BMK_5BAqWtmxAH6_9rCGuxiNbfc;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * newcontribob; //returned contributor object 
                 objectval_tyBM * contribob;    //current contributor object 
                 objectval_tyBM * assocob;      // temporary assoc-object
                 // mapping
                 // contributors-objects to
                 // *contributors(<email>,<alias>)
                 // nodes
                 value_tyBM namev;      // the name string
                 value_tyBM emailv;     // the email string value
                 value_tyBM aliasv;     // the alias string value
                 value_tyBM nodev;      // the node
    );
  bool knowncontrib = false;
  if (!alias)
    alias = "";
  if (perrmsg)
    *perrmsg = NULL;
  DBGPRINTF_BM
    ("add_contributor_name_email_alias start name='%s' email='%s' alias='%s' perrmsg@%p",
     name, email, alias, (void *) perrmsg);
  ASSERT_BM (name && name[0]);
  ASSERT_BM (email && email[0]);
  if (!valid_contributor_name_BM (name, perrmsg))
    LOCALRETURN_BM (NULL);
  if (!valid_email_BM (email, CHECKDNS_BM, perrmsg))
    LOCALRETURN_BM (NULL);
  if (alias && alias[0] && !valid_email_BM (alias, CHECKDNS_BM, perrmsg))
    LOCALRETURN_BM (NULL);
  // the contributor files should exist and contain only valid
  // entries. Otherwise fatal error!
  FILE *fil = fopen (contributors_filepath_BM, "r+");
  if (!fil)
    {
      FATAL_BM ("cannot open contributors file %s : %m",
                CONTRIBUTORS_FILE_BM);
      LOCALRETURN_BM (NULL);
    }
  const char *rcpath = contributors_filepath_BM;
  struct stat mystat = { };
  if (!rcpath)
    FATAL_BM ("cannot get real path of contributor file %s: %m",
              CONTRIBUTORS_FILE_BM);
  int fd = fileno (fil);
  memset (&mystat, 0, sizeof (mystat));
  if (fstat (fd, &mystat))
    FATAL_BM ("failed to fstat fd#%d for %s", fd, rcpath);
  // the file size gives a guess on the initial size of assocob
  _.assocob = makeobj_BM ();
  objputassocpayl_BM (_.assocob, prime_above_BM (mystat.st_size / 64 + 10));
  if (flock (fd, LOCK_EX))
    FATAL_BM ("failed to flock fd#%d for %s", fd, rcpath);
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  int nbcontrib = 0;
  if (!linbuf)
    FATAL_BM
      ("add_contributor_name_email_alias can't alloc line of %zd bytes",
       linsiz);
  /// reading loop
  for (;;)
    {
      _.contribob = NULL;
      _.namev = NULL;
      _.emailv = NULL;
      _.aliasv = NULL;
      _.nodev = NULL;
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in %s line#%d is invalid UTF8: %s",
                  rcpath, lincnt, linbuf);
      // linbuf should be like: <username>;<oid>;<email>;<alias>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      char *semcol3 = semcol2 ? strchr (semcol2 + 1, ';') : NULL;
      if (!semcol3)
        FATAL_BM
          ("in %s line#%d should be like <username>;<oid>;<email>;<alias> but is %s",
           rcpath, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      *semcol3 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curemail = semcol2 + 1;
      const char *curalias = semcol3 + 1;
      DBGPRINTF_BM
        ("add_contributor_name_email_alias file %s line#%d curcontrib '%s' curoidstr '%s' curemail '%s' curalias '%s'",
         rcpath, lincnt, curcontrib, curoidstr, curemail, curalias);
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM ("in %s line#%d has invalid contributor name %s : %s",
                  rcpath, lincnt, curcontrib, errmsg);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM ("in %s line#%d has invalid oid %s for contributor %s",
                  rcpath, lincnt, curoidstr, curcontrib);
      if (!valid_email_BM (curemail, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid email %s for contributor %s : %s",
           rcpath, lincnt, curemail, curcontrib, errmsg);
      if (curalias[0] && !isspace (curalias[0])
          && !valid_email_BM (curalias, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid alias %s for contributor %s : %s",
           rcpath, lincnt, curalias, curcontrib, errmsg);
      _.contribob = findobjofid_BM (curid);
      if (!_.contribob)
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s is missing in persistent heap,"
           " so remove or comment out that line, then add that contributor after restarting",
           rcpath, lincnt, curcontrib, curoidstr);
      objlock_BM (_.contribob);
      if (!objhascontributorpayl_BM (_.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s is not a user-object",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      _.namev = (value_tyBM) objcontributornamepayl_BM (_.contribob);
      objunlock_BM (_.contribob);
      if (objassocgetattrpayl_BM (_.assocob, _.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s is duplicated",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (!isstring_BM (_.namev))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s has no user-name",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (strcmp (bytstring_BM (_.namev), curcontrib))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s which has unexpected name %s",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob),
           bytstring_BM (_.namev));
      _.emailv = (value_tyBM) makestring_BM (curemail);
      _.aliasv = (curalias
                  && curalias[0]) ? (value_tyBM) makestring_BM (curalias) :
        NULL;
      _.nodev =
        (value_tyBM) makenode2_BM (BMP_contributors, _.emailv, _.aliasv);
      objassocaddattrpayl_BM (_.assocob, _.contribob, _.nodev);
      // is the current contributor the added one? Then it should also have the same email
      if (!strcmp (curcontrib, name))
        {
          if (strcmp (curemail, email))
            FATAL_BM
              ("in %s line#%d contributor %s of oid %s and object %s has same name but different email %s",
               rcpath, lincnt, curcontrib, curoidstr,
               objectdbg_BM (_.contribob), curemail);
          _.newcontribob = _.contribob;
        }
      if (!strcmp (curemail, email))
        {
          FATAL_BM
            ("in %s line#%d contributor %s of oid %s and object %s has same email as added one %s",
             rcpath, lincnt, curcontrib, curoidstr,
             objectdbg_BM (_.contribob), curemail);
        }
      _.contribob = NULL;
      _.namev = NULL;
      _.emailv = NULL;
      _.aliasv = NULL;
      _.nodev = NULL;
    }                           /* end of reading loop */
  fflush (fil);
  // create and enter the new contributor, if unknown one
  if (!_.newcontribob)
    {
      _.newcontribob = makeobj_BM ();
      struct user_stBM *us =
        allocgcty_BM (typayl_user_BM, sizeof (struct user_stBM));
      us->user_ownobj = _.newcontribob;
      us->user_namev = makestring_BM (name);
      objputpayload_BM (_.newcontribob, us);
      objlock_BM (BMP_contributors);
      objhashsetaddpayl_BM (BMP_contributors, _.newcontribob);
      objputspacenum_BM (_.newcontribob, GlobalSp_BM);
      _.emailv = (value_tyBM) makestring_BM (email);
      _.aliasv = (alias
                  && alias[0]) ? (value_tyBM) makestring_BM (alias) : NULL;
      _.nodev =
        (value_tyBM) makenode2_BM (BMP_contributors, _.emailv, _.aliasv);
      objassocaddattrpayl_BM (_.assocob, _.newcontribob, _.nodev);
      objputclass_BM (_.newcontribob, k_contributor_class);
      objtouchnow_BM (_.newcontribob);
      DBGPRINTF_BM ("created new contributor %s for %s",
                    objectdbg_BM (_.newcontribob), name);
    }
  else
    knowncontrib = true;
  /// writing loop
  overwrite_contributor_file_BM (fil, _.assocob, CURFRAME_BM);
  fflush (fil);
  long filen = ftell (fil);
  ftruncate (fd, filen);
  usleep (100);
  if (flock (fd, LOCK_UN))
    FATAL_BM ("failed to un-flock fd#%d for %s", fd, rcpath);
  if (fclose (fil))
    FATAL_BM ("failed to fclose %s", rcpath);
  fil = NULL;
  fd = -1;
  ASSERT_BM (isobject_BM (_.newcontribob)
             && objhascontributorpayl_BM (_.newcontribob));
  {
    char idbuf[32];
    memset (idbuf, 0, sizeof (idbuf));
    idtocbuf32_BM (objid_BM (_.newcontribob), idbuf);
    if (knowncontrib)           // changed old contributor
      {
        if (alias && alias[0])
          INFOPRINTF_BM ("*** Changed contributor %s (of %d) with email %s "
                         "& alias %s registered thru object %s of id %s ***\n",
                         name, nbcontrib, email, alias,
                         objectdbg_BM (_.newcontribob), idbuf);
        else
          INFOPRINTF_BM ("*** Changed contributor %s (of %d) with email %s "
                         "registered thru object %s of id %s ***\n",
                         name, nbcontrib, email,
                         objectdbg_BM (_.newcontribob), idbuf);
      }
    else                        // added new fresh contributor
      {
        if (alias && alias[0])
          INFOPRINTF_BM ("*** Added contributor %s (of %d) with email %s"
                         " & alias %s registered thru object %s of id %s ***\n",
                         name, nbcontrib, email, alias,
                         objectdbg_BM (_.newcontribob), idbuf);
        else
          INFOPRINTF_BM ("*** Added contributor %s (of %d) with email %s"
                         " registered thru object %s of id %s ***\n",
                         name, nbcontrib, email,
                         objectdbg_BM (_.newcontribob), idbuf);
      }
  }
  LOCALRETURN_BM (_.newcontribob);
}                               /* end add_contributor_name_email_alias_BM */



objectval_tyBM *
add_contributor_user_BM (const char *str,
                         char **perrmsg, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  const char *namestr = NULL;
  const char *emailstr = NULL;
  const char *aliasstr = NULL;
  if (!str)
    return NULL;
  if (perrmsg)
    *perrmsg = NULL;
  DBGPRINTF_BM ("add_contributor_user_BM str='%s'", str);
  if (!str[0])
    {
      if (perrmsg)
        asprintf (perrmsg, "empty user string");
      return NULL;
    }
  const char *end = NULL;
  if (!g_utf8_validate (str, -1, &end) && end && *end)
    {
      if (perrmsg)
        asprintf (perrmsg, "invalid utf8 string %s", str);
      return false;
    }
  if (isspace (str[0]))
    {
      if (perrmsg)
        asprintf (perrmsg, "user string '%s' cannot start with a space", str);
      return NULL;
    }
  if (isdigit (str[0]) || str[0] == '_')
    {
      if (perrmsg)
        asprintf (perrmsg,
                  "user string '%s' cannot start with a digit or underscore\n",
                  str);
      return NULL;
    }
  for (const char *pc = str; *pc; pc++)
    if (*pc == '\n' || *pc == '\r' || *pc == '\t'
        || *pc == '\r' || *pc == '\v' || *pc == '\f'
        || (*pc != ' ' && (isspace (*pc) || iscntrl (*pc))))
      {
        if (perrmsg)
          asprintf (perrmsg,
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
      const char *namend = lt - 1;
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
                                             perrmsg, CURFRAME_BM);
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
      const char *namend = semcol1 - 1;
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
                                             aliasstr, perrmsg, CURFRAME_BM);
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
  if (perrmsg)
    asprintf (perrmsg,
              "invalid user string '%s',\n"
              "... expecting 'First Lastname <email@example.com>'\n"
              "... or 'First Lastname;email@example.com;aliasmail@example.org'\n",
              str);
  LOCALRETURN_BM (NULL);
}                               /* end add_contributor_user_BM */



objectval_tyBM *
remove_contributor_by_name_BM (const char *oldname,
                               struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * oldcontribob; //removed contributor object
                 objectval_tyBM * contribob;    //current contributor object 
                 objectval_tyBM * assocob;      // temporary assoc-object
                 value_tyBM namev;      // the name string
                 value_tyBM emailv;     // the email string value
                 value_tyBM aliasv;     // the alias string value
                 value_tyBM nodev;      // the node
                 value_tyBM keysetv;    // the set of keys
    );
  FILE *fil = fopen (CONTRIBUTORS_FILE_BM, "r+");
  if (!fil)
    {
      FATAL_BM ("cannot open contributors file %s : %m",
                CONTRIBUTORS_FILE_BM);
      LOCALRETURN_BM (NULL);
    }
  const char *rcpath = realpath (CONTRIBUTORS_FILE_BM, NULL);
  struct stat mystat = { };
  if (!rcpath)
    FATAL_BM ("cannot get real path of contributor file %s: %m",
              CONTRIBUTORS_FILE_BM);
  int fd = fileno (fil);
  memset (&mystat, 0, sizeof (mystat));
  if (fstat (fd, &mystat))
    FATAL_BM ("failed to fstat fd#%d for %s", fd, rcpath);
  // the file size gives a guess on the initial size of assocob
  _.assocob = makeobj_BM ();
  objputassocpayl_BM (_.assocob, prime_above_BM (mystat.st_size / 64 + 10));
  if (flock (fd, LOCK_EX))
    FATAL_BM ("failed to flock fd#%d for %s", fd, rcpath);
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  if (!linbuf)
    FATAL_BM
      ("remove_contributor_by_name_BM can't alloc line of %zd bytes", linsiz);
  /// reading loop
  for (;;)
    {
      _.contribob = NULL;
      _.namev = NULL;
      _.emailv = NULL;
      _.aliasv = NULL;
      _.nodev = NULL;
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in %s line#%d is invalid UTF8: %s",
                  rcpath, lincnt, linbuf);
      // linbuf should be like: <username>;<oid>;<email>;<alias>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      char *semcol3 = semcol2 ? strchr (semcol2 + 1, ';') : NULL;
      if (!semcol3)
        FATAL_BM
          ("in %s line#%d should be like <username>;<oid>;<email>;<alias> but is %s",
           rcpath, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      *semcol3 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curemail = semcol2 + 1;
      const char *curalias = semcol3 + 1;
      DBGPRINTF_BM
        ("remove_contributor_by_name_BM file %s line#%d curcontrib '%s' curoidstr '%s' curemail '%s' curalias '%s'",
         rcpath, lincnt, curcontrib, curoidstr, curemail, curalias);
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM ("in %s line#%d has invalid contributor name %s : %s",
                  rcpath, lincnt, curcontrib, errmsg);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM ("in %s line#%d has invalid oid %s for contributor %s",
                  rcpath, lincnt, curoidstr, curcontrib);
      if (!valid_email_BM (curemail, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid email %s for contributor %s : %s",
           rcpath, lincnt, curemail, curcontrib, errmsg);
      if (curalias[0] && !isspace (curalias[0])
          && !valid_email_BM (curalias, DONTCHECKDNS_BM, &errmsg))
        FATAL_BM
          ("in %s line#%d has invalid alias %s for contributor %s : %s",
           rcpath, lincnt, curalias, curcontrib, errmsg);
      _.contribob = findobjofid_BM (curid);
      if (!_.contribob)
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s is missing in persistent heap,"
           " so remove or comment out that line, then add that contributor after restarting",
           rcpath, lincnt, curcontrib, curoidstr);
      objlock_BM (_.contribob);
      if (!objhascontributorpayl_BM (_.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s is not a user-object",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      _.namev = (value_tyBM) objcontributornamepayl_BM (_.contribob);
      objunlock_BM (_.contribob);
      if (objassocgetattrpayl_BM (_.assocob, _.contribob))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s is duplicated",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (!isstring_BM (_.namev))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s has no user-name",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob));
      if (strcmp (bytstring_BM (_.namev), curcontrib))
        FATAL_BM
          ("in %s line#%d contributor %s of oid %s and object %s which has unexpected name %s",
           rcpath, lincnt, curcontrib, curoidstr, objectdbg_BM (_.contribob),
           bytstring_BM (_.namev));
      _.emailv = (value_tyBM) makestring_BM (curemail);
      _.aliasv = (curalias && curalias[0])      //
        ? (value_tyBM) makestring_BM (curalias) : NULL;
      _.nodev =
        (value_tyBM) makenode2_BM (BMP_contributors, _.emailv, _.aliasv);
      objassocaddattrpayl_BM (_.assocob, _.contribob, _.nodev);
      if (!strcmp (curcontrib, oldname))
        {
          ASSERT_BM (!_.oldcontribob);
          _.oldcontribob = _.contribob;
        }
    }                           /* end reading loop */
  if (!_.oldcontribob)
    FATAL_BM ("did not found old contributor %s in %s", oldname, rcpath);
  if (!objhashsetcontainspayl_BM (BMP_contributors, _.oldcontribob))
    FATAL_BM
      ("old contributor %s of object %s is not in `contributors` but in %s",
       oldname, objectdbg_BM (_.oldcontribob), rcpath);
  // clear payload and make the oldcontribob transient to remove it from future dumps
  {
    objlock_BM (_.oldcontribob);
    objclearpayload_BM (_.oldcontribob);
    objputspacenum_BM (_.oldcontribob, TransientSp_BM);
    objtouchnow_BM (_.oldcontribob);
    objunlock_BM (_.oldcontribob);
  }
  // remove from contributors hashset; it probably has already been
  // removed at clear payload above, but we need to be sure
  {
    objlock_BM (BMP_contributors);
    objhashsetremovepayl_BM (BMP_contributors, _.oldcontribob);
    objtouchnow_BM (BMP_contributors);
    objunlock_BM (BMP_contributors);
  }
  objassocremoveattrpayl_BM (_.assocob, _.oldcontribob);
  overwrite_contributor_file_BM (fil, _.assocob, CURFRAME_BM);
  fflush (fil);
  long filen = ftell (fil);
  ftruncate (fd, filen);
  usleep (100);
  if (flock (fd, LOCK_UN))
    FATAL_BM ("failed to un-flock fd#%d for %s", fd, rcpath);
  if (fclose (fil))
    FATAL_BM ("failed to fclose %s", rcpath);
  fil = NULL;
  fd = -1;
  DBGPRINTF_BM
    ("remove_contributor_by_name_BM oldname %s gives oldcontribob %s",
     oldname, objectdbg_BM (_.oldcontribob));
  LOCALRETURN_BM (_.oldcontribob);
}                               /* end remove_contributor_by_name_BM */





// payload delete support for user
void
userdelete_BM (objectval_tyBM * ownobj, struct user_stBM *us)
{
  ASSERT_BM (valtype_BM ((value_tyBM) us) == typayl_user_BM);
  ASSERT_BM (isobject_BM (ownobj));
  ASSERT_BM (!objpayload_BM (ownobj) || objpayload_BM (ownobj) == us);
  if (us->user_ownobj)
    {
      ASSERT_BM (us->user_ownobj == ownobj || !ownobj);
      objectval_tyBM *uownerob = us->user_ownobj;
      us->user_ownobj = NULL;
      objlock_BM (uownerob);
      if (objpayload_BM (uownerob) == (extendedval_tyBM) us)
        uownerob->ob_payl = NULL;
      objunlock_BM (uownerob);
    }
  bool wascontributor = false;
  {
    objlock_BM (BMP_contributors);
    if (!objhashashsetpayl_BM (BMP_contributors))
      FATAL_BM ("when deleting user %s, contributors has no hashset payload",
                objectdbg_BM (ownobj));
    if (objhashsetcontainspayl_BM (BMP_contributors, ownobj))
      {
        wascontributor = true;
        objhashsetremovepayl_BM (BMP_contributors, ownobj);
      }
    objunlock_BM (BMP_contributors);
  }
  if (!wascontributor)
    WARNPRINTF_BM ("deleted user %s was not in `contributors_BM`",
                   objectdbg_BM (ownobj));
}                               /* end userdelete_BM */



static void
compute_crypt_salt32_BM (char salt[32], objectval_tyBM * contribob)
{
  ASSERT_BM (salt != NULL);
  memset (salt, 0, 32);
  ASSERT_BM (isobject_BM (contribob) && objhascontributorpayl_BM (contribob));
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (contribob), idbuf);
  const stringval_tyBM *namstr = objcontributornamepayl_BM (contribob);
  ASSERT_BM (isstring_BM ((value_tyBM) namstr));
  hash_tyBM hnam = valhash_BM ((value_tyBM) namstr);
  ASSERT_BM (hnam > 0);
  snprintf (salt, 32, "$6$%.12s%04x", idbuf + 1, hnam & 0xffff);
}                               /* end compute_crypt_salt32_BM */


#define MINIMAL_PASSWORD_LEN_BM 10
bool
valid_password_BM (const char *passwd, char **perrmsg)
{
  if (!passwd)
    {
      if (perrmsg)
        asprintf (perrmsg, "nil password");
      return false;
    }
  if (strlen (passwd) < MINIMAL_PASSWORD_LEN_BM)
    {
      if (perrmsg)
        asprintf (perrmsg, "too short password, needs at least %d bytes",
                  MINIMAL_PASSWORD_LEN_BM);
      return false;
    }
  const char *end = NULL;
  if (!g_utf8_validate (passwd, -1, &end) && end && *end)
    {
      if (perrmsg)
        asprintf (perrmsg, "password is not valid UTF8 at byte offset %d",
                  (int) (end - passwd));
      return false;
    }
  int nbdigits = 0, nbalphas = 0, nbpunct = 0;
  int nbc = 0;
  for (const char *p = passwd; *p; p = g_utf8_next_char (p))
    {
      gunichar uc = g_utf8_get_char (p);
      if (!g_unichar_isprint (uc))
        {
          if (perrmsg)
            asprintf (perrmsg,
                      "password contain unprintable character of Unicode #%d",
                      uc);
          return false;
        }
      if (g_unichar_isalpha (uc))
        nbalphas++;
      else if (g_unichar_isdigit (uc))
        nbdigits++;
      else if (g_unichar_ispunct (uc))
        nbpunct++;
      else if (g_unichar_iszerowidth (uc))
        continue;
      nbc++;
    }
  if (nbc < MINIMAL_PASSWORD_LEN_BM)
    {
      if (perrmsg)
        asprintf (perrmsg, "password has less than %d characters",
                  MINIMAL_PASSWORD_LEN_BM);
      return false;
    }
  if (nbdigits == 0)
    {
      if (perrmsg)
        asprintf (perrmsg, "password has no digits");
      return false;
    }
  if (nbalphas == 0)
    {
      if (perrmsg)
        asprintf (perrmsg, "password has no letters");
      return false;
    }
  if (nbpunct == 0)
    {
      if (perrmsg)
        asprintf (perrmsg, "password has no punctuation");
      return false;
    }
  if (perrmsg)
    *perrmsg = NULL;
  return true;
}                               /* end valid_password_BM */

bool
check_contributor_password_BM (objectval_tyBM * contribobarg,
                               const char *passwd,
                               struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //current contributor object 
                 objectval_tyBM * curcontribob; //current contributor object 
    );
  FILE *passfil = NULL;
  bool ok = false;
#define REJECT() do { DBGPRINTF_BM("check_contributor_password_BM rejects contribob %s passwd '%s'", \
  objectdbg_BM(_.contribob), passwd); ok=false; goto end; } while(0)
  // to make life harder for external malicious stuff 
  usleep (1000 + g_random_int () % 1024);
  _.contribob = objectcast_BM (contribobarg);
  if (!_.contribob)
    REJECT ();
  if (!passwd || !valid_password_BM (passwd, NULL))
    REJECT ();
  if (!objhascontributorpayl_BM (_.contribob))
    REJECT ();
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (_.contribob), idbuf);
  DBGPRINTF_BM
    ("check_contributor_password contribob %s / %s passwd '%s' start",
     objectdbg_BM (_.contribob), idbuf, passwd);
  bool knowncontrib = false;
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  if (!linbuf)
    FATAL_BM ("check_contributor_file can't alloc line of %zd bytes", linsiz);
  {
    objlock_BM (BMP_contributors);
    knowncontrib = objhashsetcontainspayl_BM (BMP_contributors, _.contribob);
    objunlock_BM (BMP_contributors);
  }
  if (!knowncontrib)
    REJECT ();
  passfil = fopen (passwords_filepath_BM, "r");
  if (!passfil)
    FATAL_BM ("check_contributor_password fopen %s failed: %m",
              passwords_filepath_BM);
  if (flock (fileno (passfil), LOCK_EX))
    FATAL_BM ("check_contributor_password failed to flock fd#%d for %s",
              fileno (passfil), passwords_filepath_BM);
  if (!linbuf)
    FATAL_BM ("check_contributor_password failed to calloc line of %zd",
              linsiz);
  /// read password file loop
  int lincnt = 0;
  for (;;)
    {
      ssize_t linlen = getline (&linbuf, &linsiz, passfil);
      if (linlen <= 0)
        break;
      if (linbuf[linlen - 1] == '\n')
        linbuf[linlen - 1] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in password file %s line#%d is invalid UTF8: %s",
                  passwords_filepath_BM, lincnt, linbuf);
      // linbuf should be like: <contribname>;<oid>;<encrypted-password>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      if (!semcol2)
        FATAL_BM ("in password file %s line#%d should be like"
                  " <contributor-name>;<oid>;<encrypted-password> but is %s",
                  passwords_filepath_BM, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curcryptpass = semcol2 + 1;
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM ("in password file %s line#%d has"
                  " invalid contributor name %s : %s",
                  passwords_filepath_BM, lincnt, curcontrib, errmsg);
      DBGPRINTF_BM ("check_contributor_file lin#%d"
                    " curcontrib '%s' curoidstr '%s' curcryptpass '%s'",
                    lincnt, curcontrib, curoidstr, curcryptpass);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM
          ("in password file %s line#%d has"
           " invalid oid %s for contributor %s",
           passwords_filepath_BM, lincnt, curoidstr, curcontrib);
      _.curcontribob = findobjofid_BM (curid);
      if (!_.curcontribob)
        continue;
      if (!objhascontributorpayl_BM (_.curcontribob))
        continue;
      const char *contrinam =
        bytstring_BM (objcontributornamepayl_BM (_.curcontribob));
      if (!contrinam)
        FATAL_BM ("in password file %s line#%d corrupted"
                  " contributor %s of oid %s",
                  passwords_filepath_BM, lincnt, curcontrib, curoidstr);
      if (strcmp (contrinam, curcontrib))
        FATAL_BM ("in password file %s line#%d contributor %s"
                  " of oid %s is expected to be %s",
                  passwords_filepath_BM, lincnt, curcontrib, curoidstr,
                  contrinam);
      // read carefully crypt(3), that is http://man7.org/linux/man-pages/man3/crypt.3.html
      // we want to use SHA-512, so "$6$" prefix
      if (strncmp ("$6$", curcryptpass, 3))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s with corrupted crypted password",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr);
      if (_.curcontribob != _.contribob)
        continue;
      char encrypassbuf[128];
      memset (encrypassbuf, 0, sizeof (encrypassbuf));
      {
        char salt[32];
        // crypt_data is quite big, more than 128Kbytes. So it cannot fit on the callstack.
        struct crypt_data *crydat = calloc (sizeof (struct crypt_data), 1);
        if (!crydat)
          FATAL_BM ("calloc failed for crypt_data");
        memset (salt, 0, sizeof (salt));
        compute_crypt_salt32_BM (salt, _.contribob);
        crydat->initialized = 0;
        char *cryp = crypt_r (passwd, salt, crydat);
        if (cryp)
          strncpy (encrypassbuf, cryp, sizeof (encrypassbuf) - 8);
        memset (crydat, 0, sizeof (struct crypt_data));
        // the test below is always false, but we need the compiler to
        // emit it. We don't want crypting secrets to leak!
        if (((char *) crydat)[g_random_int () % sizeof (struct crypt_data)] !=
            0)
          FATAL_BM ("corruption in password crypting");
        free (crydat), crydat = NULL;
      }
      DBGPRINTF_BM
        ("for contributor %s encrypassbuf '%s' curcryptpass '%s' passwd '%s'",
         objectdbg_BM (_.contribob), encrypassbuf, curcryptpass, passwd);
      if (strcmp (encrypassbuf, curcryptpass))
        REJECT ();
      else
        {
          ok = true;
          break;
        }
    }                           /* end readloop */
end:
#undef REJECT
  if (linbuf)
    free (linbuf), linbuf = NULL;
  if (passfil)
    {
      if (flock (fileno (passfil), LOCK_UN))
        FATAL_BM ("failed to un-flock fd#%d for %s", fileno (passfil),
                  passwords_filepath_BM);
      if (fclose (passfil))
        FATAL_BM ("failed to fclose %s", passwords_filepath_BM);
      passfil = NULL;
    }
  // sleep some random delay, to make this call a bit costly...
  usleep (100 + g_random_int () % 2048);
  return ok;
}                               /* end check_contributor_password_BM */


static void read_password_file_BM (FILE * passfil, objectval_tyBM * assocob,
                                   struct stackframe_stBM *stkf);

static pthread_mutex_t passwd_mutex_bm = PTHREAD_MUTEX_INITIALIZER;
bool
put_contributor_password_BM (objectval_tyBM * contribobarg,
                             const char *passwd, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * contribob;    //given contributor object 
                 objectval_tyBM * curcontribob; //current contributor object
                 objectval_tyBM * assocob;      //
                 value_tyBM keysetv;    //
                 value_tyBM curpasstrv; //
                 value_tyBM curnamev;
    );
  FILE *passfil = NULL;
  bool ok = false;
  static long putcount;
#define REJECT() do { DBGPRINTF_BM("put_contributor_password_BM rejects contribob %s passwd '%s'", \
  objectdbg_BM(_.contribob), passwd); ok=false; goto end; } while(0)
  // to make life harder for external malicious stuff 
  usleep (1000 + g_random_int () % 1024);
  _.contribob = objectcast_BM (contribobarg);
  pthread_mutex_lock (&passwd_mutex_bm);
  if (!_.contribob)
    REJECT ();
  if (!passwd || !passwd[0] || !valid_password_BM (passwd, NULL))
    REJECT ();
  if (!objhascontributorpayl_BM (_.contribob))
    REJECT ();
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (_.contribob), idbuf);
  DBGPRINTF_BM
    ("put_contributor_password_BM contribob %s / %s passwd '%s' start password file %s",
     objectdbg_BM (_.contribob), idbuf, passwd, passwords_filepath_BM);
  bool knowncontrib = false;
  {
    objlock_BM (BMP_contributors);
    knowncontrib = objhashsetcontainspayl_BM (BMP_contributors, _.contribob);
    objunlock_BM (BMP_contributors);
  }
  if (!knowncontrib)
    REJECT ();
  passfil = fopen (passwords_filepath_BM, "r+");
  if (!passfil)
    FATAL_BM ("put_contributor_password fopen %s failed: %m",
              passwords_filepath_BM);
  if (flock (fileno (passfil), LOCK_EX))
    FATAL_BM ("put_contributor_password failed to flock fd#%d for %s",
              fileno (passfil), passwords_filepath_BM);
  struct stat passwstat;
  memset (&passwstat, 0, sizeof (passwstat));
  {
    if (fstat (fileno (passfil), &passwstat))
      FATAL_BM ("failed to fstat password file %s fd#%d",
                passwords_filepath_BM, fileno (passfil));
    _.assocob = makeobj_BM ();
    objputassocpayl_BM (_.assocob,
                        prime_above_BM (passwstat.st_size / 64 + 10));
  }
  objtouchnow_BM (_.assocob);
  read_password_file_BM (passfil, _.assocob, CURFRAME_BM);
  /// we first should do some backup copy, and we should do it once in
  /// the whole process
  if (putcount++ == 0)
    {                           // first call in this process, so backup the password file
      size_t linsiz = 128;
      char *linbuf = calloc (linsiz, 1);
      if (!linbuf)
        FATAL_BM
          ("put_contributor_password_BM can't alloc line of %zd bytes",
           linsiz);
      char *backupath = NULL;
      if (asprintf (&backupath, "%s~", passwords_filepath_BM) < 0
          || !backupath)
        FATAL_BM ("failed to get backup path for passwords file %s",
                  passwords_filepath_BM);
      DBGPRINTF_BM
        ("put_contributor_password_BM backup password file %s -> %s",
         passwords_filepath_BM, backupath);
      FILE *backfil = fopen (backupath, "w");
      if (!backfil)
        FATAL_BM ("failed to fopen backup %s for passwords file - %m",
                  backupath);
      rewind (passfil);
      if (fchmod (fileno (backfil), 0600))
        FATAL_BM ("failed to fchmod backup file %s - %m", backupath);
      for (;;)
        {
          ssize_t linlen = getline (&linbuf, &linsiz, passfil);
          if (linlen < 0)
            break;
          if (linbuf[linlen] == '\n')
            linbuf[linlen] = (char) 0;
          fputs (linbuf, backfil);
          if (fputc ('\n', backfil) < 0)
            FATAL_BM ("failed to write passwords backup %s - %m", backupath);
        }
      if (fclose (backfil))
        FATAL_BM ("failed to fclose passwords backup %s - %m", backupath);
      backfil = NULL;
      struct utimbuf backtb;
      memset (&backtb, 0, sizeof (backtb));
      time (&backtb.actime);
      backtb.modtime = passwstat.st_mtime;
      utime (backupath, &backtb);
      free (linbuf), linbuf = NULL;
    }
  char encrypassbuf[128];
  memset (encrypassbuf, 0, sizeof (encrypassbuf));
  {
    char salt[32];
    // crypt_data is quite big, more than 128Kbytes. So it cannot fit on the callstack.
    struct crypt_data *crydat = calloc (sizeof (struct crypt_data), 1);
    if (!crydat)
      FATAL_BM ("calloc failed for crypt_data");
    memset (salt, 0, sizeof (salt));
    compute_crypt_salt32_BM (salt, _.contribob);
    crydat->initialized = 0;
    char *cryp = crypt_r (passwd, salt, crydat);
    if (cryp)
      strncpy (encrypassbuf, cryp, sizeof (encrypassbuf) - 8);
    memset (crydat, 0, sizeof (struct crypt_data));
    // the test below is always false, but we need the compiler to
    // emit it.  We don't want crypting secrets to leak, even with very
    // optimizing compilers!
    if (((char *) crydat)[g_random_int () % sizeof (struct crypt_data)] != 0)
      FATAL_BM ("corruption in password crypting");
    free (crydat), crydat = NULL;
  }
  _.curpasstrv = (value_tyBM) makestring_BM (encrypassbuf);
  objassocaddattrpayl_BM (_.assocob, _.contribob, _.curpasstrv);
  /// rewrite loop of password
  rewind (passfil);
  write_password_file_BM (passfil, _.assocob, CURFRAME_BM);
  ok = true;
  DBGPRINTF_BM ("put_contributor_password ok for contrib %s",
                objectdbg_BM (_.contribob));
end:
#undef REJECT
  objclearpayload_BM (_.assocob);
  objputclass_BM (_.assocob, BMP_object);
  objtouchnow_BM (_.assocob);
  if (passfil)
    {
      if (flock (fileno (passfil), LOCK_UN))
        FATAL_BM ("failed to un-flock fd#%d for %s", fileno (passfil),
                  passwords_filepath_BM);
      if (fclose (passfil))
        FATAL_BM ("failed to fclose %s", passwords_filepath_BM);
      passfil = NULL;
    }
  usleep (100);
  pthread_mutex_unlock (&passwd_mutex_bm);
  // sleep some random delay, to make this call a bit costly...
  usleep (100 + g_random_int () % 2048);
  return ok;
}                               /* end put_contributor_password_BM */


void
read_password_file_BM (FILE * passfil, objectval_tyBM * assocobarg,
                       struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * curcontribob; //current contributor object
                 objectval_tyBM * assocob;      //
                 value_tyBM keysetv;    //
                 value_tyBM curpasstrv; //
                 value_tyBM curnamev;
    );
  _.assocob = assocobarg;
  ASSERT_BM (isobject_BM (_.assocob));
  ASSERT_BM (objhasassocpayl_BM (_.assocob));
  size_t linsiz = 128;
  char *linbuf = calloc (linsiz, 1);
  int lincnt = 0;
  if (!linbuf)
    FATAL_BM ("read_password_file_BM failed to calloc line of %zd", linsiz);
  /// read password file loop
  for (;;)
    {
      ssize_t linlen = getline (&linbuf, &linsiz, passfil);
      if (linlen < 0)
        break;
      if (linbuf[linlen] == '\n')
        linbuf[linlen] = (char) 0;
      lincnt++;
      if (linbuf[0] == '#' || linbuf[0] == '\n' || !linbuf[0])
        continue;
      const char *end = NULL;
      if (!g_utf8_validate (linbuf, -1, &end) && end && *end)
        FATAL_BM ("in password file %s line#%d is invalid UTF8: %s",
                  passwords_filepath_BM, lincnt, linbuf);
      // linbuf should be like: <contribname>;<oid>;<encrypted-password>
      char *semcol1 = strchr (linbuf, ';');
      char *semcol2 = semcol1 ? strchr (semcol1 + 1, ';') : NULL;
      if (!semcol2)
        FATAL_BM
          ("in password file %s line#%d should be like <contributor-name>;<oid>;<encrypted-password> but is %s",
           passwords_filepath_BM, lincnt, linbuf);
      *semcol1 = (char) 0;
      *semcol2 = (char) 0;
      const char *curcontrib = linbuf;
      const char *curoidstr = semcol1 + 1;
      const char *curcryptpass = semcol2 + 1;
      char *errmsg = NULL;
      if (!valid_contributor_name_BM (curcontrib, &errmsg))
        FATAL_BM
          ("in password file %s line#%d has invalid contributor name %s : %s",
           passwords_filepath_BM, lincnt, curcontrib, errmsg);
      const char *endid = NULL;
      rawid_tyBM curid = parse_rawid_BM (curoidstr, &endid);
      if (!endid || *endid || !curid.id_hi || !curid.id_lo)
        FATAL_BM
          ("in password file %s line#%d has invalid oid %s for contributor %s",
           passwords_filepath_BM, lincnt, curoidstr, curcontrib);
      _.curcontribob = findobjofid_BM (curid);
      if (!_.curcontribob)
        continue;
      if (!objhascontributorpayl_BM (_.curcontribob))
        continue;
      {
        bool knowncontrib = false;
        objlock_BM (BMP_contributors);
        knowncontrib =
          objhashsetcontainspayl_BM (BMP_contributors, _.curcontribob);
        objunlock_BM (BMP_contributors);
        if (!knowncontrib)
          continue;
      }
      if (objassocgetattrpayl_BM (_.assocob, _.curcontribob))
        FATAL_BM
          ("in password file %s line#%d duplicate contributor %s of oid %s",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr);
      const char *contrinam =
        bytstring_BM (objcontributornamepayl_BM (_.curcontribob));
      if (!contrinam)
        FATAL_BM
          ("in password file %s line#%d corrupted contributor %s of oid %s",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr);
      if (strcmp (contrinam, curcontrib))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s is expected to be %s",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr, contrinam);
      // read carefully crypt(3), that is http://man7.org/linux/man-pages/man3/crypt.3.html
      // we want to use SHA-512, so "$6$" prefix
      if (strncmp ("$6$", curcryptpass, 3))
        FATAL_BM
          ("in password file %s line#%d contributor %s of oid %s with corrupted crypted password %.6s...",
           passwords_filepath_BM, lincnt, curcontrib, curoidstr, curcryptpass);
      objassocaddattrpayl_BM (_.assocob, _.curcontribob,
                              (value_tyBM) makestring_BM (curcryptpass));
    }                           /* end readloop */
}                               /* end read_password_file_BM */


////////////////
void
write_password_file_BM (FILE * passfil, objectval_tyBM * assocobarg,
                        struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * curcontribob; //current contributor object
                 objectval_tyBM * assocob;      //
                 value_tyBM keysetv;    //
                 value_tyBM curpasstrv; //
                 value_tyBM curnamev;
    );
  _.assocob = assocobarg;
  ASSERT_BM (isobject_BM (_.assocob));
  ASSERT_BM (objhasassocpayl_BM (_.assocob));
  DBGPRINTF_BM ("write_password_file start assocob %s",
                objectdbg_BM (_.assocob));
  rewind (passfil);
  char nowtimbuf[80];
  memset (nowtimbuf, 0, sizeof (nowtimbuf));
  time_t nowt = 0;
  time (&nowt);
  struct tm nowtm = { };
  memset (&nowtm, 0, sizeof (nowtm));
  localtime_r (&nowt, &nowtm);
  strftime (nowtimbuf, sizeof (nowtimbuf), "%c", &nowtm);
  char *baspath = basename (passwords_filepath_BM);
  int nbpasswords = objassocnbkeyspayl_BM (_.assocob);
  if (strcmp (baspath, PASSWORDS_FILE_BM))
    fprintf (passfil, "## BISMON passwords file %s (really %s)\n",
             PASSWORDS_FILE_BM, passwords_filepath_BM);
  else
    fprintf (passfil, "## BISMON passwords file %s\n", PASSWORDS_FILE_BM);
  fprintf (passfil,
           "## when BISMON is running, don't edit manually this file; it could be flock-ed.\n");
  fprintf (passfil, "###############################################\n");
  fprintf (passfil, "## written by BISMON built at %s\n", bismon_timestamp);
  fprintf (passfil, "## BISMON lastgitcommit %s\n", bismon_lastgitcommit);
  fprintf (passfil, "## BISMON checksum %s\n", bismon_checksum);
  fprintf (passfil, "##- emitted at %s on %s for %d passwords.\n",
           nowtimbuf, myhostname_BM, nbpasswords);
  fprintf (passfil,
           "## passwords are encrypted, see http://man7.org/linux/man-pages/man3/crypt.3.html\n");
  fprintf (passfil,
           "## format: one password line per contributor or user like:\n"
           "## <username>;<oid>;<encrypted-password>\n");
  _.keysetv = (value_tyBM) objassocsetattrspayl_BM (_.assocob);
  ASSERT_BM (isset_BM (_.keysetv)
             && (int) setcardinal_BM (_.keysetv) == nbpasswords);
  for (unsigned pix = 0; pix < (unsigned) nbpasswords; pix++)
    {
      _.curcontribob = setelemnth_BM (_.keysetv, pix);
      ASSERT_BM (isobject_BM (_.curcontribob));
      ASSERT_BM (objhascontributorpayl_BM (_.curcontribob));
      _.curpasstrv = objassocgetattrpayl_BM (_.assocob, _.curcontribob);
      ASSERT_BM (isstring_BM (_.curpasstrv));
      _.curnamev = (value_tyBM) objcontributornamepayl_BM (_.curcontribob);
      ASSERT_BM (isstring_BM (_.curnamev));
      DBGPRINTF_BM ("write_password_file pix#%d curcontribob %s curpasstr %s"
                    " curname %s",
                    pix, objectdbg_BM (_.curcontribob),
                    debug_outstr_value_BM (_.curpasstrv, CURFRAME_BM, 0),
                    debug_outstr_value_BM (_.curnamev, CURFRAME_BM, 0));
      char contridbuf[32];
      memset (contridbuf, 0, sizeof (contridbuf));
      idtocbuf32_BM (objid_BM (_.curcontribob), contridbuf);
      fprintf (passfil, "%s;%s;%s\n", bytstring_BM (_.curnamev), contridbuf,
               bytstring_BM (_.curpasstrv));
    }
  fprintf (passfil, "# end of BISMON password files for %d passwords\n",
           nbpasswords);
  if (fflush (passfil))
    FATAL_BM ("failed to fflush password file %s", passwords_filepath_BM);
  long ln = ftell (passfil);
  ftruncate (fileno (passfil), ln);
  DBGPRINTF_BM ("write_password_file end ln %ld", ln);
}                               /* end write_password_file_BM */

/// end of file user_BM.c
