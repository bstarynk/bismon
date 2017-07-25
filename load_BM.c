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
loadergcmark_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) ld) == tydata_loader_BM);
  assert (ld->ld_magic == LOADERMAGIC_BM);
  gcmark_BM (gc, ld->ld_hset, 0);
}                               /* end loadergcmark_BM */

static void doload_BM (struct stackframe_stBM *fr, struct loader_stBM *ld);

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
  char *todopath = NULL;
  int maxnum = 0;
  while ((de = readdir (ldir)) != NULL)
    {
      if (!isalpha (de->d_name[0]))
        continue;
      int num = 0;
      int pos = 0;
      if ((sscanf (de->d_name, "store%d.bismon%n", &num, &pos) > 0
           && pos > 0) && num > 0 && de->d_name[pos] == 0)
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
              // detect store12.bismon and store+12.bismon or store0012.bismon
              if (g_tree_lookup (trent, (void *) (intptr_t) num))
                FATAL_BM ("duplicate store%d* entries in %s", num, ldirpath);
              g_tree_insert (trent, (void *) (intptr_t) num, buf);
              if (num > maxnum)
                maxnum = num;
            }
          else
            FATAL_BM ("asprintf failure (%m)");
        }
      else if (!strcmp (de->d_name, "store_todo.bismon"))
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
            }
          else
            FATAL_BM ("asprintf failure (%m)");
          assert (todopath == NULL);
          todopath = buf;
        }
    }
  closedir (ldir);
  if (g_tree_nnodes (trent) == 0)
    FATAL_BM
      ("no file matching store[0-9]+.bismon or store[0-9]+_*.bismon in loaded directory %s",
       ldirpath);
  if (maxnum > 1024)
    FATAL_BM ("too many store files %d to load", maxnum);
  printf ("got %d store entries in loaded directory %s\n",
          (int) g_tree_nnodes (trent), ldirpath);
  struct loader_stBM *ld =      //
    allocgcty_BM (tydata_loader_BM, sizeof (struct loader_stBM));
  // ((typedhead_tyBM *) ld)->htyp = tydata_loader_BM;
  // ((typedhead_tyBM *) ld)->hgc = 0;
  ((typedhead_tyBM *) ld)->rlen = 0;
  ld->ld_magic = LOADERMAGIC_BM;
  ld->ld_maxnum = maxnum;
  ld->ld_hset =
    hashsetobj_grow_BM (NULL, 2 * BM_NB_PREDEFINED + maxnum * 100);
  ld->ld_storepatharr = calloc (maxnum + 1, sizeof (void *));
  if (!ld->ld_storepatharr)
    FATAL_BM ("cannot calloc for %d store files (%m)", maxnum);
  for (int ix = 1; ix <= maxnum; ix++)
    {
      char *pa = g_tree_lookup (trent, (void *) (intptr_t) ix);
      if (pa)
        ld->ld_storepatharr[ix] = pa;
    }
  ld->ld_todopath = todopath;
  ld->ld_dir = strdup (ldirpath);
  if (!ld->ld_dir)
    FATAL_BM ("cannot strdup dir %s (%m)", ldirpath);
  g_tree_unref (trent), trent = NULL;
  // should create a loader, and probably have a  frame for it.
#warning load_initial_BM incomplete
}                               /* end load_initial_BM */

void
doload_BM (struct stackframe_stBM *fr, struct loader_stBM *ld)
{
}                               /* end doload_BM */
