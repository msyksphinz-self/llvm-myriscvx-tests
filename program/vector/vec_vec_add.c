void vector_add (int *c, int *a, int *b, const int N)
{
  for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }
  return;
}
