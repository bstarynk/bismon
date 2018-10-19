// file factinline12.c
static int fact (int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact (n - 1);
}

int fact12 (void) {
  return fact (12);
}
