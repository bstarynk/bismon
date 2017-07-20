// GPLv3+ licensed cold.c file
// by basile@starynkevitch.net
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <gtk/gtk.h>

typedef uint32_t hash_tyBM;
struct typedhead_stBM
{
  unsigned htyp:24;
  unsigned hgc:8;
  union
  {
    hash_tyBM hash;
    uint32_t rlen;
  };
};
typedef struct typedhead_stBM typedhead_tyBM;
typedef struct typedhead_stBM typedintern_tyBM;

struct typedsize_stBM
{
  typedhead_tyBM pA;
  uint32_t size;
};
typedef struct typedsize_stBM typedsize_tyBM;

typedef uint64_t serial63_tyBM;

struct rawid_stBM
{
  serial63_tyBM id_hi;
  serial63_tyBM id_lo;
};
typedef struct rawid_stBM rawid_tyBM;

struct allalloc_stBM
{
  unsigned long al_size;        /* allocated size of al_ptr */
  unsigned long al_nb;          /* user number of al_ptr */
  void *al_ptr[];
};
extern struct allalloc_stBM *allocationvec_vBM;

extern const int64_t primes_tab_BM[];
extern int64_t prime_above_BM (int64_t);
extern int64_t prime_below_BM (int64_t);

#define MINSERIAL_BM (62*62)    /*3884 */
#define MAXSERIAL_BM ((uint64_t)10 * 62 * (62* 62*62) * (62*62*62) * (62*62*62))        /*8392993658683402240 */
#define DELTASERIAL_BM (MAXSERIAL_BM-MINSERIAL_BM)

#define B62DIGITS_BM   "0123456789"  "abcdefghijklmnopqrstuvwxyz"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define SERIALDIGITS_BM 11
#define SERIALBASE_BM 62

#define FATAL_AT_BIS_BM(Fil,Lin,Fmt,...) do { \
fprintf(stderr, "BM FATAL:%s:%d: " Fmt "\n", \
	Fil, Lin, __VA_ARGS__); abort_BM(); } while(0)

#define FATAL_AT_BM(Fil,Lin,Fmt,...) FATAL_AT_BIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define FATAL_BM(Fmt,...) FATAL_AT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

extern void abort_BM (void) __attribute__ ((noreturn));

inline bool validserial63_BM (serial63_tyBM s);
extern serial63_tyBM randomserial63_BM (void);
extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16]);
extern serial63_tyBM parse_serial63_BM (const char *buf, const char **pend);
extern rawid_tyBM randomid_BM (void);
inline bool validid_BM (rawid_tyBM id);
inline hash_tyBM hashid_BM (rawid_tyBM id);
extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[static 32]);
extern rawid_tyBM parse_rawid_BM (const char *buf, const char **pend);
extern void *allocgcty_BM (unsigned type, size_t sz);
extern void *allocinternalty_BM (unsigned type, size_t sz);



// an array of primes, gotten with something similar to
//   /usr/games/primes 3  | awk '($1>p+p/9){print $1, ","; p=$1}' 
const int64_t primes_tab_BM[] = {
  3, 5, 7, 11, 13, 17, 19, 23, 29, 37, 43, 53, 59, 67, 79, 89, 101, 113,
  127, 149, 167, 191, 223, 251, 281, 313, 349, 389, 433, 487, 547, 613,
  683, 761, 853, 953, 1061, 1181, 1319, 1471, 1637, 1823, 2027, 2267,
  2521, 2803, 3119, 3467, 3853, 4283, 4759, 5297, 5897, 6553, 7283, 8093,
  8999, 10007, 11119, 12373, 13751, 15287, 16987, 18899, 21001, 23339,
  25933, 28817, 32027, 35591, 39551, 43951, 48847, 54277, 60317, 67021,
  74471, 82757, 91957, 102181, 113537, 126173, 140197, 155777, 173087,
  192319, 213713, 237467, 263863, 293201, 325781, 361979, 402221, 446921,
  496579, 551767, 613097, 681221, 756919, 841063, 934517, 1038383, 1153759,
  1281961, 1424407, 1582697, 1758553, 1953949, 2171077, 2412323, 2680367,
  2978189, 3309107, 3676789, 4085339, 4539277, 5043653, 5604073, 6226757,
  6918619, 7687387, 8541551, 9490631, 10545167, 11716879, 13018757,
  14465291, 16072547, 17858389, 19842659, 22047401, 24497113, 27219019,
  30243359, 33603743, 37337497, 41486111, 46095719, 51217477, 56908337,
  63231499, 70257241, 78063641, 86737379, 96374881, 107083213, 118981367,
  132201521, 146890631, 163211821, 181346479, 201496157, 223884629,
  248760703, 276400823, 307112027, 341235667, 379150777, 421278643,
  468087391, 520097111, 577885681, 642095213, 713439127, 792710159,
  880789067, 978654533, 1087393949, 1208215531, 1342461719, 1491624137,
  1657360153, 1841511311, 2046123679, 2273470799, 2526078691, 2806754123,
  3118615693, 3465128567, 3850142869, 4277936557, 4753262879, 5281403287,
  5868225889, 6520251019, 7244723357, 8049692639, 8944102939, 9937892189,
  11042102507, 12269002787, 13632225331, 15146917109, 16829907907,
  18699897683, 20777664097, 23086293457, 25651437191, 28501596883,
  31668440987, 35187156661, 39096840751, 43440934181, 48267704657,
  53630782993, 59589758903, 66210843271, 73567603643, 81741781829,
  90824202037, 100915780061, 112128644521, 124587382807, 138430425373,
  153811583771, 170901759761, 189890844179, 210989826869, 234433140979,
  260481267763, 289423630891, 321581812103, 357313124579, 397014582917,
  441127314403, 490141460453, 544601622727, 605112914149, 672347682449,
  747052980503, 830058867229, 922287630259, 1024764033637, 1138626704071,
};


int64_t
prime_above_BM (int64_t n)
{
  unsigned numprimes = sizeof (primes_tab_BM) / sizeof (primes_tab_BM[0]);
  int lo = 0, hi = numprimes;
  if (n >= primes_tab_BM[numprimes - 1])
    return 0;
  if (n < 2)
    return 2;
  while (lo + 6 < hi)
    {
      int md = (lo + hi) / 2;
      if (primes_tab_BM[md] > n)
        hi = md;
      else
        lo = md;
    };
  if (hi < (int) numprimes - 1)
    hi++;
  if (hi < (int) numprimes - 1)
    hi++;
  for (int ix = lo; ix < hi; ix++)
    if (primes_tab_BM[ix] > n)
      return primes_tab_BM[ix];
  return 0;
}

int64_t
prime_below_BM (int64_t n)
{
  unsigned numprimes = sizeof (primes_tab_BM) / sizeof (primes_tab_BM[0]);
  int lo = 0, hi = numprimes;
  if (n >= primes_tab_BM[numprimes - 1])
    return 0;
  if (n < 2)
    return 2;
  while (lo + 6 < hi)
    {
      int md = (lo + hi) / 2;
      if (primes_tab_BM[md] > n)
        hi = md;
      else
        lo = md;
    };
  if (hi < (int) numprimes - 1)
    hi++;
  if (hi < (int) numprimes - 1)
    hi++;
  for (int ix = hi; ix >= 0; ix--)
    if (primes_tab_BM[ix] < n)
      return primes_tab_BM[ix];
  return 0;
}

/*****************************************************************/

bool
validserial63_BM (serial63_tyBM s)
{
  return (s > MINSERIAL_BM && s < MAXSERIAL_BM);
}

serial63_tyBM
randomserial63_BM (void)
{
  serial63_tyBM s = 0;
  do
    {
      // notice that g_random_int is seeded by /dev/random
      s = (((serial63_tyBM) g_random_int ()) << 32) | g_random_int ();
    }
  while (!validserial63_BM (s));
  return s;
}

// return the number of bytes written into cbuf
int
serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16])
{
  memset (cbuf, 0, 16);
  if (s == 0)
    {
      cbuf[0] = '_';
      cbuf[1] = '_';
      return 2;
    };
  cbuf[0] = '_';
  uint64_t n = s;
  char *pc = cbuf + SERIALDIGITS_BM;
  const char *b62digits = B62DIGITS_BM;
  while (n != 0)
    {
      unsigned d = n % SERIALBASE_BM;
      n = n / SERIALBASE_BM;
      *pc = b62digits[d];
      pc--;
    }
  while (pc > cbuf)
    *(pc--) = '0';
  cbuf[16 - 1] = (char) 0;
  return SERIALDIGITS_BM + 1;
}                               /* end serial63tocbuf16_BM */


serial63_tyBM
parse_serial63_BM (const char *buf, const char **pend)
{
  if (buf && buf[0] == '_' && buf[1] == '_')
    {
      if (pend)
        *pend = buf + 2;
      return 0;
    };
  if (!buf || buf[0] != '_' || buf[1] < '0' || buf[1] > '9')
    {
      if (pend)
        *pend = buf;
      return 0;
    };
  uint64_t n = 0;
  const char *b62digits = B62DIGITS_BM;
  for (unsigned i = 0; i < SERIALDIGITS_BM; i++)
    {
      if (!buf[i + 1])
        {
          if (pend)
            *pend = buf;
          return 0;
        };
      char *str = strchr (b62digits, buf[i + 1]);
      if (!str)
        {
          if (pend)
            *pend = buf;
          return 0;
        };
      n = n * SERIALBASE_BM + (str - b62digits);
    };
  if (!validserial63_BM (n))
    {
      if (pend)
        *pend = buf;
      return 0;
    };
  if (pend)
    *pend = buf + SERIALDIGITS_BM + 1;
  return n;
}                               /* end parse_serial63_BM */

rawid_tyBM
randomid_BM (void)
{
  rawid_tyBM r;
  r.id_hi = randomserial63_BM ();
  r.id_lo = randomserial63_BM ();
  return r;
}                               /* end randomid_BM  */

bool
validid_BM (rawid_tyBM id)
{
  return (validserial63_BM (id.id_hi) && validserial63_BM (id.id_lo));
}

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

// return the number of bytes written into cbuf
int
idtocbuf32_BM (rawid_tyBM id, char cbuf[static 32])
{
  memset (cbuf, 0, 32);
  if (!validid_BM (id))
    {
      cbuf[0] = cbuf[1] = '_';
      return 2;
    };
  int llo = serial63tocbuf16_BM (id.id_hi, cbuf);
  int lhi = serial63tocbuf16_BM (id.id_lo, cbuf + llo);
  return llo + lhi;
}                               /* end idtocbuf32_BM */


rawid_tyBM
parse_rawid_BM (const char *buf, const char **pend)
{
  if (buf && buf[0] == '_' && buf[1] == '_')
    {
      if (pend)
        *pend = buf + 2;
      return (rawid_tyBM)
      {
      0, 0};
    }
  if (!buf || buf[0] != '_' || buf[1] < '0' || buf[1] > '9')
    {
      if (pend)
        *pend = buf;
      return (rawid_tyBM)
      {
      0, 0};
    }
  const char *endhi = NULL;
  const char *endlo = NULL;
  serial63_tyBM idhi = 0, idlo = 0;
  idhi = parse_serial63_BM (buf, &endhi);
  if (endhi && endhi > buf + SERIALDIGITS_BM)
    idlo = parse_serial63_BM (endhi, &endlo);
  if (endlo && endlo > endhi + SERIALDIGITS_BM)
    {
      if (pend)
        *pend = endlo;
      return (rawid_tyBM)
      {
      idhi, idlo};
    };
  if (pend)
    *pend = buf;
  return (rawid_tyBM)
  {
  0, 0};
}                               /* end parse_rawid_BM */


/////////////////////// allocation support
struct allalloc_stBM *allocationvec_vBM;


void *
allocgcty_BM (unsigned type, size_t sz)
{
  unsigned long alloc_size =
    allocationvec_vBM ? allocationvec_vBM->al_size : 0;
  unsigned long alloc_nb = allocationvec_vBM ? allocationvec_vBM->al_nb : 0;
  if (alloc_nb + 2 >= alloc_size)
    {
      unsigned long new_alloc_size = ((4 * alloc_size / 3 + 600) | 511) - 2;
      struct allalloc_stBM *new_allocvec =
        malloc (sizeof (struct allalloc_stBM) +
                new_alloc_size * sizeof (void *));
      if (!new_allocvec)
        {
          FATAL_BM ("failed reallocation of allocvec %ld (%m)",
                    new_alloc_size);
        }
      new_allocvec->al_size = new_alloc_size;
      new_allocvec->al_nb = alloc_nb;
      memset (new_allocvec->al_ptr, 0, new_alloc_size * sizeof (void *));
      free (allocationvec_vBM);
      allocationvec_vBM = new_allocvec;
    }
  assert (sz > sizeof (typedhead_tyBM));
  typedhead_tyBM *newzon = malloc (sz);
  if (!newzon)
    FATAL_BM ("failed fresh GC allocation of new zone %zd bytes (%m)", sz);
  memset (newzon, 0, sz);
  newzon->htyp = type;
  allocationvec_vBM->al_ptr[alloc_nb++] = newzon;
  allocationvec_vBM->al_nb = alloc_nb;
  return newzon;
}                               /* end allocgcty_BM */



void *
allocinternalty_BM (unsigned type, size_t sz)
{
  assert (sz > sizeof (typedintern_tyBM));
  typedintern_tyBM *newizon = malloc (sz);
  if (!newizon)
    FATAL_BM ("failed internal allocation of %zd bytes (%m)", sz);
  memset (newizon, 0, sz);
  newizon->htyp = type;
  return newizon;
}                               /* end allocinternalty_BM  */

void
abort_BM (void)
{
  fflush (NULL);
  abort ();
}

int
main (int argc, char **argv)
{
  bool batch = false;
  for (int ix = 1; ix < argc; ix++)
    if (!strcmp (argv[ix], "-B") || !strcmp (argv[ix], "--batch"))
      batch = true;
}                               /* end main */

/// for Emacs
/// Local Variables:
/// compile-command: "ninja"
/// End:
