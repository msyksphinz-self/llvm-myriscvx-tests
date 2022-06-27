int global_a;

int funcA(int a)
{
  return a + 1;
}

int funcB(int a)
{
  return a + 2;
}

extern int branch_test(int b, int c);

int main ()
{
  return branch_test(10, 20);
}
