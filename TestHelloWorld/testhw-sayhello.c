/* this TestHelloWorld/testhw-sayhello.c file is in the public domain */
#include <stdio.h>

void
say_anonymous_hello (void)
{
  printf ("Anonymous hello from %s:%d\n", __FILE__, __LINE__);
}
/* end of file TestHelloWorld/testhw-sayhello.c
