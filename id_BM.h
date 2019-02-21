// file id_BM.h - declarations and inline functions for objid-s

/***
    BISMON 
    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

#ifndef ID_BM_INCLUDED
#define ID_BM_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus*/

#ifndef ASSERT_BM
#include <assert.h>
#define ASSERT_BM(Cond) assert(Cond)
#endif                          /* ASSERT_BM */

#define IDLEN_BM 24


#define MINSERIAL_BM (62*62)    /*3884 */
#define MAXSERIAL_BM ((uint64_t)10 * 62 * (62* 62*62) * (62*62*62) * (62*62*62))        /*8392993658683402240 */
#define DELTASERIAL_BM (MAXSERIAL_BM-MINSERIAL_BM)
#define MAXBUCKETS_BM (10*62)
#define B62DIGITS_BM   "0123456789"  "abcdefghijklmnopqrstuvwxyz"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define SERIALDIGITS_BM 11
#define SERIALBASE_BM 62

  typedef uint32_t hash_tyBM;

  typedef uint64_t serial63_tyBM;

  struct rawid_stBM
  {
    serial63_tyBM id_hi;
    serial63_tyBM id_lo;
  };
  typedef struct rawid_stBM rawid_tyBM;


  static inline bool validserial63_BM (serial63_tyBM s);
  extern serial63_tyBM randomserial63_BM (void);
#if __cplusplus
  extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[]);
#else
  extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16]);
#endif

  extern serial63_tyBM parse_serial63_BM (const char *buf, const char **pend);
  static inline unsigned bucknumserial63_BM (serial63_tyBM s);
  static inline uint64_t buckoffserial63_BM (serial63_tyBM s);

  extern rawid_tyBM parse_rawid_BM (const char *buf, const char **pend);
  extern rawid_tyBM randomid_BM (void);
  static inline bool validid_BM (rawid_tyBM id);
  static inline hash_tyBM hashid_BM (rawid_tyBM id);
  static inline int cmpid_BM (rawid_tyBM id1, rawid_tyBM id2);
  static inline bool equalid_BM (rawid_tyBM id1, rawid_tyBM id2);
#if __cplusplus
  extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[]);
#else
  extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[static 32]);
#endif
// to be called from debugger
// actually the objectdbg* functions use some static thread-local buffer
  extern const char *iddbg_BM (rawid_tyBM id);  // non reentrant!

  extern const char *iddbg1_BM (rawid_tyBM id); // non reentrant!

  extern const char *iddbg2_BM (rawid_tyBM id); // non reentrant!


  bool validserial63_BM (serial63_tyBM s)
  {
    return (s > MINSERIAL_BM && s < MAXSERIAL_BM);
  }                             /* end validserial63_BM */


  unsigned bucknumserial63_BM (serial63_tyBM s)
  {
    return s / (DELTASERIAL_BM / MAXBUCKETS_BM);
  }

  uint64_t buckoffserial63_BM (serial63_tyBM s)
  {
    return s % (DELTASERIAL_BM / MAXBUCKETS_BM);
  }

  bool validid_BM (rawid_tyBM id)
  {
    return (validserial63_BM (id.id_hi) && validserial63_BM (id.id_lo));
  }                             /* end validid_BM */



  hash_tyBM hashid_BM (rawid_tyBM id)
  {
    if (!validid_BM (id))
      return 0;
    hash_tyBM h = (id.id_hi % 1073741939) ^ (id.id_lo % 596789351);
    if (h == 0)
      h = (id.id_hi & 0xffffff) + (id.id_lo & 0x3ffffff) + 17;
    ASSERT_BM (h > 0);
    return h;
  }                             /* end hashid_BM */



  int cmpid_BM (rawid_tyBM id1, rawid_tyBM id2)
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
  }                             /* end cmpid_BM */



#ifdef __cplusplus

  struct IdLess_BM
  {
    inline bool operator            () (const rawid_tyBM & id1,
                                        const rawid_tyBM & id2)
    {
      return cmpid_BM (id1, id2) < 0;
    };
  };                            // end IdLess_BM

};                              /* end extern "C" */
#endif /*__cplusplus*/

#endif /*ID_BM_INCLUDED */
