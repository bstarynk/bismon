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
}                               /* end main */

/// for Emacs
/// Local Variables:
/// compile-command: "ninja"
/// End:
