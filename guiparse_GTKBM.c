// file guiparse_GTKBM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

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
#include "guiparse_GTKBM.const.h"

void
parserror_guicmd_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf,
                     unsigned lineno, unsigned colpos, char *msg)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (commandbuf_BM, &endit);
  gtk_text_buffer_apply_tag (commandbuf_BM, errored_cmdtag_BM, &it, &endit);
  if (!nobuild)
    {
      log_begin_message_BM ();
      char errbuf[64];
      snprintf (errbuf, sizeof (errbuf), "command error L%dC%d:",
                lineno, colpos);
      GtkTextIter logit = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_end_iter (logbuf_BM, &logit);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &logit, errbuf, -1, error_logtag_BM, NULL);
      log_puts_message_BM (msg);
      log_end_message_BM ();
      gtk_text_view_scroll_to_iter (GTK_TEXT_VIEW (commandview_BM),
                                    &it, 0.1, false, 0.5, 0.2);
      errormessagedialog_BM = gtk_message_dialog_new_with_markup        //
        (GTK_WINDOW (mainwin_BM),
         GTK_DIALOG_DESTROY_WITH_PARENT,
         GTK_MESSAGE_ERROR,
         GTK_BUTTONS_CLOSE,
         "<b>command error</b> L%dC%d:\n" "%s", lineno, colpos, msg);
      gtk_widget_show_all (errormessagedialog_BM);
      fflush (NULL);
      /// errormessagedialog_BM is run in runcommand_BM 
    }
  free (msg);
#warning should use failure in parserror_guicmd_BM
  longjmp (jmperrorcmd_BM, 1);
}                               /* end parserror_guicmd_BM */



// for $<var>
value_tyBM
parsdollarval_guicmd_BM (struct parser_stBM *pars,
                         unsigned lineno,
                         unsigned colpos,
                         const value_tyBM varname,
                         struct stackframe_stBM *stkf)
{
  const char *varstr = NULL;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val;
    );
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  if (isstring_BM (varname))
    varstr = bytstring_BM (varname);
  else if (isobject_BM (varname))
    varstr = findobjectname_BM (varname);
  else if (varname == NULL)
    varstr = BMK_7bD9VtDkGSn_7lxHeYuuFLR;       // result
  if (!varstr)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "invalid $<var>");
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "not found $%s !(%s:%d)", varstr, __FILE__,
                          __LINE__);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 1 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return _.val;
}                               /* end parsdollarval_guicmd_BM */


// for $:<var>
const objectval_tyBM *
parsdollarobj_guicmd_BM (struct parser_stBM *pars,
                         unsigned lineno, unsigned colpos,
                         const value_tyBM varname,
                         struct stackframe_stBM *stkf)
{

  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val;
    );
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  const char *varstr = NULL;
  if (isstring_BM (varname))
    varstr = bytstring_BM (varname);
  else if (isobject_BM (varname))
    varstr = findobjectname_BM (varname);
  else if (varname == NULL)
    varstr = BMK_7bD9VtDkGSn_7lxHeYuuFLR;       /* result */
  if (!varstr)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "invalid $:<var> !(%s:%d)", __FILE__, __LINE__);
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "not found $:%s !(%s:%d)", varstr, __FILE__,
                          __LINE__);
  if (!isobject_BM (_.val) && !nobuild)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "non-object $:%s !(%s:%d)", varstr, __FILE__,
                          __LINE__);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 2 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return (const objectval_tyBM *) _.val;
}                               /* end parsdollarobj_guicmd_BM */


// for €<newname> or $*<newname>
const objectval_tyBM *parsmakenewname_guicmd_BM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   const value_tyBM varname, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * namedobj; const stringval_tyBM * strnam;
                 objectval_tyBM * parsob;);
  if (!isparser_BM (pars))
    return NULL;
  _.parsob = checkedparserowner_BM (pars);
  ASSERT_BM (isstring_BM (varname));
  _.strnam = varname;
  if (!validname_BM (bytstring_BM (varname)))
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "invalid new name %s", bytstring_BM (varname));
  _.namedobj = findnamedobj_BM (bytstring_BM (varname));
  if (_.namedobj)
    return _.namedobj;
  _.namedobj = makeobj_BM ();
  objtouchnow_BM (_.namedobj);
  objputspacenum_BM (_.namedobj, GlobalSp_BM);
  registername_BM (_.namedobj, bytstring_BM (_.strnam));
  log_begin_message_BM ();
  log_puts_message_BM ("created global new named object ");
  log_object_message_BM (_.namedobj);
  log_end_message_BM ();
  return _.namedobj;
}                               /* end parsmakenewname_guicmd_BM */

static bool
parseobjectcompl_guicmd_BM (struct parser_stBM *pars,
                            objectval_tyBM * obj, int depth,
                            struct stackframe_stBM *stkf,
                            struct parstoken_stBM *ptok);
#define MAXARGS_BM 9
bool
parseobjectcompl_guicmd_BM (struct parser_stBM *pars,
                            objectval_tyBM * targobj, int depth,
                            struct stackframe_stBM *stkf,
                            struct parstoken_stBM *ptok)
{
  if (!isparser_BM (pars))
    return false;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM comp; objectval_tyBM * targobj;
                 objectval_tyBM * obattr; objectval_tyBM * obclass;
                 objectval_tyBM * obsel; const stringval_tyBM * name;
                 objectval_tyBM * parsob; value_tyBM args[MAXARGS_BM];
    );
  _.parsob = checkedparserowner_BM (pars);
  _.targobj = targobj;
  struct parstoken_stBM tok = {
  };
  if (!ptok)
    {
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      ptok = &tok;
    };
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  unsigned lineno = pars->pars_lineno;
  unsigned colpos = pars->pars_colpos;
  //
  // !& <comp>   # append a component to target object
  if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamand)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !&");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  CURFRAME_BM,  //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing value after !&");
      if (!nobuild)
        {
          objappendcomp_BM (_.targobj, _.comp);
          log_begin_message_BM ();
          log_puts_message_BM ("appended to ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !: <attr> <val> # put an attribute in target object
  // !: <index> <val> # put a component at given index in target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamcolon)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !:");
      parserskipspaces_BM (pars, CURFRAME_BM);
      lineno = pars->pars_lineno;
      colpos = pars->pars_colpos;
      bool gotattr = false;
      bool gotindex = false;
      int index = -1;
      _.obattr = parsergetobject_BM (pars,      //
                                     CURFRAME_BM,       //
                                     depth + 1, &gotattr);
      if (!gotattr)
        {
          parserseek_BM (pars, lineno, colpos);
          struct parstoken_stBM tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind == plex_LLONG)
            {
              gotindex = true;
              index = (int) tok.tok_llong;
            }
        }
      if (!gotattr && !gotindex)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing attribute or index after !:");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  CURFRAME_BM,  //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing value after !:");
      if (!nobuild && gotattr)
        {
          objputattr_BM (_.targobj, _.obattr, _.comp);
          log_begin_message_BM ();
          log_puts_message_BM ("put attribute ");
          log_object_message_BM (_.obattr);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
      else if (!nobuild && gotindex)
        {
          objputcomp_BM (_.targobj, index, _.comp);
          log_begin_message_BM ();
          log_printf_message_BM ("put comp#%d in object ", index);
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !$ <class>           # set the class of target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamdollar)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !$");
      bool gotclass = false;
      _.obclass = parsergetobject_BM (pars,     //
                                      CURFRAME_BM,      //
                                      depth + 1, &gotclass);
      if (!gotclass)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing class after !$");
      if (!nobuild)
        {
          objectval_tyBM *k_basiclo_function = BMK_2Ir1i8qnrA4_3jSkierlc5z;
          objputclass_BM (_.targobj, _.obclass);
          log_begin_message_BM ();
          log_puts_message_BM ("put class ");
          log_object_message_BM (_.obclass);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          if (_.obclass == k_basiclo_function)
            {
              log_begin_message_BM ();
              log_puts_message_BM ("\n");
              gint codestartoff = 0;
              {
                GtkTextIter it = EMPTY_TEXT_ITER_BM;
                gtk_text_buffer_get_end_iter (logbuf_BM, &it);
                codestartoff = gtk_text_iter_get_offset (&it);
              }
              log_puts_message_BM ("\n");
              log_puts_message_BM ("// Possible code for ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("\n\n"
                                     "extern objrout_sigBM ROUTINEOBJNAME_BM (");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (");\n\n"
                                     "value_tyBM\n" "ROUTINEOBJNAME_BM (");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (")\n"
                                     "(struct stackframe_stBM* stkf, //\n"
                                     " const value_tyBM arg1, //\n"
                                     " const value_tyBM arg2, //\n"
                                     " const value_tyBM arg3, //\n"
                                     " const value_tyBM arg4, //\n"
                                     " const quasinode_tyBM* restargs __attribute__((unused)))\n"
                                     "{\n" "  LOCALFRAME_BM (stkf, /*descr ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("::*/ NULL,\n"
                                     "   value_tyBM resultv;\n" "  );\n");
              log_printf_message_BM ("#warning unimplemented ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (" routine\n");
              log_printf_message_BM
                ("  WEAKASSERT_BM(false && \"unimplemented ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (" routine\");\n");
              log_printf_message_BM ("  LOCALRETURN_BM(_.resultv);\n");
              log_printf_message_BM ("} /* end routine ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("*/\n\n");
              {
                GtkTextIter begit = EMPTY_TEXT_ITER_BM;
                GtkTextIter endit = EMPTY_TEXT_ITER_BM;
                gtk_text_buffer_get_iter_at_offset (logbuf_BM, &begit,
                                                    codestartoff);
                gtk_text_buffer_get_end_iter (logbuf_BM, &endit);
                gtk_text_buffer_apply_tag (logbuf_BM, code_logtag_BM, &begit,
                                           &endit);
              }
              log_puts_message_BM ("\n");
              if (!_.targobj->ob_rout && !_.targobj->ob_sig)
                {
                  _.targobj->ob_sig = BMP_function_sig;
                  _.targobj->ob_rout = objrout_placeholder_BM;
                  log_printf_message_BM ("** added placeholder for ");
                  log_object_message_BM (_.targobj);
                }
              log_end_message_BM ();
            }
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !> <obselector> ( ... ) # to send a side-effecting message
  else
    if (ptok->tok_kind == plex_DELIM
        && ptok->tok_delim == delim_exclamgreater)
    {
      unsigned arglineno = pars->pars_lineno;
      unsigned argcolpos = pars->pars_colpos;
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !>");
      bool gotsel = false;
      _.obsel = parsergetobject_BM (pars,       //
                                    CURFRAME_BM,        //
                                    depth + 1, &gotsel);
      if (!gotsel)
        parsererrorprintf_BM (pars, CURFRAME_BM, arglineno,
                              argcolpos, "missing selector after !>");
      parserskipspaces_BM (pars, CURFRAME_BM);
      unsigned leftlineno = pars->pars_lineno;
      unsigned leftcolpos = pars->pars_colpos;
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
        parsererrorprintf_BM (pars, CURFRAME_BM, arglineno,
                              argcolpos,
                              "missing left paren after selector for !>");
      int nbarg = 0;
      while (nbarg < MAXARGS_BM)
        {
          bool gotarg = false;
          _.args[nbarg] =       //
            parsergetvalue_BM (pars,    //
                               CURFRAME_BM,     //
                               depth + 1, &gotarg);
          if (!gotarg)
            break;
          nbarg++;
        }
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, CURFRAME_BM, arglineno,
                              argcolpos,
                              "missing right paren after selector for !>");
      unsigned rightlineno = pars->pars_lineno;
      unsigned rightcolpos = pars->pars_colpos;
      parsnesting_guicmd_BM (pars, depth + 1, delim_leftparen,
                             leftlineno, leftcolpos, delim_rightparen,
                             rightlineno, rightcolpos);
      if (!nobuild)
        {
          bool failsend = false;
          switch (nbarg)
            {
            case 0:
              _.comp = send0_BM (_.targobj, _.obsel, CURFRAME_BM);
              break;
            case 1:
              _.comp = send1_BM (_.targobj, _.obsel, CURFRAME_BM, _.args[0]);
              break;
            case 2:
              _.comp =
                send2_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1]);
              break;
            case 3:
              _.comp =
                send3_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2]);
              break;
            case 4:
              _.comp =
                send4_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2], _.args[3]);
              break;
            case 5:
              _.comp =
                send5_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4]);
              break;
            case 6:
              _.comp =
                send6_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5]);
              break;
            case 7:
              _.comp =
                send7_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5], _.args[6]);
              break;
            case 8:
              _.comp =
                send8_BM (_.targobj, _.obsel, CURFRAME_BM,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5], _.args[6], _.args[7]);
              break;
            default:
              _.comp = NULL;
              failsend = true;
              break;
            }
          if ((_.comp == NULL) || failsend)
            {
              char targidbuf[32];
              const char *targname = findobjectname_BM (_.targobj);
              idtocbuf32_BM (objid_BM (_.targobj), targidbuf);
              char selidbuf[32];
              const char *selname = findobjectname_BM (_.obsel);
              idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
              parsererrorprintf_BM (pars, CURFRAME_BM,
                                    arglineno, argcolpos,
                                    "failed to send %s to target %s",
                                    selname ? : selidbuf,
                                    targname ? : targidbuf);
            }
          log_begin_message_BM ();
          log_puts_message_BM ("sent message ");
          log_object_message_BM (_.obsel);
          log_printf_message_BM (" with %d arguments to object ", nbarg);
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
    }                           // end !> 
  //
  // !- <attr>  # remove an attribute in target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamminus)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !-");
      bool gotattr = false;
      _.obattr = parsergetobject_BM (pars,      //
                                     CURFRAME_BM,       //
                                     0, &gotattr);
      if (!gotattr)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing attribute after !-");
      if (!nobuild)
        {
          objremoveattr_BM (_.targobj, _.obattr);
          log_begin_message_BM ();
          log_puts_message_BM ("remove attribute ");
          log_object_message_BM (_.obattr);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // $% <name> # to show and bind to name
  else
    if (ptok->tok_kind == plex_DELIM
        && ptok->tok_delim == delim_dollarpercent)
    {
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "no name to bind and show after $%%");
      if (!nobuild)
        {
          if (tok.tok_kind == plex_NAMEDOBJ)
            _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
          else
            _.name = tok.tok_cname;
          ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
          browse_named_value_gui_BM (_.name, _.targobj,
                                     BMP_gtk_browse_value, browserdepth_BM,
                                     CURFRAME_BM);
          log_begin_message_BM ();
          log_printf_message_BM ("bound name $%s to object ",
                                 bytstring_BM (_.name));
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        };
    }
  //
  // !^ <space> # to move to given space
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamcaret)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "missing target for !^");
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind == plex_LLONG && tok.tok_llong >= 0
          && tok.tok_llong < LASTSPACE__BM)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, tok.tok_llong);
              log_begin_message_BM ();
              log_printf_message_BM ("put in space#%d object ",
                                     (int) tok.tok_llong);
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ *   to make global
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_star)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, GlobalSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in global space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ :   to make userA
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_colon)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, UserASp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in userA space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ ;   to make userB
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_semicolon)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, UserBSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in userB space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ %   to make transient
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_percent)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, TransientSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in transient space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ !$   to make predefined
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamdollar)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, PredefSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in predefined space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      else
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos, "bad space for !^");
    }
  else
    return false;
  return true;
}                               /* end parseobjectcompl_guicmd_BM */



// parse inside $(....)
value_tyBM
parsvalexp_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                      unsigned colpos, int depth,
                      struct stackframe_stBM *stkf)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM resval;
                 value_tyBM srcval;
                 objectval_tyBM * obj; objectval_tyBM * obsel;
                 objectval_tyBM * parsob; objectval_tyBM * obattr;
                 closure_tyBM * clos; value_tyBM otherval;
                 const stringval_tyBM * name; value_tyBM args[MAXARGS_BM];
    );
  _.parsob = checkedparserowner_BM (pars);
  unsigned srclineno = parserlineno_BM (pars);
  unsigned srccolpos = parsercolpos_BM (pars);
  bool gotsrcval = false;
  _.srcval = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotsrcval);
  if (!gotsrcval)
    parsererrorprintf_BM (pars, CURFRAME_BM, srclineno,
                          srccolpos, "expecting source value in $(...)");
  struct parstoken_stBM tok = {
  };
  for (;;)
    {
      parserskipspaces_BM (pars, CURFRAME_BM);
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightparen)
        {
          parsnesting_guicmd_BM (pars, depth, delim_dollarleftparen,
                                 lineno, colpos, delim_rightparen,
                                 parserlineno_BM (pars),
                                 parsercolpos_BM (pars));
          return _.srcval;
        }
      //
      // !> <obselector> ( ...) # to send a message for its result
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_exclamgreater)
        {
          unsigned arglineno = pars->pars_lineno;
          unsigned argcolpos = pars->pars_colpos;
          if (!nobuild && !_.srcval)
            parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                                  colpos, "missing target for !>");
          bool gotsel = false;
          _.obsel = parsergetobject_BM (pars,   //
                                        CURFRAME_BM,    //
                                        0, &gotsel);
          if (!gotsel)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  arglineno, argcolpos,
                                  "missing selector after !>");
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  arglineno, argcolpos,
                                  "missing left paren after selector for !>");
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars, CURFRAME_BM,     //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  arglineno, argcolpos,
                                  "missing right paren after selector for !>");
          if (!nobuild)
            {
              bool failsend = false;
              switch (nbarg)
                {
                case 0:
                  _.resval = send0_BM (_.srcval, _.obsel, CURFRAME_BM);
                  break;
                case 1:
                  _.resval =
                    send1_BM (_.srcval, _.obsel, CURFRAME_BM, _.args[0]);
                  break;
                case 2:
                  _.resval =
                    send2_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0], _.args[1]);
                  break;
                case 3:
                  _.resval =
                    send3_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0], _.args[1], _.args[2]);
                  break;
                case 4:
                  _.resval =
                    send4_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0],
                              _.args[1], _.args[2], _.args[3]);
                  break;
                case 5:
                  _.resval =
                    send5_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4]);
                  break;
                case 6:
                  _.resval =
                    send6_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5]);
                  break;
                case 7:
                  _.resval =
                    send7_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5], _.args[6]);
                  break;
                case 8:
                  _.resval =
                    send8_BM (_.srcval, _.obsel,
                              CURFRAME_BM, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5], _.args[6], _.args[7]);
                  break;
                default:
                  _.resval = NULL;
                  failsend = true;
                  break;
                }
              if ((_.resval == NULL) || failsend)
                {
                  char selidbuf[32];
                  const char *selname = findobjectname_BM (_.obsel);
                  idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
                  parsererrorprintf_BM (pars, CURFRAME_BM,
                                        arglineno, argcolpos,
                                        "failed to send %s",
                                        selname ? : selidbuf);
                }
              log_begin_message_BM ();
              log_puts_message_BM ("sent message ");
              log_object_message_BM (_.obsel);
              log_printf_message_BM (" with %d arguments to value.", nbarg);
              log_end_message_BM ();
            }
        }                       // end !> 
      //
      //  ( ...) # to apply a functon
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftparen)
        {
          unsigned arglineno = pars->pars_lineno;
          unsigned argcolpos = pars->pars_colpos;
          if (!nobuild && !isclosure_BM (_.srcval))
            parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                                  colpos,
                                  "source value is not a closure for application");
          _.clos = (closure_tyBM *) _.srcval;
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars, CURFRAME_BM,     //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  arglineno, argcolpos,
                                  "missing right paren after application");
          if (!nobuild)
            {
              bool failapply = false;
              switch (nbarg)
                {
                case 0:
                  _.resval = apply0_BM (_.clos, CURFRAME_BM);
                  break;
                case 1:
                  _.resval = apply1_BM (_.clos, CURFRAME_BM, _.args[0]);
                  break;
                case 2:
                  _.resval =
                    apply2_BM (_.clos, CURFRAME_BM, _.args[0], _.args[1]);
                  break;
                case 3:
                  _.resval =
                    apply3_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2]);
                  break;
                case 4:
                  _.resval =
                    apply4_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3]);
                  break;
                case 5:
                  _.resval =
                    apply5_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4]);
                  break;
                case 6:
                  _.resval =
                    apply6_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5]);
                  break;
                case 7:
                  _.resval =
                    apply7_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6]);
                  break;
                case 8:
                  _.resval =
                    apply8_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6], _.args[7]);
                  break;
                case 9:
                  _.resval =
                    apply9_BM (_.clos, CURFRAME_BM,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6], _.args[7],
                               _.args[8]);
                  break;
                default:
                  _.resval = NULL;
                  failapply = true;
                  break;
                }
              if ((_.resval == NULL) || failapply)
                {
                  char selidbuf[32];
                  idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
                  parsererrorprintf_BM (pars, CURFRAME_BM,
                                        arglineno, argcolpos,
                                        "failed to apply with %d arguments",
                                        nbarg);
                }
              log_begin_message_BM ();
              log_printf_message_BM ("applied with %d arguments to value.",
                                     nbarg);
              log_end_message_BM ();
              _.srcval = _.resval;
            }
        }                       // end application ( ... )
      //
      // !. <obattr> # to get an attribute
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamdot)
        {
          bool gotattr = false;
          parserskipspaces_BM (pars, CURFRAME_BM);
          unsigned atlineno = parserlineno_BM (pars);
          unsigned atcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  atlineno, atcolpos, "non object before !.");
          _.obattr =
            parsergetobject_BM (pars, CURFRAME_BM, depth + 1, &gotattr);
          if (!gotattr)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  atlineno, atcolpos,
                                  "expecting object attribute after !.");
          if (!nobuild)
            {
              _.resval =
                objgetattr_BM ((objectval_tyBM *) _.srcval, _.obattr);
              log_begin_message_BM ();
              log_puts_message_BM ("got attribute ");
              log_object_message_BM (_.obsel);
              log_puts_message_BM (" from value object ");
              log_object_message_BM ((objectval_tyBM *) _.srcval);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }                       /* end !. */
      //
      // !@ <index> # to get a component
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamat)
        {
          bool gotindex = false;
          parserskipspaces_BM (pars, CURFRAME_BM);
          unsigned ixlineno = parserlineno_BM (pars);
          unsigned ixcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  ixlineno, ixcolpos, "non object before !@");
          _.otherval =
            parsergetvalue_BM (pars, CURFRAME_BM, depth + 1, &gotindex);
          if (!gotindex)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  ixlineno, ixcolpos,
                                  "expecting index value after !@");
          if (!nobuild)
            {
              if (!istaggedint_BM (_.otherval))
                parsererrorprintf_BM (pars, CURFRAME_BM,
                                      ixlineno, ixcolpos,
                                      "expecting integer index after !@");
              _.resval =
                objgetcomp_BM ((objectval_tyBM *) _.srcval,
                               getint_BM (_.otherval));
              log_begin_message_BM ();
              log_printf_message_BM
                ("got component #%ld from object value ",
                 (long) getint_BM (_.otherval));
              log_object_message_BM ((objectval_tyBM *) _.srcval);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }                       /* end !@ */
      //
      // $% <name> # to show and bind to name
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_dollarpercent)
        {
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                                  colpos,
                                  "no name to bind and show after $%%");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
              browse_named_value_gui_BM (_.name, _.srcval,
                                         BMP_gtk_browse_value,
                                         browserdepth_BM, CURFRAME_BM);
              log_begin_message_BM ();
              log_printf_message_BM ("bound and show name $%s to value.",
                                     bytstring_BM (_.name));
              log_end_message_BM ();
            };
        }
      //
      // otherwise error
      else
        parsererrorprintf_BM (pars, CURFRAME_BM,
                              parserlineno_BM (pars), parsercolpos_BM (pars),
                              "unexpected token in $(...)");
    }                           /* end for (;;) */
  return NULL;
}                               /* end parsvalexp_guicmd_BM */


// expand readmacro-s
value_tyBM parsreadmacroexp_guicmd_BM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, int depth,
   const node_tyBM * nod, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM resval; const node_tyBM * nod; value_tyBM crm;
                 const objectval_tyBM * conn; objectval_tyBM * parsob;);
  _.parsob = checkedparserowner_BM (pars);
  _.nod = nod;
  if (depth > MAXDEPTHPARSE_BM)
    parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos,
                          "too deep %d readmacro", depth);
  ASSERT_BM (isnode_BM ((const value_tyBM) nod));
  _.conn = nodeconn_BM ((const value_tyBM) _.nod);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.conn));
  _.crm = objgetattr_BM (_.conn, BMP_command_readmacro);
  if (!isclosure_BM ((const value_tyBM) _.crm))
    {
      char crmidbuf[32];
      memset (crmidbuf, 0, sizeof (crmidbuf));
      idtocbuf32_BM (objid_BM (_.crm), crmidbuf);
      const char *crmname = findobjectname_BM (_.crm);
      if (crmname)
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos,
                              "readmacro ^ %s |=%s| has bad `command_readmacro` attribute",
                              crmidbuf, crmname);
      else
        parsererrorprintf_BM (pars, CURFRAME_BM, lineno,
                              colpos,
                              "readmacro ^ %s has bad `command_readmacro` attribute",
                              crmidbuf);
    }
  _.resval =                    //
    apply4_BM (_.crm, CURFRAME_BM,
               (value_tyBM) _.nod,
               taggedint_BM (lineno), taggedint_BM (colpos), _.parsob);
  return _.resval;
}                               /* end parsreadmacroexp_guicmd_BM */



// parse inside $[...]
const objectval_tyBM *
parsobjexp_guicmd_BM (struct parser_stBM *pars,
                      unsigned lineno, unsigned colpos,
                      int depth, struct stackframe_stBM *stkf)
{
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * obj; const stringval_tyBM * namev;
                 objectval_tyBM * oldnamedob; value_tyBM val;
    );
  ASSERT_BM (isparser_BM (pars));
  parserskipspaces_BM (pars, CURFRAME_BM);
  unsigned oblineno = parserlineno_BM (pars);
  unsigned obcolpos = parsercolpos_BM (pars);
  bool gotobj = false;
  struct parstoken_stBM tok = parsertokenget_BM (pars, CURFRAME_BM);
  // * <name> to create a new (userE) named object
  // !* <name> to create a new (global) named object
  if (tok.tok_kind == plex_DELIM
      && (tok.tok_delim == delim_exclamstar || tok.tok_delim == delim_star))
    {
      bool isglobal = (tok.tok_delim == delim_exclamstar);
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind == plex_CNAME)
        {
          _.namev = tok.tok_cname;
        }
      else if (tok.tok_kind == plex_NAMEDOBJ)
        {
          _.oldnamedob = tok.tok_namedobj;
        }
      else
        parsererrorprintf_BM (pars, CURFRAME_BM, oblineno,
                              obcolpos,
                              "expecting name after * or !* in $[...]");
      gotobj = true;
      if (!nobuild)
        {
          if (_.namev)
            {
              _.obj = makeobj_BM ();
              objtouchnow_BM (_.obj);
              objputspacenum_BM (_.obj, isglobal ? GlobalSp_BM : UserEsp_BM);
              registername_BM (_.obj, bytstring_BM (_.namev));
              log_begin_message_BM ();
              log_puts_message_BM (isglobal
                                   ? "created global named object "
                                   : "created userE named object ");
              log_object_message_BM (_.obj);
              log_end_message_BM ();
            }
          else if (_.oldnamedob)
            {
              _.obj = _.oldnamedob;
              log_begin_message_BM ();
              log_puts_message_BM ("reusing named object ");
              log_object_message_BM (_.obj);
              log_end_message_BM ();
            }
          else
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  oblineno, obcolpos,
                                  "expecting some name after * or !* in $[...]");
        }
    }
  // : to create a new transient anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_colon)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, TransientSp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created transient anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  // ~ to create a new global anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_tilde)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, GlobalSp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created global anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  // % to create a new (userE) anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_percent)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, UserEsp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created userE anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  //
  // $:<var>
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_dollarcolon)
    {
      parserseek_BM (pars, oblineno, obcolpos);
      _.obj = parsergetobject_BM (pars, CURFRAME_BM, 0, &gotobj);
      if (!gotobj)
        parsererrorprintf_BM (pars, CURFRAME_BM, oblineno,
                              obcolpos, "expecting $:<var> in $[...]");
    }
  //
  // ( <expr> ) to cast a value into an object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftparen)
    {
      bool gotval = false;
      _.val = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, CURFRAME_BM, oblineno,
                              obcolpos, "expecting value after $[ (");
      tok = parsertokenget_BM (pars, CURFRAME_BM);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, CURFRAME_BM,
                              pars->pars_lineno,
                              pars->pars_colpos,
                              "expecting right paren after $[ ( started at L%d:C%d",
                              oblineno, obcolpos);
      if (!nobuild && !isobject_BM (_.val))
        parsererrorprintf_BM (pars, CURFRAME_BM,
                              oblineno,
                              obcolpos, "non-object value after $[ (...");
    }
  //
  // <id> or <name> to refer to an existing object
  else if (tok.tok_kind == plex_ID || tok.tok_kind == plex_NAMEDOBJ)
    {
      parserseek_BM (pars, oblineno, obcolpos);
      _.obj = parsergetobject_BM (pars, CURFRAME_BM, 0, &gotobj);
    }
  if (!gotobj)
    parsererrorprintf_BM (pars, CURFRAME_BM, oblineno,
                          obcolpos, "expecting object at start of $[...]");
  while ((tok =
          parsertokenget_BM (pars, CURFRAME_BM)), tok.tok_kind != plex__NONE)
    {
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightbracket)
        {
          parsnesting_guicmd_BM (pars, depth, delim_dollarleftbracket,
                                 lineno, colpos, delim_rightbracket,
                                 parserlineno_BM (pars),
                                 parsercolpos_BM (pars));
          return _.obj;
        }
      bool gotcomp = parseobjectcompl_guicmd_BM (pars, _.obj, depth,
                                                 CURFRAME_BM,
                                                 &tok);
      if (!gotcomp)
        parsererrorprintf_BM (pars, CURFRAME_BM,
                              pars->pars_lineno, pars->pars_colpos,
                              "bad object complement (for $[...] started L%d:C%d",
                              oblineno, obcolpos);
      if (!nobuild)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("updated object ");
          log_object_message_BM (_.obj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
      return _.obj;
    };
  parsererrorprintf_BM (pars, CURFRAME_BM,
                        pars->pars_lineno, pars->pars_colpos,
                        "invalid object expression for $[...] started L%d:C%d",
                        oblineno, obcolpos);
}                               /* end parsobjexp_guicmd_BM */


////////////////
void
parsecommandbuf_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf)
{
  if (!isparser_BM (pars))
    return;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM comp; objectval_tyBM * obj;
                 objectval_tyBM * parsob; objectval_tyBM * oldfocusobj;
                 const stringval_tyBM * name; const stringval_tyBM * result;);
  _.parsob = checkedparserowner_BM (pars);
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  int nbloop = 0;
  for (;;)
    {
      parserskipspaces_BM (pars, CURFRAME_BM);
      if (nbloop++ > MAXSIZE_BM / 32)
        parsererrorprintf_BM (pars, CURFRAME_BM,
                              pars->pars_lineno, pars->pars_colpos,
                              "too many %d loops", nbloop);
      if (parserendoffile_BM (pars))
        break;
      unsigned curlineno = parserlineno_BM (pars);
      unsigned curcolpos = parsercolpos_BM (pars);
      parstoken_tyBM tok = parsertokenget_BM (pars, CURFRAME_BM);
      //// double semicolon stops the parsing and skip the rest
      if (tok.tok_kind == plex_DELIM
          && tok.tok_delim == delim_doublesemicolon)
        {
          unsigned toklin = tok.tok_line;
          unsigned tokcol = tok.tok_col;
          GtkTextIter skipit = EMPTY_TEXT_ITER_BM;
          GtkTextIter endit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_line (commandbuf_BM, &skipit, toklin);
          gtk_text_iter_forward_chars (&skipit, tokcol);
          gtk_text_buffer_get_end_iter (commandbuf_BM, &endit);
          gtk_text_buffer_apply_tag (commandbuf_BM, skipped_cmdtag_BM,
                                     &skipit, &endit);
          break;
        }
      // object complement applies to focus
      if (tok.tok_kind == plex_DELIM
          && (tok.tok_delim == delim_exclamand
              || tok.tok_delim == delim_exclamcolon
              || tok.tok_delim == delim_exclamdollar
              || tok.tok_delim == delim_exclamgreater
              || tok.tok_delim == delim_exclamminus
              || tok.tok_delim == delim_exclamcaret))
        {

          if (!browserbuf_BM)
            {
              browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          if (!nobuild && !isobject_BM (GLOBAL_BM (gui_focus_obj)))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no focus object to complement");
          if (!parseobjectcompl_guicmd_BM
              (pars, (objectval_tyBM *) GLOBAL_BM (gui_focus_obj), 0,
               CURFRAME_BM, &tok))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "invalid focus complement");
          if (!nobuild)
            {
              struct browsedobj_stBM *brfocusob =
                find_browsed_object_BM (GLOBAL_BM (gui_focus_obj));
              ASSERT_BM (brfocusob != NULL);
              browse_object_gui_BM (GLOBAL_BM (gui_focus_obj),
                                    BMP_gtk_browse_in_object,
                                    brfocusob->brow_odepth, CURFRAME_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("[re-]browsing object ");
              log_object_message_BM (GLOBAL_BM (gui_focus_obj));
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      //
      // ?* <object> # to focus and display an object
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionstar)
        {

          if (!browserbuf_BM)
            {
              browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, CURFRAME_BM,        //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no new focus object after ?*");
          if (!nobuild)
            {
              _.oldfocusobj = GLOBAL_BM (gui_focus_obj);
              struct browsedobj_stBM *broldfocusob =
                find_browsed_object_BM (_.oldfocusobj);
              GLOBAL_BM (gui_focus_obj) = _.obj;
              if (_.obj)
                {
                  browse_object_gui_BM (GLOBAL_BM (gui_focus_obj),
                                        BMP_gtk_browse_in_object,
                                        browserdepth_BM, CURFRAME_BM);
                  log_begin_message_BM ();
                  log_puts_message_BM ("showing and focusing object ");
                  log_object_message_BM (GLOBAL_BM (gui_focus_obj));
                  log_printf_message_BM (" at depth %d.", browserdepth_BM);
                  log_end_message_BM ();
                }
              if (broldfocusob && _.oldfocusobj != _.obj)
                {
                  browse_object_gui_BM (_.oldfocusobj,
                                        BMP_gtk_browse_in_object,
                                        broldfocusob->brow_odepth,
                                        CURFRAME_BM);
                  log_begin_message_BM ();
                  log_puts_message_BM ("defocusing object ");
                  log_object_message_BM (_.oldfocusobj);
                  log_puts_message_BM (".");
                  log_end_message_BM ();
                }
            }
        }
      //
      // ?. <object> # to display an object without focusing on it
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questiondot)
        {
          if (!browserbuf_BM)
            {
              browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, CURFRAME_BM,        //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no displayed object after ?.");
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos, "no browser buffer");
          if (!nobuild)
            {
              browse_object_gui_BM (_.obj,
                                    BMP_gtk_browse_in_object,
                                    browserdepth_BM, CURFRAME_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("displaying object ");
              log_object_message_BM (_.obj);
              log_printf_message_BM (" at depth %d.", browserdepth_BM);
              log_end_message_BM ();
            }
        }
      //
      // <id>, <name>, $[...], $:<obj> is displaying an object without focus
      else if (tok.tok_kind == plex_ID || tok.tok_kind == plex_NAMEDOBJ
               || (tok.tok_kind == plex_DELIM
                   && (tok.tok_delim == delim_dollarcolon
                       || tok.tok_delim == delim_dollarleftbracket)))
        {

          if (!browserbuf_BM)
            {
              browserbuf_BM = newgui_get_browsebuf_BM ();
            };
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos, "no browser buffer");
          bool gotobject = false;
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.obj = parsergetobject_BM (pars, CURFRAME_BM,        //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "expecting object to display");
          if (!nobuild)
            {
              browse_object_gui_BM (_.obj,
                                    BMP_gtk_browse_in_object,
                                    browserdepth_BM, CURFRAME_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("displaying object ");
              log_object_message_BM (_.obj);
              log_printf_message_BM (" at depth %d.", browserdepth_BM);
              log_end_message_BM ();
            }
        }
      //
      // ?- <object> # to hide an object
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionstar)
        {
          if (!browserbuf_BM)
            {
              browserbuf_BM = newgui_get_browsebuf_BM ();
            };
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos, "no browser buffer");
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, CURFRAME_BM,        //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no object to hide after ?-");
          if (!nobuild)
            {
              if (_.obj == GLOBAL_BM (gui_focus_obj))
                GLOBAL_BM (gui_focus_obj) = NULL;
              hide_object_gui_BM (_.obj, CURFRAME_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("hiding object ");
              log_object_message_BM (_.obj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      //
      // ?$ <name> <value> # to display and bind a named value
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_questiondollar)
        {
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no name to bind and show after ?$");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
            };
          bool gotval = false;
          _.comp = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no value to bind and show after ?$");
          if (!nobuild)
            {
              if (_.comp)
                {
                  log_begin_message_BM ();
                  log_printf_message_BM
                    ("binding & showing named value $%s at depth %d.",
                     bytstring_BM (_.name), browserdepth_BM);
                  log_end_message_BM ();
                  browse_named_value_gui_BM (_.name, _.comp,
                                             BMP_gtk_browse_value,
                                             browserdepth_BM, CURFRAME_BM);
                }
              else
                {
                  log_begin_message_BM ();
                  log_printf_message_BM ("hiding named value $%s.",
                                         bytstring_BM (_.name));
                  log_end_message_BM ();
                  hide_named_value_gui_BM (_.name, CURFRAME_BM);
                }
            }
        }
      // ?$- <name>  # to hide and unbind a named value
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_questiondollar)
        {
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no name to hide after ?$-");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
              if (!find_browsed_named_value_BM (bytstring_BM (_.name)))
                parsererrorprintf_BM (pars, CURFRAME_BM,
                                      curlineno, curcolpos,
                                      "name %s is not of a shown value",
                                      bytstring_BM (_.name));
              hide_named_value_gui_BM (_.name, CURFRAME_BM);
              log_begin_message_BM ();
              log_printf_message_BM ("hiding named value $%s.",
                                     bytstring_BM (_.name));
              log_end_message_BM ();
            };
        }
      //
      // ?# <depth> # to change the browse depth
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionhash)
        {
          tok = parsertokenget_BM (pars, CURFRAME_BM);
          if (tok.tok_kind != plex_LLONG)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "?# should be followed by browse depth number");
          int newdepth = browserdepth_BM;
          if (tok.tok_llong < 2)
            newdepth = 2;
          else if (tok.tok_llong > BROWSE_MAXDEPTH_BM)
            newdepth = BROWSE_MAXDEPTH_BM;
          else
            newdepth = (int) tok.tok_llong;
          if (!nobuild)
            {
              log_begin_message_BM ();
              log_printf_message_BM ("changing browse depth to %d.",
                                     newdepth);
              log_end_message_BM ();
              browserdepth_BM = newdepth;
            }
        }
      // various value-starting delimiters
      else if (tok.tok_kind == plex_DELIM
               && (tok.tok_delim == delim_hashleftbrace
                   || tok.tok_delim == delim_leftbracket
                   || tok.tok_delim == delim_leftbrace
                   || tok.tok_delim == delim_tildecolon
                   || tok.tok_delim == delim_star
                   || tok.tok_delim == delim_percent
                   || tok.tok_delim == delim_caret
                   || tok.tok_delim == delim_dollar
                   || tok.tok_delim == delim_dollarcolon
                   || tok.tok_delim == delim_dollarleftbracket
                   || tok.tok_delim == delim_dollarleftparen))
        {
          bool gotval = false;
          if (!_.result)
            _.result = makestring_BM ("result");
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.comp = parsergetvalue_BM (pars, CURFRAME_BM, 0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, CURFRAME_BM,
                                  curlineno, curcolpos,
                                  "no value to display as $result after $(");
          if (!nobuild)
            {
              if (_.comp)
                {
                  log_begin_message_BM ();
                  log_printf_message_BM
                    ("binding & showing $result at depth %d.",
                     browserdepth_BM);
                  log_end_message_BM ();
                  browse_named_value_gui_BM (_.result, _.comp,
                                             BMP_gtk_browse_value,
                                             browserdepth_BM, CURFRAME_BM);
                }
              else
                parsererrorprintf_BM (pars, CURFRAME_BM,
                                      curlineno, curcolpos,
                                      "no result to display after $(");
            }
        }
      //
      else
        parsererrorprintf_BM (pars, CURFRAME_BM, curlineno,
                              curcolpos, "unexpected command");
    }
}                               /* end parsecommandbuf_BM */


void
parscommentinside_guicmd_BM (struct parser_stBM *pars,
                             unsigned lineno, unsigned colpos,
                             unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentinside_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentinside_guicmd_BM */


void
parscommentsign_guicmd_BM (struct parser_stBM *pars,
                           unsigned lineno, unsigned colpos, unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentsign_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentsign_guicmd_BM */

void
parsdelim_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                     unsigned colpos, unsigned delimlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, delimlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, delim_cmdtag_BM, &it, &endit);
}                               /* end parsdelim_guicmd_BM */

void
parsknowname_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                        unsigned colpos, unsigned namlen)
{
  char *buf = NULL;
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsknownname L%uC%u w%u: '%s'", lineno, colpos, namlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, knowname_cmdtag_BM, &it, &endit);
}                               /* end parsknowname_guicmd_BM */


void
parsnewname_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                       unsigned colpos, unsigned namlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, newname_cmdtag_BM, &it, &endit);
}                               /* end parsnewname_guicmd_BM */

// decorate numbers
void
parsnumber_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                      unsigned colpos, unsigned numlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, numlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsnumbergui L%uC%u w%u: '%s'", lineno, colpos, numlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, number_cmdtag_BM, &it, &endit);
}                               /* end parsnumber_guicmd_BM  */


// decorate string signs, notably outside quotes
void
parsstringsign_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                          unsigned colpos, unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsstringsign L%uC%u w%u: '%s'", lineno, colpos, signlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, stringsign_cmdtag_BM, &it,
                             &endit);
}                               /* end parsstringsign_guicmd_BM */


// decorate string inside characters
void
  parsstringinside_guicmd_BM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsstringinside L%uC%u w%u: '%s'", lineno, colpos,
                  signlen, (buf =
                            gtk_text_buffer_get_text (commandbuf_BM, &it,
                                                      &endit, false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, stringinside_cmdtag_BM, &it,
                             &endit);
}                               /* end parsstringinside_guicmd_BM */


void
parsid_guicmd_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
                  unsigned idlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, idlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, id_cmdtag_BM, &it, &endit);
}                               /* end parsid_guicmd_BM */


void
parsnesting_guicmd_BM (struct parser_stBM *pars, int depth,
                       enum lexdelim_enBM opendelim,
                       unsigned openlinpos, unsigned opencolpos,
                       enum lexdelim_enBM closedelim,
                       unsigned closelinpos, unsigned closecolpos)
{
  ASSERT_BM (isparser_BM (pars));
  ASSERT_BM (openlinpos > 0 && closelinpos > 0 && openlinpos <= closelinpos);
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter openit = EMPTY_TEXT_ITER_BM, endopenit = EMPTY_TEXT_ITER_BM;
  GtkTextIter closeit = EMPTY_TEXT_ITER_BM, stacloseit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos - 1);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               open_cmdtags_BM[depth], &openit, &endopenit);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &stacloseit,
                                    closelinpos - 1);
  gtk_text_iter_forward_chars (&stacloseit, closecolpos);
  closeit = stacloseit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_iter_forward_chars (&closeit, closelen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               close_cmdtags_BM[depth],
                               &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,.paroff_close = closeoff + closelen,
    .paroff_xtra = -1,
    .paroff_openlen = openlen,.paroff_closelen = closelen,
    .paroff_xtralen = 0,.paroff_depth = depth
  };
  cmd_add_parens_BM (&po);
  return;
}                               /* end parsnesting_guicmd_BM */


void
parsstartnesting_guicmd_BM (struct parser_stBM *pars, int depth,
                            enum lexdelim_enBM xtradelim,
                            unsigned xtralinpos,
                            unsigned xtracolpos,
                            enum lexdelim_enBM opendelim,
                            unsigned openlinpos,
                            unsigned opencolpos,
                            enum lexdelim_enBM closedelim,
                            unsigned closelinpos, unsigned closecolpos)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *xtradelstr = delimstr_BM (xtradelim);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter xtrait = EMPTY_TEXT_ITER_BM, endxtrait = EMPTY_TEXT_ITER_BM;
  GtkTextIter openit = EMPTY_TEXT_ITER_BM, endopenit = EMPTY_TEXT_ITER_BM;
  GtkTextIter closeit = EMPTY_TEXT_ITER_BM, stacloseit = EMPTY_TEXT_ITER_BM;
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &xtrait, xtralinpos - 1);
  gtk_text_iter_forward_chars (&xtrait, xtracolpos);
  endxtrait = xtrait;
  int xtraoff = gtk_text_iter_get_offset (&xtrait);
  int xtralen = g_utf8_strlen (xtradelstr, -1);
  gtk_text_iter_forward_chars (&endxtrait, xtralen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &xtrait, &endxtrait);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               xtra_cmdtags_BM[depth], &xtrait, &endxtrait);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos - 1);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               open_cmdtags_BM[depth], &openit, &endopenit);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &stacloseit,
                                    closelinpos - 1);
  gtk_text_iter_forward_chars (&stacloseit, closecolpos);
  closeit = stacloseit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  gtk_text_iter_forward_chars (&closeit, closelen);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               close_cmdtags_BM
                               [depth], &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,.paroff_close = closeoff + closelen,.paroff_xtra =
      xtraoff,.paroff_openlen = openlen,.paroff_closelen =
      closelen,.paroff_xtralen = xtralen,.paroff_depth = depth
  };
  cmd_add_parens_BM (&po);
}                               /* end parsstartnesting_guicmd_BM */

/************ end of file guiparse_GTKBM.c ********************/
