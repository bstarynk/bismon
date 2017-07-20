// GPLv3+ licensed cold.c file
// by basile@starynkevitch.net
#include <stdint.h>
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

int
main (int argc, char **argv)
{
}				/* end main */

/// for Emacs
/// Local Variables:
/// compile-command: "ninja"
/// End:
