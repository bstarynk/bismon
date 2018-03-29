// file guicode_BM.c

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
***/
#include "bismon.h"
#include "guicode_BM.const.h"


/// method to browse_in_object for object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d);
value_tyBM
ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the depth
 const value_tyBM arg3 __attribute__ ((unused)),        //
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  ASSERT_BM (isobject_BM (arg1));
  ASSERT_BM (istaggedint_BM (arg2));
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const setval_tyBM * setattrs; const objectval_tyBM * curattr;
                 value_tyBM curval;);
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  char objbroid[32];
  memset (objbroid, 0, sizeof (objbroid));
  idtocbuf32_BM (objid_BM (_.objbrows), objbroid);
  const char *objbroname = findobjectname_BM (_.objbrows);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                    "|", -1, miscomm_brotag_BM, NULL);
  if (objbroname)
    {
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                        objbroname, -1, objname_brotag_BM,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, " = ", -1,
                                        miscomm_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                    objbroid, -1, objid_brotag_BM,
                                    objrefcomm_brotag_BM, NULL);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, "\n ", -1,
                                    miscomm_brotag_BM, NULL);
  ///
  //// show hi&lo id and hash
  Dl_info di = { };
  if (_.objbrows->ob_rout
      && dladdr (_.objbrows->ob_rout, &di) && di.dli_fname && di.dli_sname)
    {
      char *commbuf = NULL;
      asprintf (&commbuf,
                "id:%lld,%lld; h:%d\n ... µ%s;%s @%p|",
                (long long) _.objbrows->ob_id.id_hi,
                (long long) _.objbrows->ob_id.id_lo,
                objecthash_BM (_.objbrows),
                di.dli_fname, di.dli_sname, (void *) _.objbrows->ob_rout);
      if (!commbuf)
        FATAL_BM ("asprintf failure in browse_in_object]object");

      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                        commbuf, -1, miscomm_brotag_BM, NULL);
      free (commbuf), commbuf = NULL;
    }
  else
    {
      char idcomm[128];
      memset (idcomm, 0, sizeof (idcomm));
      snprintf (idcomm, sizeof (idcomm), "id:%lld,%lld; h:%d|",
                (long long) _.objbrows->ob_id.id_hi,
                (long long) _.objbrows->ob_id.id_lo,
                objecthash_BM (_.objbrows));
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                        idcomm, -1, miscomm_brotag_BM, NULL);
    }
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  ///
  //// show mtime & space
  {
    char mbuf[64];
    double mtime = _.objbrows->ob_mtime;
    snprintf (mbuf, sizeof (mbuf), "!@ %.2f ", mtime);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, mbuf, -1, NULL, NULL);
    double now = clocktime_BM (CLOCK_REALTIME);
    time_t mtimt = (time_t) mtime;
    struct tm mtimtm = {
    };
    localtime_r (&mtimt, &mtimtm);
    char commbuf[96];
    memset (commbuf, 0, sizeof (commbuf));
    char spabuf[16];
    memset (spabuf, 0, sizeof (spabuf));
    switch (_.objbrows->ob_space)
      {
      case TransientSp_BM:
        strcpy (spabuf, "transient");
        break;
      case PredefSp_BM:
        strcpy (spabuf, "predefined");
        break;
      case GlobalSp_BM:
        strcpy (spabuf, "global");
        break;
      default:
        snprintf (spabuf, sizeof (spabuf), "user#%d", _.objbrows->ob_space);
        break;
      };
    if (mtime < now && mtime + 1.0e6 > now)     // a million second is about 11 days
      strftime (mbuf, sizeof (mbuf), "%a %d, %T %Z", &mtimtm);
    else if (mtime < now && mtime + 25e6 > now) // 25 million seconds is less than 10 months
      strftime (mbuf, sizeof (mbuf), "%a %d %b, %T %Z", &mtimtm);
    else
      strftime (mbuf, sizeof (mbuf), "%c", &mtimtm);
    snprintf (commbuf, sizeof (commbuf), "|mtim:%s space:%s|", mbuf, spabuf);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    if (_.objbrows->ob_class)
      {
        gtk_text_buffer_insert (brobuf, &browserit_BM, "!$ ", -1);
        browse_value_BM ((const value_tyBM) _.objbrows->ob_class,
                         (struct stackframe_stBM *) &_, 2, 0);
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      };
  }
  ///
  //// show attributes
  {
    char commbuf[64];
    memset (commbuf, 0, sizeof (commbuf));
    _.setattrs = objsetattrs_BM (_.objbrows);
    unsigned nbattrs = setcardinal_BM (_.setattrs);
    snprintf (commbuf, sizeof (commbuf), "|%d attributes:|", nbattrs);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    objectval_tyBM *tinyarr[TINYSIZE_BM] = {
    };
    objectval_tyBM **arr = (nbattrs < TINYSIZE_BM) ? tinyarr    //
      : calloc (prime_above_BM (nbattrs),
                sizeof (const objectval_tyBM *));
    if (!arr)
      FATAL_BM ("failed to calloc arr for %d attrs", nbattrs);
    for (unsigned ix = 0; ix < nbattrs; ix++)
      arr[ix] = setelemnth_BM (_.setattrs, ix);
    sortnamedobjarr_BM (arr, nbattrs);
    for (unsigned aix = 0; aix < nbattrs; aix++)
      {
        _.curattr = arr[aix];
        _.curval = objgetattr_BM (_.objbrows, _.curattr);
        gtk_text_buffer_insert (brobuf, &browserit_BM, "!: ", -1);
        browse_value_BM ((const value_tyBM) _.curattr,
                         (struct stackframe_stBM *) &_, maxdepth, 2);
        browsespacefordepth_BM (1);
        browse_value_BM ((const value_tyBM) _.curval,
                         (struct stackframe_stBM *) &_, maxdepth, 1);
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      };
    if (arr != tinyarr)
      free (arr), arr = NULL;
  }
  ///
  //// show the components
  {
    char commbuf[64];
    memset (commbuf, 0, sizeof (commbuf));
    unsigned nbcomps = objnbcomps_BM (_.objbrows);
    snprintf (commbuf, sizeof (commbuf), "|%d components:|", nbcomps);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    for (unsigned cix = 0; cix < nbcomps; cix++)
      {
        gtk_text_buffer_insert (brobuf, &browserit_BM, "!& ", -1);
        snprintf (commbuf, sizeof (commbuf), "|#%d:|", cix);
        gtk_text_buffer_insert_with_tags (brobuf,
                                          &browserit_BM, commbuf, -1,
                                          miscomm_brotag_BM, NULL);
        _.curval = objgetcomp_BM (_.objbrows, cix);
        browsespacefordepth_BM (1);
        browse_value_BM ((const value_tyBM) _.curval,
                         (struct stackframe_stBM *) &_, maxdepth, 1);
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      }
  }
  ///
  // extra data
  extendedval_tyBM payl = objpayload_BM (_.objbrows);
  if (payl)
    {
      send1_BM ((const value_tyBM) _.objbrows, BMP_browse_data,
                (struct stackframe_stBM *) &_, taggedint_BM (maxdepth));
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  /// return itself
  LOCALRETURN_BM (_.objbrows);
}                               /* end  ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d) */





/// method to browse_value for object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe);
value_tyBM
ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_value for object-s _0BAnB0xjs23_0WEOCOi5Nbe");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;);
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  ASSERT_BM (maxdepth > 0);
  int curdepth = getint_BM (arg3);
  //  ASSERT_BM (curdepth <= maxdepth);
  const char *objnam = findobjectname_BM (_.objbrows);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (_.objbrows), idbuf);
  if (objnam)
    {
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        objnam, -1, objname_brotag_BM, NULL);
      if (curdepth < 2)
        {
          gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                            " |=", -1, objrefcomm_brotag_BM,
                                            NULL);
          gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                            idbuf,
                                            -1, objrefcomm_brotag_BM, NULL);
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|", -1,
                                            objrefcomm_brotag_BM, NULL);
        }
    }
  else
    {                           // anonymous
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        idbuf, -1, objid_brotag_BM, NULL);
    }
  LOCALRETURN_BM (_.objbrows);
}                               /* end  ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe) */


/// method to browse_data for class-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA);
value_tyBM
ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__ ((unused)),        //
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows; const setval_tyBM * setsel;   //
                 const objectval_tyBM * cursel;
                 const objectval_tyBM * supercla;
                 value_tyBM curval;);
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for class-s _09DxyieS5Wz_7pkad4F88FA");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.objbrows));
  ASSERT_BM (objhasclassinfo_BM (_.objbrows));
  _.setsel = objgetclassinfosetofselectors_BM (_.objbrows);
  _.supercla = objgetclassinfosuperclass_BM (_.objbrows);
  unsigned nbmeth = setcardinal_BM (_.setsel);
  objectval_tyBM *tinyarr[TINYSIZE_BM] = {
  };
  objectval_tyBM **arr = (nbmeth < TINYSIZE_BM) ? tinyarr       //
    : calloc (prime_above_BM (nbmeth),
              sizeof (const objectval_tyBM *));
  if (!arr)
    FATAL_BM ("failed to calloc arr for %d methods", nbmeth);
  for (unsigned ix = 0; ix < nbmeth; ix++)
    arr[ix] = setelemnth_BM (_.setsel, ix);
  sortnamedobjarr_BM (arr, nbmeth);
  gtk_text_buffer_insert_with_tags (brobuf,
                                    &browserit_BM,
                                    "!~ class (~ ", -1, NULL, NULL);
  if (_.supercla)
    {
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM,
                                        "|superclass=|", -1,
                                        miscomm_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.supercla,
                       (struct stackframe_stBM *) &_, 2, 0);
    }
  else
    {
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM,
                                        "|nosuperclass|", -1,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, " __\n", -1,
                                        NULL, NULL);
    }
  for (unsigned ix = 0; ix < nbmeth; ix++)
    {
      _.cursel = arr[ix];
      _.curval = (value_tyBM) objgetclassinfomethod_BM (_.objbrows, _.cursel);
      browsenewlinefordepth_BM (1);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, "~: ", -1, NULL, NULL);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM,
                                        "|selector:|", -1,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, " ", -1, NULL, NULL);
      browse_value_BM ((const value_tyBM) _.cursel,
                       (struct stackframe_stBM *) &_, 2, 1);
      browsespacefordepth_BM (1);
      browse_value_BM ((const value_tyBM) _.curval,
                       (struct stackframe_stBM *) &_, depth, 1);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, "\n", -1, NULL, NULL);
    }
  if (arr != tinyarr)
    free (arr), arr = NULL;
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, "~)\n", -1,
                                    NULL, NULL);
  LOCALRETURN_BM (_.objbrows);
}                               /* end ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA) */


/// method to browse_value for tuple-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt);
value_tyBM
ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4_ __attribute__ ((unused)),
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  if (!istuple_BM (arg1))
    FATAL_BM
      ("non-tuple for  method to browse_value for tuple-s _0BAnB0xjs23_0WEOCOi5Nb");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const tupleval_tyBM * tupbrows;
                 const objectval_tyBM * objbrows;);
  _.tupbrows = (const tupleval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  int oboff = browse_show_start_offset_BM ();
  ASSERT_BM (curdepth <= maxdepth);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "[", -1, nest_brotag_BM, NULL);
  unsigned tupsiz = tuplesize_BM (_.tupbrows);
  if (curdepth < maxdepth)
    {
      for (unsigned tix = 0; tix < tupsiz; tix++)
        {
          _.objbrows = tuplecompnth_BM (_.tupbrows, tix);
          if (tix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.objbrows,
                           (struct stackframe_stBM *) &_,
                           (maxdepth), (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d objects in tuple|", tupsiz);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "]", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth,
                        (struct stackframe_stBM *) &_);
  LOCALRETURN_BM (_.objbrows);
}                               /* end ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nb)  */





/// method to browse_value for set-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr);
value_tyBM
ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),        // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!isset_BM (arg1))
    FATAL_BM
      ("non-set for  method to browse_value for set-s _3rne4qbpnV9_0pywzeJp3Qr");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const setval_tyBM * setbrows;
                 const objectval_tyBM * objbrows;);
  _.setbrows = (const setval_tyBM *) arg1;
  unsigned setcard = setcardinal_BM (_.setbrows);
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  ASSERT_BM (curdepth <= maxdepth);
  int oboff = browse_show_start_offset_BM ();
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "{", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      objectval_tyBM *tinyarr[TINYSIZE_BM] = {
      };
      objectval_tyBM **arr =    //
        (setcard < TINYSIZE_BM) ? tinyarr
        : calloc (setcard + 1, sizeof (const objectval_tyBM *));
      if (!arr)
        FATAL_BM ("calloc failed for %d elements", setcard);
      for (unsigned eix = 0; eix < setcard; eix++)
        arr[eix] = setelemnth_BM (_.setbrows, eix);
      sortnamedobjarr_BM (arr, setcard);
      for (unsigned eix = 0; eix < setcard; eix++)
        {
          _.objbrows = arr[eix];
          if (eix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.objbrows,
                           (struct stackframe_stBM *) &_,
                           (maxdepth), (curdepth + 1));
        }
      if (arr != tinyarr)
        free (arr), arr = NULL;
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d objects in set|", setcard);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "}", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth,
                        (struct stackframe_stBM *) &_);
  LOCALRETURN_BM (_.objbrows);
}                               /* end ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr)  */





/// method to browse_value for int-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y);
value_tyBM
ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!istaggedint_BM (arg1))
    FATAL_BM
      ("non-int for method to browse_value for int-s _0HBMCM5CeLn_7L5YEV2jO7Y");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
    );
  intptr_t i = getint_BM (arg1);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  char ibuf[32];
  memset (ibuf, 0, sizeof (ibuf));
  snprintf (ibuf, sizeof (ibuf), "%lld", (long long) i);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    ibuf, -1, num_brotag_BM, NULL);
  LOCALRETURN_BM (arg1);
}                               /* end ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)  */



/// method to browse_value for string-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud);
#define WANTEDLINEWIDTH_BM 64
value_tyBM
ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!isstring_BM (arg1))
    FATAL_BM
      ("non-string for method to browse_value for string-s _63ZPkXUI2Uv_6Cp3qmh6Uud");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * strbrows;);
  _.strbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  ASSERT_BM (curdepth <= maxdepth);
  unsigned l = lenstring_BM (_.strbrows);
  const char *str = bytstring_BM (_.strbrows);
  if (l >= WANTEDLINEWIDTH_BM / 2)
    browsespacefordepth_BM (curdepth);
  int oboff = browse_show_start_offset_BM ();
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "\"", -1, stresc_brotag_BM, NULL);
  int ccnt = 0;
  int linecnt = 0;
#define WANTEDLINEWIDTH_BM 64
  for (const char *pc = str; *pc; pc = g_utf8_next_char (pc))
    {
      gunichar uc = g_utf8_get_char (pc);
      ccnt++;
      linecnt++;
#define ADDESCAPESTR_BM(S)						\
    gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,	\
				      (S), -1, stresc_brotag_BM, NULL)
      switch (uc)
        {
        case '\"':
          ADDESCAPESTR_BM ("\\\"");
          break;
        case '\'':
          ADDESCAPESTR_BM ("\\\'");
          break;
        case '\a':
          ADDESCAPESTR_BM ("\\a");
          break;
        case '\b':
          ADDESCAPESTR_BM ("\\b");
          break;
        case '\f':
          ADDESCAPESTR_BM ("\\f");
          break;
        case '\n':
          if (linecnt > 3 * WANTEDLINEWIDTH_BM / 4 && pc[1] && pc[2])
            {
              ADDESCAPESTR_BM ("\"+");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          else
            ADDESCAPESTR_BM ("\\n");
          break;
        case '\r':
          ADDESCAPESTR_BM ("\\r");
          break;
        case '\t':
          ADDESCAPESTR_BM ("\\t");
          break;
        case '\v':
          ADDESCAPESTR_BM ("\\v");
          break;
        case '\033' /*ESCAPE*/:
          ADDESCAPESTR_BM ("\\e");
          break;
        default:
          if (linecnt > 3 * WANTEDLINEWIDTH_BM / 4 && pc[1] && pc[2]
              && g_unichar_isspace (uc))
            {
              ADDESCAPESTR_BM ("\"&");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          else if (linecnt > WANTEDLINEWIDTH_BM && pc[1])
            {
              ADDESCAPESTR_BM ("\"&");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          if (g_unichar_isprint (uc))
            {
              char ubuf[8];
              memset (ubuf, 0, sizeof (ubuf));
              g_unichar_to_utf8 (uc, ubuf);
              gtk_text_buffer_insert_with_tags (brobuf,
                                                &browserit_BM, ubuf, -1,
                                                str_brotag_BM, NULL);
            }
          else if (uc < 0xffff)
            {
              char ubuf[24];
              memset (ubuf, 0, sizeof (ubuf));
              snprintf (ubuf, sizeof (ubuf), "\\u%04x", uc);
              ADDESCAPESTR_BM (ubuf);
            }
          else
            {
              char ubuf[24];
              memset (ubuf, 0, sizeof (ubuf));
              snprintf (ubuf, sizeof (ubuf), "\\U%08x", uc);
              ADDESCAPESTR_BM (ubuf);
            }
          break;
        }
    }                           /* end for pc */
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "\"", -1, stresc_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth,
                        (struct stackframe_stBM *) &_);
  if (ccnt >= WANTEDLINEWIDTH_BM / 2)
    browsespacefordepth_BM (curdepth);
  LOCALRETURN_BM (arg1);
}                               /* end ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud) */



/// method to browse_value for node-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg);
value_tyBM
ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),        // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!isnode_BM (arg1))
    FATAL_BM
      ("non-node for method to browse_value for node-s _7fJKfG4SN0U_1QTu5J832xg");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * nodbrows;
                 const objectval_tyBM * connob; value_tyBM curson;);
  _.nodbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  ASSERT_BM (curdepth <= maxdepth);
  unsigned nw = nodewidth_BM ((const value_tyBM) _.nodbrows);
  _.connob = nodeconn_BM ((const value_tyBM) _.nodbrows);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.connob));
  int oboff = browse_show_start_offset_BM ();
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  int xtraoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "*", -1, nest_brotag_BM, NULL);
  gtk_text_buffer_insert (brobuf, &browserit_BM, " ", 1);
  browse_value_BM ((const value_tyBM) _.connob, (struct stackframe_stBM *) &_,
                   (maxdepth), (curdepth + 1));
  browsespacefordepth_BM (curdepth + 1);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "(", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      for (unsigned six = 0; six < nw; six++)
        {
          _.curson = nodenthson_BM ((const value_tyBM) _.nodbrows, six);
          if (six > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.curson,
                           (struct stackframe_stBM *) &_, (maxdepth),
                           (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d sons in node|", nw);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    ")", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, xtraoff, 1, 1, 1, curdepth,
                        (struct stackframe_stBM *) &_);
  LOCALRETURN_BM (arg1);
}                               /* end ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg) */





/// method to browse_value for closure-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_7CohjJ9tkfZ_4UMAIZCgwac);
value_tyBM
ROUTINEOBJNAME_BM (_7CohjJ9tkfZ_4UMAIZCgwac)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  if (!isclosure_BM (arg1))
    FATAL_BM
      ("non-closure for method to browse_value for closure-s _7CohjJ9tkfZ_4UMAIZCgwac");
  ASSERT_BM (istaggedint_BM (arg2));
  ASSERT_BM (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clobrows;
                 const objectval_tyBM * connob; value_tyBM curson;);
  _.clobrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  ASSERT_BM (curdepth <= maxdepth);
  unsigned cw = closurewidth_BM ((const value_tyBM) _.clobrows);
  _.connob = closureconn_BM ((const value_tyBM) _.clobrows);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.connob));
  int oboff = browse_show_start_offset_BM ();
  int xtraoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "%", -1, nest_brotag_BM, NULL);
  gtk_text_buffer_insert (brobuf, &browserit_BM, " ", 1);
  browse_value_BM ((const value_tyBM) _.connob, (struct stackframe_stBM *) &_,
                   (maxdepth), (curdepth + 1));
  browsespacefordepth_BM (curdepth + 1);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    "(", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      for (unsigned cix = 0; cix < cw; cix++)
        {
          _.curson = closurenthson_BM ((const value_tyBM) _.clobrows, cix);
          if (cix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.curson,
                           (struct stackframe_stBM *) &_, (maxdepth),
                           (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d sons in closure|", cw);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,      //
                                    ")", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, xtraoff, 1, 1, 1, curdepth,
                        (struct stackframe_stBM *) &_);
  LOCALRETURN_BM (arg1);
}                               /* end ROUTINEOBJNAME_BM ( _7CohjJ9tkfZ_4UMAIZCgwac) */



/// method to browse_data for basiclo_function-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_9zpvXnTuDeB_2B7ZiBtN8fA);
value_tyBM
ROUTINEOBJNAME_BM (_9zpvXnTuDeB_2B7ZiBtN8fA)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__ ((unused)), const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 value_tyBM curval;);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for basiclo_function-s _9zpvXnTuDeB_2B7ZiBtN8fA");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.objbrows));
  _.curval = objpayload_BM (_.objbrows);
  int tyval = valtype_BM (_.curval);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  if (tyval == tyInt_BM
      || (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM))
    {
      char vcommbuf[40];
      memset (vcommbuf, 0, sizeof (vcommbuf));
      snprintf (vcommbuf, sizeof (vcommbuf), "|valdata h=%u:| ",
                valhash_BM (_.curval));
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, vcommbuf, -1,
                                        miscomm_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curval,
                       (struct stackframe_stBM *) &_, depth, 0);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    };
  LOCALRETURN_BM (_.objbrows);
}                               /* end ROUTINE _9zpvXnTuDeB_2B7ZiBtN8fA */



/// method to browse_data°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4IshjBIv6ol_5korHKUIjeK);
value_tyBM
ROUTINEOBJNAME_BM (_4IshjBIv6ol_5korHKUIjeK)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__ ((unused)),        //
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows; value_tyBM curval;
                 const objectval_tyBM * curkeyob; value_tyBM curkeyval;
                 const setval_tyBM * setk;
    );
  if (!isobject_BM (arg1))
    FATAL_BM ("non-object for method to browse_data for hset_object");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.objbrows));
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  _.curval = objpayload_BM (_.objbrows);
  if (!_.curval)
    {
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, "|no hset|", -1,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      LOCALRETURN_BM (_.objbrows);
    }
  int tyval = valtype_BM (_.curval);
  WEAKASSERT_BM (tyval == typayl_hashsetobj_BM);
  _.setk = hashsetobj_to_set_BM (_.curval);
  char commbuf[32];
  memset (commbuf, 0, sizeof (commbuf));
  snprintf (commbuf, sizeof (commbuf), "|hset %d:|", setcardinal_BM (_.setk));
  gtk_text_buffer_insert_with_tags (brobuf,
                                    &browserit_BM, commbuf, -1,
                                    miscomm_brotag_BM, NULL);
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  browse_value_BM ((const value_tyBM) _.setk,
                   (struct stackframe_stBM *) &_, depth, 0);
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°hset_object _4IshjBIv6ol_5korHKUIjeK */



/// method to browse_data for any object with extended value ob_data
extern objrout_sigBM ROUTINEOBJNAME_BM (_5KWAjUEGiiq_2B6rbvkCcgc);
value_tyBM
ROUTINEOBJNAME_BM (_5KWAjUEGiiq_2B6rbvkCcgc)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdept
 const value_tyBM arg3 __attribute__ ((unused)),        //
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows; value_tyBM curval;
                 const objectval_tyBM * curkeyob; value_tyBM curkeyval;
                 const setval_tyBM * setk;
    );
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for any object _5KWAjUEGiiq_2B6rbvkCcgc");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.objbrows));
#warning should be improved
  _.curval = objpayload_BM (_.objbrows);
  int tyval = valtype_BM (_.curval);
  char vcommbuf[64];
  memset (vcommbuf, 0, sizeof (vcommbuf));
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  if (tyval == tyInt_BM
      || (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM))
    {
      snprintf (vcommbuf, sizeof (vcommbuf), "|xvaldata h=%u:| ",
                valhash_BM (_.curval));
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, vcommbuf, -1,
                                        miscomm_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curval,
                       (struct stackframe_stBM *) &_, depth, 0);
    }
  else
    switch (tyval)
      {
      case tyNone_BM:
        {
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|xnone|", -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_vectval_BM:
        {
          const struct datavectval_stBM *dvec = _.curval;
          snprintf (vcommbuf, sizeof (vcommbuf), "|xvector l:%u| ",
                    datavectlen_BM (dvec));
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_assocbucket_BM:
      case typayl_assocpairs_BM:
        {
          const anyassoc_tyBM *assoc = assoccast_BM (_.curval);
          unsigned nbkeys = assoc_nbkeys_BM (assoc);
          snprintf (vcommbuf, sizeof (vcommbuf), "|xassoc l:%u| ", nbkeys);
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
          _.setk = assoc_setattrs_BM (assoc);
          ASSERT_BM (nbkeys == setcardinal_BM (_.setk));
          objectval_tyBM *tinyarr[TINYSIZE_BM] = {
          };
          objectval_tyBM **arr = (nbkeys < TINYSIZE_BM) ? tinyarr       //
            : calloc (prime_above_BM (nbkeys),
                      sizeof (const objectval_tyBM *));
          if (!arr)
            FATAL_BM ("failed to calloc arr for %d keys", nbkeys);
          for (unsigned ix = 0; ix < nbkeys; ix++)
            arr[ix] = setelemnth_BM (_.setk, ix);
          sortnamedobjarr_BM (arr, nbkeys);
          for (unsigned kix = 0; kix < nbkeys; kix++)
            {
              _.curkeyob = arr[kix];
              _.curkeyval = assoc_getattr_BM (assoc, _.curkeyob);
              gtk_text_buffer_insert (brobuf, &browserit_BM, "\342\234\252 ",   // U+272A CIRCLED WHITE STAR ✪
                                      -1);
              browse_value_BM ((const value_tyBM) _.curkeyob,
                               (struct stackframe_stBM *) &_, 2, 0);
              browsespacefordepth_BM (1);
              browse_value_BM ((const value_tyBM) _.curkeyval,
                               (struct stackframe_stBM *) &_, depth, 1);
              gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
            }
          if (arr != tinyarr)
            free (arr), arr = NULL;
        }
        break;
      case typayl_hashsetobj_BM:
        {
          const struct hashsetobj_stBM *hset = hashsetobjcast_BM (_.curval);
          snprintf (vcommbuf, sizeof (vcommbuf), "|xhset card:%u| ",
                    hashsetobj_cardinal_BM ((const value_tyBM) hset));
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
          _.setk = hashsetobj_to_set_BM ((const value_tyBM) hset);
          browse_value_BM ((const value_tyBM) _.setk,
                           (struct stackframe_stBM *) &_, depth, 1);
        }
        break;
      case typayl_listtop_BM:
        {
          const struct listtop_stBM *lis = _.curval;
          snprintf (vcommbuf, sizeof (vcommbuf), "|xlist l:%u| ",
                    listlength_BM (lis));
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_loader_BM:
        {
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|xloader|", -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_parser_BM:
        {
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|xparser|", -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_classinfo_BM:
        {
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|xclassinfo|", -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_strbuffer_BM:
        {
          snprintf (vcommbuf, sizeof (vcommbuf), "|xsbuf l:%u| ",
                    objstrbufferlengthpayl_BM (_.objbrows));
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_dumper_BM:
        {
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, "|xdumper|", -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      case typayl_dict_BM:
        {
          const struct dict_stBM *dic = _.curval;
          snprintf (vcommbuf, sizeof (vcommbuf), "|xdict s.%u| ",
                    dictsize_BM (dic));
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      default:
        {
          snprintf (vcommbuf, sizeof (vcommbuf), "|xtyp?#%d| ", (int) tyval);
          gtk_text_buffer_insert_with_tags (brobuf,
                                            &browserit_BM, vcommbuf, -1,
                                            miscomm_brotag_BM, NULL);
        }
        break;
      };
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  LOCALRETURN_BM (_.objbrows);
}                               /* end  browse_data for any object with extended value_5KWAjUEGiiq_2B6rbvkCcgc  */



////////////////////////////////////////////////////////////////

/// command handler for put
extern objrout_sigBM ROUTINEOBJNAME_BM (_1Xc5XJ7S5r7_3nYIzlf2XAw);
value_tyBM
ROUTINEOBJNAME_BM (_1Xc5XJ7S5r7_3nYIzlf2XAw)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the attr or index
 const value_tyBM arg3,         // the comp
 const value_tyBM arg4_ __attribute__ ((unused)),       // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM attv;
                 value_tyBM compv;
                 value_tyBM reasonv;
    );
  objectval_tyBM *k_failure_non_object = BMK_6yWldsq3Rmk_01WqTfwSIDV;
  objectval_tyBM *k_failure_bad_attribute = BMK_4GumRf8w4jT_6lfDDJ5Y3TH;
  if (!isobject_BM (arg1))
    {
      FAILURE_BM (__LINE__, k_failure_non_object,
                  (struct stackframe_stBM *) &_);
    }
  _.recv = arg1;
  _.attv = arg2;
  _.compv = arg3;
  NONPRINTF_BM ("commandhandler°put recv=%s attv=%s compv=%s", objectdbg_BM (_.recv), debug_outstr_value_BM    //
                (_.attv, (struct stackframe_stBM *) &_, 0), debug_outstr_value_BM       //
                (_.compv, (struct stackframe_stBM *) &_, 0));
  if (isobject_BM (_.attv))
    {
      objlock_BM (_.recv);
      if (_.compv)
        objputattr_BM (_.recv, _.attv, _.compv);
      else
        objremoveattr_BM (_.recv, _.attv);
      objtouchnow_BM (_.recv);
      objunlock_BM (_.recv);
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("In object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_puts_message_BM (" put attribute ");
          log_object_message_BM (objectcast_BM (_.attv));
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
      LOCALRETURN_BM (_.recv);
    }
  else if (istaggedint_BM (_.attv))
    {
      int attix = getint_BM (_.attv);
      objlock_BM (_.recv);
      objputcomp_BM (_.recv, attix, _.compv);
      objtouchnow_BM (_.recv);
      objunlock_BM (_.recv);
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("In object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_printf_message_BM (" put component#%d.", attix);
          log_end_message_BM ();
        }
      LOCALRETURN_BM (_.recv);
    }
  else
    {
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("In object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_printf_message_BM
            (" bad attribute %s to put.",
             debug_outstr_value_BM (_.attv, (struct stackframe_stBM *) &_,
                                    0));
          log_end_message_BM ();
        }
      FAILURE_BM (__LINE__, k_failure_bad_attribute,
                  (struct stackframe_stBM *) &_);
    }
  LOCALRETURN_BM (NULL);
}                               /* end  command handler for put _1Xc5XJ7S5r7_3nYIzlf2XAw */


/// command handler for add
extern objrout_sigBM ROUTINEOBJNAME_BM (_5v5ChlG1IYh_1Pv87MZJFPl);
value_tyBM
ROUTINEOBJNAME_BM (_5v5ChlG1IYh_1Pv87MZJFPl)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the comp
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       // 
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 value_tyBM compv;
    );
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  objectval_tyBM *k_failure_non_object = BMK_6yWldsq3Rmk_01WqTfwSIDV;
  if (!isobject_BM (arg1))
    {
      FAILURE_BM (__LINE__, k_failure_non_object,
                  (struct stackframe_stBM *) &_);
    }
  _.recv = arg1;
  _.compv = arg2;
  NONPRINTF_BM ("commandhandler°add recv=%s compv=%s",
                objectdbg_BM (_.recv),
                debug_outstr_value_BM
                (_.compv, (struct stackframe_stBM *) &_, 0));
  int oblen = 0;
  objlock_BM (_.recv);
  objappendcomp_BM (_.recv, _.compv);
  objtouchnow_BM (_.recv);
  oblen = objnbcomps_BM (_.recv);
  objunlock_BM (_.recv);
  log_begin_message_BM ();
  log_puts_message_BM ("In object ");
  log_object_message_BM (objectcast_BM (_.recv));
  log_printf_message_BM (" added component#%d.", oblen);
  log_end_message_BM ();
  LOCALRETURN_BM (_.recv);
}                               /* end commandhandler°add _5v5ChlG1IYh_1Pv87MZJFPl */

/// command handler for remove
extern objrout_sigBM ROUTINEOBJNAME_BM (_0zf6nSKwSlU_6Cv3LMh1MmV);
value_tyBM
ROUTINEOBJNAME_BM (_0zf6nSKwSlU_6Cv3LMh1MmV)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the attr or index
 const value_tyBM arg3_ __attribute__ ((unused)),       // 
 const value_tyBM arg4_ __attribute__ ((unused)),       // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM attv;
    );
  objectval_tyBM *k_failure_non_object = BMK_6yWldsq3Rmk_01WqTfwSIDV;
  objectval_tyBM *k_failure_bad_attribute = BMK_4GumRf8w4jT_6lfDDJ5Y3TH;
  if (!isobject_BM (arg1))
    {
      FAILURE_BM (__LINE__, k_failure_non_object,
                  (struct stackframe_stBM *) &_);
    }
  _.recv = arg1;
  _.attv = arg2;
  NONPRINTF_BM ("commandhandler°remove recv=%s attv=%s",
                objectdbg_BM (_.recv),
                debug_outstr_value_BM
                (_.attv, (struct stackframe_stBM *) &_, 0));
  if (isobject_BM (_.attv))
    {
      objlock_BM (_.recv);
      objremoveattr_BM (_.recv, _.attv);
      objtouchnow_BM (_.recv);
      objunlock_BM (_.recv);
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("In object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_puts_message_BM (" remove attribute ");
          log_object_message_BM (objectcast_BM (_.attv));
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
      LOCALRETURN_BM (_.recv);
    }
//- else if (istaggedint_BM (_.attv))
//-   {
//-     int attix = getint_BM (_.attv);
//-     objlock_BM (_.recv);
//-     objputcomp_BM (_.recv, attix, _.compv);
//-     objunlock_BM (_.recv);
//-     log_begin_message_BM ();
//-     log_puts_message_BM ("In object ");
//-     log_object_message_BM (objectcast_BM (_.recv));
//-     log_printf_message_BM (" remove component#%d.", attix);
//-     log_end_message_BM ();
//-     LOCALRETURN_BM (_.recv);
//-   }
  else
    {
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("In object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_printf_message_BM
            (" bad attribute %s to remove.",
             debug_outstr_value_BM (_.attv, (struct stackframe_stBM *) &_,
                                    0));
          log_end_message_BM ();
        }
      FAILURE_BM (__LINE__, k_failure_bad_attribute,
                  (struct stackframe_stBM *) &_);
    }
  LOCALRETURN_BM (NULL);
}                               /* end  command handler for remove _0zf6nSKwSlU_6Cv3LMh1MmV  */


/// command handler for init_class
extern objrout_sigBM ROUTINEOBJNAME_BM (_797zacMjvvt_3I2uxNJRfdq);
value_tyBM
ROUTINEOBJNAME_BM (_797zacMjvvt_3I2uxNJRfdq)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the superclass
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * superob;
    );
  objectval_tyBM *k_failure_non_object = BMK_6yWldsq3Rmk_01WqTfwSIDV;
  objectval_tyBM *k_failure_bad_attribute = BMK_4GumRf8w4jT_6lfDDJ5Y3TH;
  objectval_tyBM *k_failure_bad_class = BMK_797zacMjvvt_3I2uxNJRfdq;
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    {
      FAILURE_BM (__LINE__, k_failure_non_object,
                  (struct stackframe_stBM *) &_);
    }
  if (!isobject_BM (arg2))
    {
      FAILURE_BM (__LINE__, k_failure_bad_class,
                  (struct stackframe_stBM *) &_);
    };
  _.recv = (objectval_tyBM *) arg1;
  _.superob = (objectval_tyBM *) arg2;
  bool badsuper = false;
  {
    objlock_BM (_.superob);
    if (objclass_BM (_.superob) != BMP_class)
      badsuper = true;
    objunlock_BM (_.superob);
  }
  if (badsuper)
    {
      FAILURE_BM (__LINE__, k_failure_bad_class,
                  (struct stackframe_stBM *) &_);
    };
  objlock_BM (_.recv);
  objputclass_BM (_.recv, BMP_class);
  objputclassinfo_BM (_.recv, _.superob);
  objtouchnow_BM (_.recv);
  objunlock_BM (_.recv);
  if (pthread_self () == mainthreadid_BM)
    {
      log_begin_message_BM ();
      log_puts_message_BM ("Object ");
      log_object_message_BM (objectcast_BM (_.recv));
      log_puts_message_BM (" made class of super ");
      log_object_message_BM (_.superob);
      log_puts_message_BM (".");
      log_end_message_BM ();
    }
  LOCALRETURN_BM (_.recv);
}                               /* end commandhandler°init_class _797zacMjvvt_3I2uxNJRfdq  */


/// command handler for put_method
extern objrout_sigBM ROUTINEOBJNAME_BM (_9QuovXgtk9K_17pMbAD0XmX);
value_tyBM
ROUTINEOBJNAME_BM (_9QuovXgtk9K_17pMbAD0XmX)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the selector
 const value_tyBM arg3,         // the closure
 const value_tyBM arg4_ __attribute__ ((unused)),       // 
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obselv;
                 value_tyBM closv;
    );
  objectval_tyBM *k_failure_non_object = BMK_6yWldsq3Rmk_01WqTfwSIDV;
  objectval_tyBM *k_failure_bad_class = BMK_797zacMjvvt_3I2uxNJRfdq;
  objectval_tyBM *k_failure_bad_closure = BMK_373gFe8m21E_47xzvCGxpI9;
  objectval_tyBM *k_failure_bad_selector = BMK_9KxVIxneLrM_8xLQNri9PmJ;
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    {
      FAILURE_BM (__LINE__, k_failure_non_object,
                  (struct stackframe_stBM *) &_);
    }
  _.recv = (objectval_tyBM *) arg1;
  if (!isobject_BM (arg2))
    {
      FAILURE_BM (__LINE__, k_failure_bad_selector,
                  (struct stackframe_stBM *) &_);
    }
  _.obselv = arg2;
  if (arg3 && !isclosure_BM (arg3))
    {
      FAILURE_BM (__LINE__, k_failure_bad_closure,
                  (struct stackframe_stBM *) &_);
    }
  _.closv = arg3;
  bool badclass = false;
  char *actword = NULL;
  objlock_BM (_.recv);
  if (objhasclassinfo_BM (_.recv))
    {
      if (_.closv)
        {
          objclassinfoputmethod_BM (_.recv, _.obselv, _.closv);
          actword = "put";
        }
      else
        {
          objclassinforemovemethod_BM (_.recv, _.obselv);
          actword = "remove";
        }
    }
  else
    badclass = true;
  objunlock_BM (_.recv);
  if (badclass)
    {
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("Object ");
          log_object_message_BM (objectcast_BM (_.recv));
          log_puts_message_BM (" is not a class.");
          log_end_message_BM ();
        }
      FAILURE_BM (__LINE__, k_failure_bad_class,
                  (struct stackframe_stBM *) &_);
    }
  if (pthread_self () == mainthreadid_BM)
    {
      log_begin_message_BM ();
      log_puts_message_BM ("In object ");
      log_object_message_BM (objectcast_BM (_.recv));
      log_printf_message_BM (" did %s method for ", actword);
      log_object_message_BM (objectcast_BM (_.obselv));
      log_puts_message_BM (".");
      log_end_message_BM ();
    }
  LOCALRETURN_BM (_.recv);
}                               /* end commandhandler°put_method _9QuovXgtk9K_17pMbAD0XmX */



// method browse_data°list_object _2EtVNhr2mHz_8CsOQJdYeCE
extern objrout_sigBM ROUTINEOBJNAME_BM (_2EtVNhr2mHz_8CsOQJdYeCE);

value_tyBM
ROUTINEOBJNAME_BM (_2EtVNhr2mHz_8CsOQJdYeCE)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2EtVNhr2mHz_8CsOQJdYeCE,
                 value_tyBM resultv; const objectval_tyBM * objbrows;
                 value_tyBM nodv; value_tyBM cursonv;
    );
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for list_object-s _2EtVNhr2mHz_8CsOQJdYeCE");
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  WEAKASSERT_BM (objhaslistpayl_BM (_.objbrows));
  _.nodv = objlisttonodepayl_BM (_.objbrows, BMP_node);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  int nodlen = nodewidth_BM (_.nodv);
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|list %d:|", nodlen);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  for (int ix = 0; ix < nodlen; ix++)
    {
      if (ix > 0 && ix % 10 == 0)
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      _.cursonv = nodenthson_BM (_.nodv, ix);
      char bufmsg[48];
      memset (bufmsg, 0, sizeof (bufmsg));
      snprintf (bufmsg, sizeof (bufmsg), "\342\255\231 %d: ",   //U+2B59 HEAVY CIRCLED SALTIRE ⭙
                ix);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, bufmsg, -1,
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.cursonv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|end list of %d|", nodlen);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°list_object _2EtVNhr2mHz_8CsOQJdYeCE */



//browse_data°assoc_object _0f1S28bCE26_3X6Vpz9lG4A

extern objrout_sigBM ROUTINEOBJNAME_BM (_0f1S28bCE26_3X6Vpz9lG4A);

value_tyBM
ROUTINEOBJNAME_BM (_0f1S28bCE26_3X6Vpz9lG4A)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0f1S28bCE26_3X6Vpz9lG4A,
                 value_tyBM resultv; const objectval_tyBM * objbrows;
                 value_tyBM setv; value_tyBM tupv;
                 const objectval_tyBM * curobj; value_tyBM curvalv;
    );
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for assoc_object-s _0f1S28bCE26_3X6Vpz9lG4A");
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  WEAKASSERT_BM (objhasassocpayl_BM (_.objbrows));
  _.setv = objassocsetattrspayl_BM (_.objbrows);
  _.tupv = settonamedsortedtuple_BM (_.setv);
  int nbelem = tuplesize_BM (_.tupv);
  ASSERT_BM (nbelem == setcardinal_BM (_.setv));
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|assoc %d:|", nbelem);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  for (int ix = 0; ix < nbelem; ix++)
    {
      if (ix > 0 && ix % 10 == 0)
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      _.curobj = tuplecompnth_BM (_.tupv, ix);
      _.curvalv = objassocgetattrpayl_BM (_.objbrows, _.curobj);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, "\342\210\230 ", //U+2218 RING OPERATOR ∘
                                        -1, nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curobj,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, " \342\206\222 ",        //U+2192 RIGHTWARDS ARROW →
                                        -1, nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curvalv,
                       (struct stackframe_stBM *) &_, maxdepth, 2);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|end assoc %d|", nbelem);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°assoc_object  _0f1S28bCE26_3X6Vpz9lG4A */


// browse_data°dict_object _6xPQJolJkUw_2jCiJ3IOKXE

extern objrout_sigBM ROUTINEOBJNAME_BM (_6xPQJolJkUw_2jCiJ3IOKXE);

value_tyBM
ROUTINEOBJNAME_BM (_6xPQJolJkUw_2jCiJ3IOKXE)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_6xPQJolJkUw_2jCiJ3IOKXE,
                 value_tyBM resultv; const objectval_tyBM * objbrows;
                 value_tyBM nodv; value_tyBM cursonv; value_tyBM curvalv;
    );
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for dict_object-s _6xPQJolJkUw_2jCiJ3IOKXE");
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  WEAKASSERT_BM (objhasdictpayl_BM (_.objbrows));
  _.nodv = objdictnodeofkeyspayl_BM (_.objbrows, BMP_node);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  int nbnames = nodewidth_BM (_.nodv);
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|dict %d:|", nbnames);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  for (int ix = 0; ix < nbnames; ix++)
    {
      if (ix > 0 && ix % 10 == 0)
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      _.cursonv = nodenthson_BM (_.nodv, ix);
      WEAKASSERT_BM (isstring_BM (_.cursonv));
      _.curvalv = objdictgetpayl_BM (_.objbrows, _.cursonv);
      WEAKASSERT_BM (_.curvalv != NULL);
      char bufmsg[48];
      memset (bufmsg, 0, sizeof (bufmsg));
      snprintf (bufmsg, sizeof (bufmsg), "\342\257\216 %d: ",   //U+2BCE WHITE FOUR POINTED CUSP ⯎
                ix);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, bufmsg, -1,
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.cursonv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        " \342\206\246 ", -1,   // U+21A6 RIGHTWARDS ARROW FROM BAR ↦
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curvalv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|end dict of %d|", nbnames);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°dict_object _6xPQJolJkUw_2jCiJ3IOKXE */


// browse_data°hashsetval_object _9dKLCRPRn9Z_1tczFz5weBe
extern objrout_sigBM ROUTINEOBJNAME_BM (_9dKLCRPRn9Z_1tczFz5weBe);

value_tyBM
ROUTINEOBJNAME_BM (_9dKLCRPRn9Z_1tczFz5weBe)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4,         //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9dKLCRPRn9Z_1tczFz5weBe,
                 value_tyBM resultv; const objectval_tyBM * objbrows;
                 value_tyBM nodv; value_tyBM cursonv;
    );
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for hashsetval_object-s _9dKLCRPRn9Z_1tczFz5weBe");
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  WEAKASSERT_BM (objhashashsetvalpayl_BM (_.objbrows));
  _.nodv = objhashsetvalmakenodepayl_BM (_.objbrows, BMP_node);
  WEAKASSERT_BM (isnode_BM (_.nodv));
  int nbvals = nodewidth_BM (_.nodv);
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|hashsetval %d:|", nbvals);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  for (int ix = 0; ix < nbvals; ix++)
    {
      if (ix > 0 && ix % 10 == 0)
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      _.cursonv = nodenthson_BM (_.nodv, ix);
      WEAKASSERT_BM (_.cursonv != NULL);
      char bufmsg[48];
      memset (bufmsg, 0, sizeof (bufmsg));
      snprintf (bufmsg, sizeof (bufmsg), "\342\230\222 %d: ",   //U+2612 BALLOT BOX WITH X ☒
                ix);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, bufmsg, -1,
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.cursonv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|end hashsetval %d|", nbvals);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°hashsetval_object  _9dKLCRPRn9Z_1tczFz5weBe */


// browse_data°hashmapval_object _0M2jApBzFAy_8H8cpCjGpTi
extern objrout_sigBM ROUTINEOBJNAME_BM (_0M2jApBzFAy_8H8cpCjGpTi);

value_tyBM
ROUTINEOBJNAME_BM (_0M2jApBzFAy_8H8cpCjGpTi)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0M2jApBzFAy_8H8cpCjGpTi,
                 value_tyBM resultv; const objectval_tyBM * objbrows;
                 value_tyBM nodv; value_tyBM cursonv; value_tyBM curvalv;
    );
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for hashmapval_object-s _0M2jApBzFAy_8H8cpCjGpTi");
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.objbrows));
  _.nodv = objhashmapvalmakenodeofkeyspayl_BM (_.objbrows, BMP_node);
  WEAKASSERT_BM (isnode_BM (_.nodv));
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  int nbkeys = nodewidth_BM (_.nodv);
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|hashmapval %d:|", nbkeys);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  for (int ix = 0; ix < nbkeys; ix++)
    {
      if (ix > 0 && ix % 10 == 0)
        gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      _.cursonv = nodenthson_BM (_.nodv, ix);
      WEAKASSERT_BM (_.cursonv != NULL);
      _.curvalv = objhashmapvalgetpayl_BM (_.objbrows, _.cursonv);
      WEAKASSERT_BM (_.curvalv != NULL);
      char bufmsg[48];
      memset (bufmsg, 0, sizeof (bufmsg));
      snprintf (bufmsg, sizeof (bufmsg),        //
                "\342\232\255 %d: ",    // U+26AD MARRIAGE SYMBOL ⚭
                ix);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, bufmsg, -1,
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.cursonv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
      gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,  //
                                        " \342\206\246 ", -1,   // U+21A6 RIGHTWARDS ARROW FROM BAR ↦
                                        nest_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curvalv,
                       (struct stackframe_stBM *) &_, maxdepth, 1);
      gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
    }
  {
    char bufmsg[48];
    memset (bufmsg, 0, sizeof (bufmsg));
    snprintf (bufmsg, sizeof (bufmsg), "|end hashmapval of %d|", nbkeys);
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, bufmsg, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  }
  LOCALRETURN_BM (_.objbrows);
}                               /* end browse_data°hashmapval_object _0M2jApBzFAy_8H8cpCjGpTi */



////////////////////////////////////////////////////////////////
// test_agenda command_handler _1eQ1a8KHixZ_1XDNH5iTQ0I
extern objrout_sigBM ROUTINEOBJNAME_BM (_1eQ1a8KHixZ_1XDNH5iTQ0I);
value_tyBM
ROUTINEOBJNAME_BM (_1eQ1a8KHixZ_1XDNH5iTQ0I)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // nbtasklets
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1eQ1a8KHixZ_1XDNH5iTQ0I,
                 objectval_tyBM * taskob; value_tyBM arg1v;
                 value_tyBM arg2v;
                 value_tyBM closv;
    );
  objectval_tyBM *k_tiny_tasklet = BMK_8dM7Xmdup4k_4jwzwOtmC1a;
  objectval_tyBM *k_rank = BMK_8zRh2medTlP_0ImnPyO8NKH;
  objectval_tyBM *k_todo = BMK_7ljWW4bj70g_9PL9dZkgBxZ;
  objectval_tyBM *kk_testagendafun = BMK_7XDuHagbhi8_3V9zhBpbrrV;
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  _.arg1v = arg1;
  _.arg2v = arg2;
  int nbtasklets = getint_BM (arg1);
  DBGPRINTF_BM ("test_agenda command_handler start nbtasklets=%d arg1=%s",      //
                nbtasklets,     //
                debug_outstr_value_BM (_.arg1v, //
                                       (struct stackframe_stBM *) &_, 0));
  if (nbtasklets <= 0 || nbtasklets > 25 * MILLION_BM)
    {
      log_begin_message_BM ();
      log_printf_message_BM (",test_agenda command bad nbtasklets %d",
                             nbtasklets);
      log_end_message_BM ();
      LOCALRETURN_BM (NULL);
    }
  int nbhi = 0;
  log_begin_message_BM ();
  log_printf_message_BM (",test_agenda will add %d tasklets.", nbtasklets);
  log_end_message_BM ();
  double starteltime = elapsedtime_BM ();
  double preveltime = 0.0;
  //
  for (int ix = 0; ix < nbtasklets; ix++)
    {
      _.taskob = makeobj_BM ();
      objputclass_BM (_.taskob, k_tiny_tasklet);
      objputattr_BM (_.taskob, k_rank, taggedint_BM (ix));
      _.closv = makeclosurevar_BM (kk_testagendafun, _.arg2v, NULL);
      objputattr_BM (_.taskob, k_todo, _.closv);
      objtouchnow_BM (_.taskob);
      bool hi = false;
      if (ix % 8 == 0)
        {
          agenda_add_high_priority_tasklet_BM (_.taskob);
          hi = true;
          nbhi++;
        }
      else
        agenda_add_low_priority_tasklet_BM (_.taskob);
      NONPRINTF_BM ("test_agenda ix=%d taskob %s / %s", ix,
                    objectdbg_BM (_.taskob), hi ? "hi" : "lo");
      if (ix % 100 == 0 && preveltime + 0.6 < elapsedtime_BM ())
        {
          preveltime = elapsedtime_BM ();
          DBGPRINTF_BM ("test_agenda **ix#%d taskob %s / %s elapsed %.3f s",
                        ix, objectdbg_BM (_.taskob), hi ? "hi" : "lo",
                        preveltime);
          log_begin_message_BM ();
          log_printf_message_BM (",test_agenda adding tasklet#%d ", ix);
          log_object_message_BM (_.taskob);
          log_printf_message_BM (" (%d of high priority), elapsed %.3f s.",
                                 nbhi, preveltime);
          log_end_message_BM ();
          usleep (1000);
        }
    }
  double realduration = elapsedtime_BM () - starteltime;
  DBGPRINTF_BM ("test_agenda ending realduration %.3f %d tasklets",
                realduration, nbtasklets);
  log_begin_message_BM ();
  log_printf_message_BM
    (",test_agenda added %d tasklets (with %d hi) in %.3f real seconds (%.2f µs/ob).",
     nbtasklets, nbhi, realduration, (1.0e6 * realduration) / nbtasklets);
  log_end_message_BM ();
  LOCALRETURN_BM (BMK_1eQ1a8KHixZ_1XDNH5iTQ0I);
}                               /* end routine _1eQ1a8KHixZ_1XDNH5iTQ0I */


//  test_agenda gtk _7rRjqfXs3QI_4Nwk2Lfm569
extern objrout_sigBM ROUTINEOBJNAME_BM (_7rRjqfXs3QI_4Nwk2Lfm569);

value_tyBM
ROUTINEOBJNAME_BM (_7rRjqfXs3QI_4Nwk2Lfm569)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // taskob
 const value_tyBM arg2,         // rank
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7rRjqfXs3QI_4Nwk2Lfm569,
                 objectval_tyBM * taskob; value_tyBM rankv;
                 value_tyBM resultv;
    );
  _.taskob = objectcast_BM (arg1);
  _.rankv = arg2;
  WEAKASSERT_BM (isobject_BM (_.taskob));
  WEAKASSERT_BM (istaggedint_BM (_.rankv));
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  int rk = getint_BM (_.rankv);
  NONPRINTF_BM ("test_agenda gtk taskob %s rk %d", objectdbg_BM (_.taskob),
                rk);
  log_begin_message_BM ();
  log_printf_message_BM ("testagenda elapsed %.3f s tasklet ",
                         elapsedtime_BM ());
  log_object_message_BM (_.taskob);
  log_printf_message_BM (" rank %d.", rk);
  log_end_message_BM ();
  LOCALRETURN_BM (_.taskob);
}                               /* end routine _7rRjqfXs3QI_4Nwk2Lfm569 */



// dump command_handler _5oSaKNehPiO_3GSlpH5boCW
extern objrout_sigBM ROUTINEOBJNAME_BM (_5oSaKNehPiO_3GSlpH5boCW);
value_tyBM
ROUTINEOBJNAME_BM (_5oSaKNehPiO_3GSlpH5boCW)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // optional dumpstring
 const value_tyBM arg2_,        //
 const value_tyBM arg3_,        //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5oSaKNehPiO_3GSlpH5boCW,
                 value_tyBM argv;
    );
  extern char *dump_dir_bm;
  char *dumpstr = NULL;
  char *realstr = NULL;
  _.argv = arg1;
  if (isstring_BM (_.argv))
    {
      dumpstr = strdup (bytstring_BM (_.argv));
      if (!dumpstr)
        FATAL_BM ("failed to strdup dump string %s", bytstring_BM (_.argv));
    }
  else
    {
      dumpstr = strdup (dump_dir_bm ? dump_dir_bm : ".");
      if (!dumpstr)
        FATAL_BM ("failed to strdup default dump string %s",
                  dump_dir_bm ? dump_dir_bm : ".");
      _.argv = makestring_BM (dumpstr);
    }
  realstr = realpath (dumpstr, NULL);
  log_begin_message_BM ();
  log_printf_message_BM (",dump into  directory %s (%s)", dumpstr,
                         realstr ? realstr : "??");
  log_puts_message_BM (".\n");
  struct dumpinfo_stBM di = dump_BM (dump_dir_bm, NULL);
  log_printf_message_BM ("dump: scanned %ld, emitted %ld objects\n",
                         di.dumpinfo_scanedobjectcount,
                         di.dumpinfo_emittedobjectcount);
  log_printf_message_BM ("did %ld todos, wrote %ld files\n",
                         di.dumpinfo_todocount, di.dumpinfo_wrotefilecount);
  log_printf_message_BM ("in %.3f elapsed, %.4f cpu seconds.\n",
                         di.dumpinfo_elapsedtime, di.dumpinfo_cputime);
  log_end_message_BM ();
  if (gui_command_log_file_BM)
    {
      time_t nowtim = time (NULL);
      struct tm nowtm = { };
      localtime_r (&nowtim, &nowtm);
      char nowbuf[64];
      memset (nowbuf, 0, sizeof (nowbuf));
      strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
      fprintf (gui_command_log_file_BM,
               "\n//// dumped %ld objects, %ld files to %s at %s\n\n",
               di.dumpinfo_emittedobjectcount, di.dumpinfo_wrotefilecount,
               realstr ? realstr : dumpstr, nowbuf);
      fflush (gui_command_log_file_BM);
    }
  free (dumpstr), dumpstr = NULL;
  free (realstr), realstr = NULL;
  LOCALRETURN_BM (_.argv);
}                               /* end dump command_handler _5oSaKNehPiO_3GSlpH5boCW */
