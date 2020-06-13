int add (int a, int b) {
  return a+b;
}

int total(int a[], const int size)
{
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += a[i];
  }
  return total;
}
