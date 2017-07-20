// GPLv3+ licensed cold.c file
// by basile@starynkevitch.net
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

struct typedhead_stBM
{
  unsigned htyp:24;
  unsigned hgc:8;
};

typedef uint64_t serial63_tBM;

struct rawid_stBM
{
  serial63_tBM id_hi;
  serial63_tBM id_lo;
};
typedef struct rawid_stBM rawid_tBM;
#define MINSERIAL_BM (62*62)	/*3884 */
#define MAXSERIAL_BM ((uint64_t)10 * 62 * (62* 62*62) * (62*62*62) * (62*62*62))	/*8392993658683402240 */
#define DELTASERIAL_BM (MAXSERIAL_BM-MINSERIAL_BM)

#define B62DIGITS_BM   "0123456789"  "abcdefghijklmnopqrstuvwxyz"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define SERIALDIGITS_BM 11
#define SERIALBASE_BM 62

bool
validserial63_BM (serial63_tBM s)
{
  return (s > MINSERIAL_BM && s < MAXSERIAL_BM);
}

serial63_tBM
randomserial63_BM (void)
{
  serial63_tBM s = 0;
  do
    {
      // notice that g_random_int is seeded by /dev/random
      s = (((serial63_tBM) g_random_int ()) << 32) | g_random_int ();
    }
  while (!validserial63_BM (s));
  return s;
}

// return the number of bytes written into cbuf
int
serial63tocbuf16_BM (serial63_tBM s, char cbuf[static 16])
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
}				/* end serial63tocbuf16_BM */


serial63_tBM
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
}				/* end parse_serial63_BM */

rawid_tBM
randomid_BM (void)
{
  rawid_tBM r;
  r.id_hi = randomserial63_BM ();
  r.id_lo = randomserial63_BM ();
  return r;
}

bool
validid_BM (rawid_tBM id)
{
  return (validserial63_BM (id.id_hi) && validserial63_BM (id.id_lo));
}

// return the number of bytes written into cbuf
int
idtocbuf32_BM (rawid_tBM id, char cbuf[static 32])
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
}				/* end idtocbuf32_BM */


rawid_tBM
parse_rawid_BM (const char *buf, const char **pend)
{
  if (buf && buf[0] == '_' && buf[1] == '_')
    {
      if (pend)
        *pend = buf + 2;
      return (rawid_tBM)
      {
        0, 0
      };
    }
  if (!buf || buf[0] != '_' || buf[1] < '0' || buf[1] > '9')
    {
      if (pend)
        *pend = buf;
      return (rawid_tBM)
      {
        0, 0
      };
    }
  const char *endhi = NULL;
  const char *endlo = NULL;
  serial63_tBM idhi = 0, idlo = 0;
  idhi = parse_serial63_BM (buf, &endhi);
  if (endhi && endhi > buf + SERIALDIGITS_BM)
    idlo = parse_serial63_BM (endhi, &endlo);
  if (endlo && endlo > endhi + SERIALDIGITS_BM)
    {
      if (pend)
        *pend = endlo;
      return (rawid_tBM)
      {
        idhi, idlo
      };
    };
  if (pend)
    *pend = buf;
  return (rawid_tBM)
  {
    0, 0
  };
}				/* end parse_rawid_BM */


int
main (int argc, char **argv)
{
}				/* end main */

/// for Emacs
/// Local Variables:
/// compile-command: "ninja"
/// End:
