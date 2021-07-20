/* this test-hello-world.c is in the public domain */
#include <stdio.h>

void
say_anonymous_hello (void)
{
  printf ("Anonymous hello from %s:%d\n", __FILE__, __LINE__);
}

int
main (int argc, char **argv)
{
  if (argc <= 1)
    say_anonymous_hello ();
  else
    {
      printf ("Hello,");
      for (int i = 1; i < argc; i++)
        printf (" %s", argv[i]);
      putchar ('\n');
    };
  fflush (stdout);
  return 0;
}

/* end of file test-hello-world.c */
