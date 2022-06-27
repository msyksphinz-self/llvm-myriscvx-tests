int factorial(int n)
{
  if (n == 1) {
    return 1;
  }
  return factorial(n-1) * n;
}


int factorial_tail_impl(int n, int accum)
{
  if (n == 1) {
    return accum;
  }
  return factorial_tail_impl(n-1, accum * n);
}

int facotorial_tail(int n)
{
  return factorial_tail_impl(n, 1);
}
