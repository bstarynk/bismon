/// file progoptions_BM.h
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

    This file progoptions_BM.h is #included twice only from main_BM.c
    to fill some GOptionEntry optionstab_bm array...

    ----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
***/

#ifndef BISMON_MAKING_C_main
#error progoptions_BM.h can only be included from main_BM.c
#endif /*BISMON_MAKING_C_main*/

#ifndef BISMONPROG_LONG_OPTION
#define BISMONPROG_LONG_OPTION(Lopt) Lopt
#endif /*BISMONPROG_LONG_OPTION*/

#ifndef BISMONPROG_SHORT_OPTION
#define BISMONPROG_SHORT_OPTION(Shopt) Shopt
#endif /*BISMONPROG_SHORT_OPTION*/

  //
  {.long_name = BISMONPROG_LONG_OPTION("load"),         //
   .short_name = BISMONPROG_SHORT_OPTION('l'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &load_dir_bm,
   .description = "load persistent heap from directory DIR\n"
   "\t .... (default is the current working directory)",
   .arg_description = "DIR"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("dump"),         //
   .short_name = BISMONPROG_SHORT_OPTION('d'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_dir_BM,
   .description = "dump persistent heap into directory DIR",
   .arg_description = "DIR"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("dump-after-load"),      //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &dump_after_load_dir_bm,
   .description = "dump after load the persistent heap into directory DIR",
   .arg_description = "DIR"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("contributors-file"),    //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &contributors_filepath_BM,
   .description = "use PATH as the contributors file;\n"
   "\t .. default is contributors_BM or $HOME/contributors_BM",
   .arg_description = "PATH"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("passwords-file"),       //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &passwords_filepath_BM,
   .description = "use PATH as the password file;\n"
   "\t .. default is passwords_BM or $HOME/passwords_BM",
   .arg_description = "PATH"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("contact-file"), //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &contact_filepath_BM,
   .description = "use PATH as the master contact file;\n"
   "\t .. default is contact_BM or $HOME/contact_BM",
   .arg_description = "PATH"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("temporary-dir"),        //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &temporary_dir_BM,
   .description =
   "If given a directory TEMPORARY_DIR\n"
   "\t will create files in it, otherwise create some under /var/tmp\n",
   .arg_description = "TEMPORARY_DIR"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("sigusr1-dump-prefix"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &sigusr1_dump_prefix_BM,
   .description =
   "If given a directory prefix DUMP_PREFIX,\n"
   "\t ... every recieved SIGUSR1 signal dumps the state into it.\n"
   "\t For example --sigusr1-dump-prefix=/tmp/dumpBM will make the\n"
   "\t ... first dump into /tmp/dumpBM1/,  and then\n"
   "\t ... the second dump into /tmp/dumpBM2/ etc...\n",
   .arg_description = "DUMP_PREFIX"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("add-passwords"),        //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &added_passwords_filepath_BM,
   .description =
   "Use the given PASSWORDENTRIES file (if it is -, stdin) \n"
   "\t ... containing lines like <username>:<password> to add passwords",
   .arg_description = "PASSWORDENTRIES"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("add-password-comment"), //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &password_file_comment_BM,
   .description =
   "append a single comment line PASSWORDCOMMENT to the password\n"
   "\t .... file.",
   .arg_description = "PASSWORDCOMMENT"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("emit-has-predef"),      //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &count_emit_has_predef_bm,
   .description = "emit NB 'HAS_PREDEF_BM'",
   .arg_description = "NB"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("job"),          //
   .short_name = BISMONPROG_SHORT_OPTION('j'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &nbworkjobs_BM,
   .description = "number of worker threads NBJOBS (>=2, <16)",
   .arg_description = "NBJOBS"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("unix-json-socket"),        //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &unix_json_socket_BM,
   .description =
   "Use the given JSONSOCKET file \n"
   "\t ... as the unix(7) socket for JSONRPC protocol",
   .arg_description = "JSONSOCKET"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("random-seed"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_INT,
   .arg_data = &randomseed_BM,
   .description = "set the initial PRNG seed for g_random_int to given SEED",
   .arg_description = "SEED"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("sleep-delay"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_DOUBLE,
   .arg_data = &sleepdelay_bm,
   .description = " sleep the given DELAY (in seconds) at start, after load ",
   .arg_description = " DELAY "},
  //
  {.long_name = BISMONPROG_LONG_OPTION("pid-file"),     //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &pid_filepath_bm,
   .description = " use PATH as the pid file where our pid is written; \n"
   " \t ... default is _bismon.pid; \n"
   " \t (if the pid file exists and does not start with a dot or percent, \n"
   " \t and mentions a valid pid, its process, \n"
   " \t presumably some other Bismon process, \n"
   " \t gets a SIGQUIT signal, and has one second to dump its state) ",
   .arg_description = "PATH"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("run-command"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &run_command_bm,
   .description = " run the command CMD ",
   .arg_description = " CMD "},
  //
  {.long_name = BISMONPROG_LONG_OPTION("project-name"), //
   .short_name = BISMONPROG_SHORT_OPTION('P'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &set_project_name_bm,
   .description = " define the project name ",
   .arg_description = " PROJECT_NAME "},
  //
  {.long_name = BISMONPROG_LONG_OPTION("init-after-load"),      //
   .short_name = BISMONPROG_SHORT_OPTION('i'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &handle_init_afterload_bm,
   .description = "do the <closure> after loading, as initialization",
   .arg_description = "<closure> (or object)"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("chdir-after-load"),     //
   .short_name = BISMONPROG_SHORT_OPTION('c'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_FILENAME,
   .arg_data = &chdir_after_load_bm,
   .description = "change directory after load to DIR (perhaps making it)",
   .arg_description = "DIR"},

  //
  {.long_name = BISMONPROG_LONG_OPTION("parse-value"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &get_parse_value_after_load_bm,
   .description = "parse (after loading) the value EXPR",
   .arg_description = "EXPR"},

  //
  {.long_name = BISMONPROG_LONG_OPTION("parse-file"),   //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &get_parse_file_after_load_bm,
   .description = " parse file (after loading) the file FILENAME ",
   .arg_description = " FILENAME "},

  //
  {.long_name = BISMONPROG_LONG_OPTION("test-plugin"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &get_testplugin_after_load_bm,
   .description =
   "run the drafts/testplugin_PLUGINAME.so (after loading) the test-plugin PLUGINAME",
   .arg_description = "PLUGINAME"},

  //
  {.long_name = BISMONPROG_LONG_OPTION("comment-predef"),       //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &comment_bm,
   .description = "set comment of next predefined to COMM",
   .arg_description = "COMM"},

  //
  {.long_name = BISMONPROG_LONG_OPTION("add-predef"),   //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &add_predef_bm,
   .description = "add new predefined named PREDEFNAME",
   .arg_description = "PREDEFNAME"},

  ////
  {.long_name = BISMONPROG_LONG_OPTION("contributor"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &add_contributor_bm,
   .description = "add or change contributor CONTRIBUTOR,\n"
   "\t like 'First Lastname <email@example.com>'\n"
   "\t or 'First Lastname;email@example.com;aliasmail@example.org'\n"
   "\t (this puts personal information relevant to European GDPR in file "
   CONTRIBUTORS_FILE_BM ")",
   .arg_description = "CONTRIBUTOR"},

  ////
  {.long_name = BISMONPROG_LONG_OPTION("print-contributor-of-oid"),     //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &print_contributor_of_oid_bm,
   .description =
   "print tab-separated: (full name, objid, email, alias) of contributor of given CONTRIBOID then exit,",
   .arg_description = "CONTRIBOID"},

  ////
  {.long_name = BISMONPROG_LONG_OPTION("remove-contributor"),   //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_CALLBACK,
   .arg_data = &remove_contributor_bm,
   .description = "remove existing contributor CONTRIBUTOR,\n"
   "\t like 'First Lastname'\n"
   "\t or email@example.com\n"
   "\t or some existing contributor oid similar to _2PFRochKb3N_3e8RFFAUi9K\n"
   "\t (this should remove personal information relevant to European GDPR in file "
   CONTRIBUTORS_FILE_BM ")",
   .arg_description = "CONTRIBUTOR"},
  ///
  {.long_name = BISMONPROG_LONG_OPTION("cleanup"),      //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &want_cleanup_bm,
   .description =
   "cleanup memory at end (for valgrind)\n"
   "\t ... (see valgrind.org for more).",
   .arg_description = NULL},
  ///
  ///
  {.long_name = BISMONPROG_LONG_OPTION("dont-indent"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &dont_indent_generated_code_BM,
   .description = "do not indent (using GNU indent) the generated C code",
   .arg_description = NULL},
  ///
  {.long_name = BISMONPROG_LONG_OPTION("final-gc"),     //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &want_finalgc_bm,
   .description =
   "forcibly run a final garbage collection (after any dump or event loop)",
   .arg_description = NULL},
  //
  //
  {.long_name = BISMONPROG_LONG_OPTION("batch"),        //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &batch_bm,
   .description = "run in batch mode without user interface",
   .arg_description = NULL},
  //
  {.long_name = BISMONPROG_LONG_OPTION("debug"), //
   .short_name = BISMONPROG_SHORT_OPTION('D'),
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = (bool *) &showdebugmsg_BM,
   .description = " gives lots of debug messages ",
   .arg_description = NULL},
  //
  {.long_name = BISMONPROG_LONG_OPTION("debug-after-load"),     //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &debug_after_load_BM,
   .description = "enable debug messages after load",
   .arg_description = NULL},
  //
  {.long_name = BISMONPROG_LONG_OPTION("emit-module"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &module_to_emit_bm,
   .description = "emit module MODULEOBJ",
   .arg_description = "MODULEOBJ"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("mailhtml-file"),        //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &mailhtml_file_bm,
   .description = " FILE is the file, in HTML, to be sent to contributor",
   .arg_description = "FILE"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("mailhtml-subject"),     //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &mailhtml_subject_bm,
   .description =
   " SUBJECT is the subject of the email to be sent to contributor",
   .arg_description = "SUBJECT"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("mailhtml-contributor"), //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &mailhtml_contributor_bm,
   .description = " CONTRIBUTOR is to whom the email will be sent",
   .arg_description = "CONTRIBUTOR"},
  //
  {.long_name = BISMONPROG_LONG_OPTION("mailhtml-attachment"),  //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_STRING,
   .arg_data = &mailhtml_attachment_bm,
   .description = " ATTACHEDFILE is the attached file of the email",
   .arg_description = "ATTACHEDFILE"},
  //
  //
  {.long_name = BISMONPROG_LONG_OPTION("version"),      //
   .short_name = (char) 0,
   .flags = G_OPTION_FLAG_NONE,
   .arg = G_OPTION_ARG_NONE,
   .arg_data = &give_version_bm,
   .description = "gives version information",
   .arg_description = NULL},
  //

#undef BISMONPROG_LONG_OPTION
#undef BISMONPROG_SHORT_OPTION


/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
  /* end of special included file progoptions_BM.h */
