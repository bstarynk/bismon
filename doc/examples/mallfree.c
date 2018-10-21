/// file mallfree.c
#include <stdlib.h>
int weirdsum(int x, int y) {
  int*ar2 = malloc(2*sizeof(int));
  ar2[0] = x;
  ar2[1] = y;
  int r = ar2[0] + ar2[1];
  free (ar2);
  return r;
}
