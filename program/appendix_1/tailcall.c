int tail_call_func(int a, int b) {
  int total = external_func(a);
  for (int i = a; i < b; i++) {
    total += i;
  }
  return total;
}

int inc(int a)
{
  return a+1;
}

int tail_call_main (int a, int b, int c, int d) {
  int e = inc(a) + inc(b);
  int f = inc(c) + inc(d);

  return tail_call_func(e, f);
}
