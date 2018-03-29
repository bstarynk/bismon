// file id_BM.c

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
}                               /* end randomserial63_BM */


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
