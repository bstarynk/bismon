/* this TestHelloWorld/testhw-main.c file is in the public domain */
#include <stdio.h>

extern void say_anonymous_hello(void); // in TestHelloWorld/testhw-sayhello.c


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

/* end of file TestHelloWorld/testhw-main.c */
