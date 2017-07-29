// file inline_BM.h
#ifndef INLINE_BM_INCLUDED
#define INLINE_BM_INCLUDED

double
clocktime_BM (clockid_t clid)
{
  struct timespec ts = { 0, 0 };
  if (clock_gettime (clid, &ts))
    return NAN;
  return (double) ts.tv_sec + 1.0e-9 * ts.tv_nsec;
}

double
cputime_BM (void)
{
  return clocktime_BM (CLOCK_PROCESS_CPUTIME_ID);
}                               /* end cputime_BM */

double
elapsedtime_BM (void)
{
  struct timespec ts = { 0, 0 };
  if (clock_gettime (CLOCK_MONOTONIC, &ts))
    return NAN;
  return (double) (ts.tv_sec - startrealtimespec_BM.tv_sec)
    + 1.0e-9 * (ts.tv_nsec - startrealtimespec_BM.tv_nsec);
}                               /* end elapsedtime_BM */



bool
istaggedint_BM (value_tyBM v)
{
  return (uintptr_t) v & 1;
}                               /* end istaggedint_BM */

intptr_t
getint_BM (value_tyBM v)
{
  if (istaggedint_BM (v))
    return ((intptr_t) v) >> 1;
  return 0;
}                               /* end getint_BM */

value_tyBM
taggedint_BM (intptr_t i)
{
  return (value_tyBM) ((i << 1) | 1);
}                               /* end taggedint_BM */

int
valtype_BM (const value_tyBM v)
{
  if (!v)
    return tyNone_BM;
  if (istaggedint_BM (v))
    return tyInt_BM;
  if (((uintptr_t) v & 3) == 0)
    {
      typedhead_tyBM *ht = (typedhead_tyBM *) v;
      assert (ht->htyp != 0);
      return ht->htyp;
    }
  return tyNone_BM;
}                               /* end valtype_BM */

objectval_tyBM *
valclass_BM (const value_tyBM v)
{
  if (!v)
    return NULL;
  if (istaggedint_BM (v))
    return BMP_int;
  if (((uintptr_t) v & 3) == 0)
    {
      typedhead_tyBM *ht = (typedhead_tyBM *) v;
      assert (ht->htyp != 0);
      int ty = ht->htyp;
      switch (ty)
        {
        case tyString_BM:
          return BMP_string;
        case tySet_BM:
          return BMP_set;
        case tyTuple_BM:
          return BMP_tuple;
        case tyNode_BM:
          return BMP_node;
        case tyClosure_BM:
          return BMP_closure;
        case tyObject_BM:
          return ((objectval_tyBM *) v)->ob_class ? : BMP_undefined;
        case tyUnspecified_BM:
          return BMP_unspecified;
        }
    }
  return NULL;
}                               /* end valclass_BM */

uint8_t
valgcmark_BM (const value_tyBM v)
{
  if (!v)
    return 0;
  int ty = valtype_BM (v);
  if (ty == tyInt_BM)
    return 0xff;
  else if (!ty)
    return 0;
  else
    {
      typedhead_tyBM *ht = (typedhead_tyBM *) v;
      assert (ht->htyp != 0);
      return ht->hgc;
    }
}                               /* end valgcmark_BM */

hash_tyBM
valhash_BM (const value_tyBM v)
{
  if (!v)
    return 0;
  int ty = valtype_BM (v);
  switch (ty)
    {
    case tyInt_BM:
      {
        uintptr_t i = getint_BM (v);
        hash_tyBM hi = (i & 0x3fffffff) ^ (i % 132594613);
        if (hi == 0)
          hi = ((i % 594571) & 0xfffffff) + 17;
        assert (hi != 0);
        return hi;
      }
    case tyString_BM:
    case tySet_BM:
    case tyTuple_BM:
    case tyNode_BM:
    case tyClosure_BM:
    case tyObject_BM:
      return ((typedhead_tyBM *) v)->hash;
    case tyUnspecified_BM:
      return 8594623;
    default:
      return 0;
    }
}                               /* end valhash_BM */

bool
valequal_BM (const value_tyBM v1, const value_tyBM v2)
{
  if (v1 == v2)
    return true;
  int ty1 = valtype_BM (v1);
  if (ty1 != valtype_BM (v2))
    return false;
  if (valhash_BM (v1) != valhash_BM (v2))
    return false;
  if (ty1 == tyObject_BM)
    return false;
  return valsamecontent_BM (v1, v2);
}                               /* end valequal_BM */

bool
validserial63_BM (serial63_tyBM s)
{
  return (s > MINSERIAL_BM && s < MAXSERIAL_BM);
}                               /* end validserial63_BM */


unsigned
bucknumserial63_BM (serial63_tyBM s)
{
  return s / (DELTASERIAL_BM / MAXBUCKETS_BM);
}

uint64_t
buckoffserial63_BM (serial63_tyBM s)
{
  return s % (DELTASERIAL_BM / MAXBUCKETS_BM);
}

bool
validid_BM (rawid_tyBM id)
{
  return (validserial63_BM (id.id_hi) && validserial63_BM (id.id_lo));
}                               /* end validid_BM */



hash_tyBM
hashid_BM (rawid_tyBM id)
{
  if (!validid_BM (id))
    return 0;
  hash_tyBM h = (id.id_hi % 1073741939) ^ (id.id_lo % 596789351);
  if (h == 0)
    h = (id.id_hi & 0xffffff) + (id.id_lo & 0x3ffffff) + 17;
  assert (h > 0);
  return h;
}                               /* end hashid_BM */



int
cmpid_BM (rawid_tyBM id1, rawid_tyBM id2)
{
  if (id1.id_hi == id2.id_hi)
    {
      if (id1.id_lo == id2.id_lo)
        return 0;
      else if (id1.id_lo < id2.id_lo)
        return -1;
      else
        return +1;
    }
  else if (id1.id_hi < id2.id_hi)
    return -1;
  else
    return +1;
}                               /* end cmpid_BM */


rawid_tyBM
objid_BM (const objectval_tyBM * obj)
{
  if ((valtype_BM ((const value_tyBM) obj) != tyObject_BM))
    return (rawid_tyBM)
    {
    0, 0};
  return obj->ob_id;
}                               /* end objid_BM */


void
objtouchmtime_BM (objectval_tyBM * obj, double mtime)
{
  if ((valtype_BM ((const value_tyBM) obj) != tyObject_BM))
    return;
  obj->ob_mtime = mtime;
}                               /* end objtouchmtime_BM */


void
objtouchnow_BM (objectval_tyBM * obj)
{
  if ((valtype_BM ((const value_tyBM) obj) != tyObject_BM))
    return;
  obj->ob_mtime = clocktime_BM (CLOCK_MONOTONIC);
}                               /* end objtouchnow_BM */

bool
equalid_BM (rawid_tyBM id1, rawid_tyBM id2)
{
  return id1.id_hi == id2.id_hi && id1.id_lo == id2.id_lo;
}                               /* end equalid_BM */



/// object support

bool
isobject_BM (const value_tyBM v)
{
  return valtype_BM (v) == tyObject_BM;
}                               /* end isobject_BM */

hash_tyBM
objecthash_BM (const objectval_tyBM * pob)
{
  if (!isobject_BM ((const value_tyBM) pob))
    return 0;
  hash_tyBM h = ((typedhead_tyBM *) pob)->hash;
  assert (h > 0);
  return h;
}                               /* end objecthash_BM */

unsigned
objspacenum_BM (objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return 0;
  return obj->ob_space;
}                               /* end objspacenum_BM */


int
objectcmp_BM (const objectval_tyBM * ob1, const objectval_tyBM * ob2)
{
  if (ob1 == ob2)
    return 0;
  if (ob1
      && (((intptr_t) ob1 & 3)
          || ((typedhead_tyBM *) ob1)->htyp != tyObject_BM))
    FATAL_BM ("bad ob1@%p for objectcmp_BM", ob1);
  if (ob2
      && (((intptr_t) ob1 & 3)
          || ((typedhead_tyBM *) ob2)->htyp != tyObject_BM))
    FATAL_BM ("bad ob2@%p for objectcmp_BM", ob2);
  if (!ob1)
    return -1;
  if (!ob2)
    return +1;
  return cmpid_BM (ob1->ob_id, ob2->ob_id);
}                               /* end objectcmp_BM */

bool
isassoc_BM (const value_tyBM v)
{
  int ty = valtype_BM (v);
  return ty == tydata_assocbucket_BM || ty == tydata_assocpairs_BM;
}                               /* end isassoc_BM */

unsigned
assoc_nbkeys_BM (const anyassoc_tyBM * assoc)
{
  int ty = valtype_BM ((value_tyBM) assoc);
  if (ty == tydata_assocpairs_BM)
    {
      struct assocpairs_stBM *apair = (struct assocpairs_stBM *) assoc;
      return ((typedsize_tyBM *) apair)->size;
    }
  else if (ty == tydata_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      return ((typedsize_tyBM *) abuck)->size;
    }
  return 0;
}                               /* end assoc_nbkeys_BM */


unsigned
datavectlen_BM (const struct datavectval_stBM *dvec)
{
  if (valtype_BM ((const value_tyBM) dvec) != tydata_vectval_BM)
    return 0;
  return ((typedsize_tyBM *) dvec)->size;
}                               /* end datavectlen_BM */

value_tyBM
datavectnth_BM (const struct datavectval_stBM * dvec, int rk)
{
  unsigned sz = datavectlen_BM (dvec);
  if (rk < 0)
    rk += (int) sz;
  if (rk >= 0 && rk < (int) sz)
    return dvec->vec_data[rk];
  return NULL;
}                               /* end datavectnth_BM */

bool
islist_BM (const value_tyBM v)
{
  return (valtype_BM (v) == tydata_listtop_BM);
}

value_tyBM
listfirst_BM (const struct listtop_stBM * lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return NULL;
  struct listlink_stBM *firstl = lis->list_first;
  if (!firstl)
    return NULL;
  for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
    {
      value_tyBM curmem = firstl->link_mems[ix];
      if (curmem)
        return curmem;
    };
  // should never happen
  FATAL_BM ("corrupted list@%p", lis);
}

value_tyBM
listlast_BM (const struct listtop_stBM * lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return NULL;
  struct listlink_stBM *lastl = lis->list_last;
  if (!lastl)
    return NULL;
  for (int ix = LINKSIZE_BM - 1; ix >= 0; ix--)
    {
      value_tyBM curmem = lastl->link_mems[ix];
      if (curmem)
        return curmem;
    };
  // should never happen
  FATAL_BM ("corrupted list@%p", lis);
}

unsigned
listlength_BM (const struct listtop_stBM *lis)
{
  if (!islist_BM ((value_tyBM) lis))
    return 0;
  return ((typedhead_tyBM *) lis)->rlen;
}                               /* end listlength_BM */


bool
istree_BM (const value_tyBM v)
{
  int ty = valtype_BM (v);
  return (ty == tyClosure_BM || ty == tyNode_BM || ty == tydata_quasinode_BM);
}                               /* end istree_BM */

bool
isclosure_BM (const value_tyBM v)
{
  return valtype_BM (v) == tyClosure_BM;
}                               /* end isclosure_BM */

bool
isnode_BM (const value_tyBM v)
{
  return valtype_BM (v) == tyNode_BM;
}                               /* end isnode_BM */

objectval_tyBM *
treeconn_BM (const value_tyBM v)
{
  if (!istree_BM (v))
    return NULL;
  return ((const tree_tyBM *) v)->nodt_conn;
}                               /* end treeconn_BM */

objectval_tyBM *
closureconn_BM (const value_tyBM v)
{
  if (!isclosure_BM (v))
    return NULL;
  return ((const closure_tyBM *) v)->nodt_conn;
}                               /* end closureconn_BM */

objectval_tyBM *
nodeconn_BM (const value_tyBM v)
{
  if (!isnode_BM (v))
    return NULL;
  return ((const node_tyBM *) v)->nodt_conn;
}                               /* end nodeconn_BM */


unsigned
treewidth_BM (const value_tyBM v)
{
  if (!istree_BM (v))
    return 0;
  return ((const typedsize_tyBM *) v)->size;
}                               /* end treewidth_BM */

unsigned
closurewidth_BM (const value_tyBM v)
{
  if (!isclosure_BM (v))
    return 0;
  return ((const typedsize_tyBM *) v)->size;
}                               /* end closurewidth_BM */

unsigned
nodewidth_BM (const value_tyBM v)
{
  if (!isnode_BM (v))
    return 0;
  return ((const typedsize_tyBM *) v)->size;
}

value_tyBM
treenthson_BM (const value_tyBM tr, int rk)
{
  if (!istree_BM (tr))
    return NULL;
  unsigned w = treewidth_BM (tr);
  if (rk < 0)
    rk += (int) w;
  if (rk >= 0 && rk < (int) w)
    return ((const tree_tyBM *) tr)->nodt_sons[rk];
  return NULL;
}                               /* end treenthson_BM */

value_tyBM
closurenthson_BM (const value_tyBM clo, int rk)
{
  if (!isclosure_BM (clo))
    return NULL;
  unsigned w = closurewidth_BM (clo);
  if (rk < 0)
    rk += (int) w;
  if (rk >= 0 && rk < (int) w)
    return ((const closure_tyBM *) clo)->nodt_sons[rk];
  return NULL;
}                               /* end closurenthson_BM */

value_tyBM
nodenthson_BM (const value_tyBM nod, int rk)
{
  if (!isnode_BM (nod))
    return NULL;
  unsigned w = nodewidth_BM (nod);
  if (rk < 0)
    rk += (int) w;
  if (rk >= 0 && rk < (int) w)
    return ((const node_tyBM *) nod)->nodt_sons[rk];
  return NULL;
}                               /* end nodenthson_BM */


bool
isparser_BM (const value_tyBM v)
{
  int ty = valtype_BM (v);
  return ty == tydata_parser_BM;
}                               /* end isparser_BM */

unsigned
parserlineno_BM (const struct parser_stBM *pars)
{
  if (isparser_BM ((const value_tyBM) pars))
    return pars->pars_lineno;
  return 0;
}                               /* end parserlineno_BM */

unsigned
parsercolpos_BM (const struct parser_stBM *pars)
{
  if (isparser_BM ((const value_tyBM) pars))
    return pars->pars_colpos;
  return 0;
}                               /* end parsercolpos_BM */

const char *
parserrestline_BM (const struct parser_stBM *pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return NULL;
  if (!pars->pars_linebuf)
    return NULL;
  assert (pars->pars_curbyte >= pars->pars_linebuf
          && pars->pars_curbyte <= pars->pars_linebuf + pars->pars_linesiz);
  return pars->pars_curbyte;
}                               /* end parserrestline_BM */

gunichar
parserunichar_BM (const struct parser_stBM * pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return 0;
  if (!pars->pars_linebuf)
    return 0;
  assert (pars->pars_curbyte >= pars->pars_linebuf
          && pars->pars_curbyte <= pars->pars_linebuf + pars->pars_linesiz);

  return g_utf8_get_char (pars->pars_curbyte);
}                               /* end parserunichar_BM */

bool
parsereol_BM (const struct parser_stBM * pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return false;
  if (!pars->pars_linebuf)
    return true;
  assert (pars->pars_curbyte >= pars->pars_linebuf
          && pars->pars_curbyte <= pars->pars_linebuf + pars->pars_linesiz);

  return pars->pars_curbyte >= pars->pars_linebuf + pars->pars_linesiz;
}                               /* end parsereol_BM */

bool
parserendoffile_BM (const struct parser_stBM * pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return false;
  return parsereol_BM (pars) && feof (pars->pars_file);
}                               /* end parserendoffile_BM */

bool
parseradvanceutf8_BM (struct parser_stBM * pars, unsigned nbc)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return false;
  if (!pars->pars_linebuf)
    return false;
  if (!pars->pars_curbyte)
    return false;
  while (nbc > 0 && !parsereol_BM (pars))
    {
      const char *pc = pars->pars_curbyte;
      if (!*pc)
        return false;
      pc = g_utf8_next_char (pc);
      pars->pars_curbyte = pc;
      pars->pars_colpos++;
      nbc--;
      if (nbc == 0)
        return true;
    }
  return false;
}                               /* end parseradvanceutf8_BM */


#endif /*INLINE_BM_INCLUDED */
