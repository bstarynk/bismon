// file names_BM.c
#include "bismon.h"


// keys are strdup-ed strings, values are objectval_tyBM*
static GTree *nametree_BM;


// keys are objectval_tyBM*, values are strdup-ed string
static GHashTable *hashtablename_BM;

static guint hashnamedobjfun_BM (gconstpointer key);

bool
validname_BM (const char *nam)
{
  if (!nam)
    return false;
  if (!isalpha (nam[0]))
    return false;
  const char *pc = nam;
  for (; *pc; pc++)
    {
      if (isalnum (*pc))
        continue;
      else if (*pc == '_')
        {
          if (!isalnum (pc[1]))
            return false;
          if (!isalnum (pc[-1]))
            return false;
          continue;
        }
      else
        return false;
    }
  return true;
}                               /* end validname_BM */

guint
hashnamedobjfun_BM (gconstpointer key)
{
  assert (valtype_BM ((const value_tyBM) key) == tyObject_BM);
  return objecthash_BM ((const objectval_tyBM *) key);
}                               /* end hashnamedobjfun_BM */

static void
add_predefined_name_BM (const char *name, objectval_tyBM * obj)
{
  assert (validname_BM (name));
  assert (isobject_BM (obj));
  char *dupname = strdup (name);
  if (!dupname)
    FATAL_BM ("strdup %s failed (%m)", name);
  assert (g_tree_lookup (nametree_BM, name) == NULL);
  assert (g_hash_table_lookup (hashtablename_BM, obj) == NULL);
  g_tree_insert (nametree_BM, dupname, obj);
  g_hash_table_insert (hashtablename_BM, obj, dupname);
}                               /* end add_predefined_name_BM */

void
initialize_predefined_names_BM (void)
{
  hashtablename_BM = g_hash_table_new (hashnamedobjfun_BM, NULL);
  nametree_BM = g_tree_new ((GCompareFunc) strcmp);
#define HAS_NAMED_PREDEF_BM(Nam,Id) \
  add_predefined_name_BM(#Nam,PREDEF_BM(Id));
#include "_bm_predef.h"
}                               /* end initialize_predefined_names_BM */


const objectval_tyBM *
findnamedobj_BM (const char *nam)
{
  if (!nam || !nam[0] || !validname_BM (nam))
    return NULL;
  return (const objectval_tyBM *) g_tree_lookup (nametree_BM, nam);
}                               /* end findnamedobj_BM */

const char *
findobjectname_BM (const objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return NULL;
  return (const char *) g_hash_table_lookup (hashtablename_BM, obj);
}                               /* end findobjectname_BM */

bool
registername_BM (const objectval_tyBM * obj, const char *nam)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return false;
  if (!validname_BM (nam))
    return false;
  if (g_tree_lookup (nametree_BM, nam))
    return false;
  if (g_hash_table_lookup (hashtablename_BM, obj))
    return false;
  char *dupname = strdup (nam);
  if (!dupname)
    FATAL_BM ("strdup %s failed (%m)", nam);
  g_tree_insert (nametree_BM, dupname, obj);
  g_hash_table_insert (hashtablename_BM, obj, dupname);
  return true;
}                               /* end registername_BM */
