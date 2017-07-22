// file main_BM.c
#include "bismon.h"


void
abort_BM (void)
{
  fflush (NULL);
  abort ();
}                               /* end abort_BM */


////////////////////////////////////////////////////////////////
int
main (int argc, char **argv)
{
  /// should actually use gtk_init_with_args so define some
  /// GOptionEntry array
  bool batch = false;
  for (int ix = 1; ix < argc; ix++)
    if (!strcmp (argv[ix], "-B") || !strcmp (argv[ix], "--batch"))
      batch = true;
}                               /* end main */
