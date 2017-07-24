// file load_BM.c
#include "bismon.h"

static gint
ld_cmp_BM (gconstpointer a, gconstpointer b,
           gpointer data __attribute__ ((unused)))
{
  if ((intptr_t) a < (intptr_t) b)
    return -1;
  if (a == b)
    return 0;
  return +1;
}                               /* end of ld_cmp_BM */

void
load_initial_BM (const char *ldirpath)
{
  fprintf (stderr, "should load from %s\n", ldirpath);
  if (!ldirpath)
    ldirpath = ".";
  DIR *ldir = opendir (ldirpath);
  if (!ldir)
    FATAL_BM ("load_initial failed to opendir %s : %m", ldirpath);
  struct dirent *de = NULL;
  GTree *trent = g_tree_new_full (ld_cmp_BM, NULL, NULL, free);
  while ((de = readdir (ldir)) != NULL)
    {
      if (!isalpha (de->d_name[0]))
        continue;
      int num = 0;
      int pos = 0;
      if (((sscanf (de->d_name, "store%d.bismon%n", &num, &pos) > 0
            && pos > 0)
           ||
           (sscanf (de->d_name, "store%d_%*[a-zA-Z0-9_].bismon%n", &num, &pos)
            > 0 && pos > 0)) && num > 0 && de->d_name[pos] == 0)
        {
          char *buf = NULL;
          if (asprintf (&buf, "%s/%s", ldirpath, de->d_name) > 0
              && buf != NULL)
            {
              struct stat fst = { };
              if (stat (buf, &fst))
                FATAL_BM ("failed to stat %s : %m", buf);
              if ((fst.st_mode & S_IFMT) != S_IFREG)
                FATAL_BM ("%s is not a plain file", buf);
              if (g_tree_lookup (trent, (void *) num))
                FATAL_BM ("duplicate store%d* entries in %s", num, ldirpath);
              g_tree_insert (trent, (void *) num, buf);
            }
        }
    }
  closedir (ldir);
  if (g_tree_nnodes (trent) == 0)
    FATAL_BM
      ("no file matching store[0-9]+.bismon or store[0-9]+_*.bismon in loaded directory %s",
       ldirpath);
  printf ("got %d store entries in loaded directory %s\n",
          (int) g_tree_nnodes (trent), ldirpath);
  /// should add to the agenda the first pass scanning then the second pass loading these files
}                               /* end load_initial_BM */
