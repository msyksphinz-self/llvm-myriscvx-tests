int a, b, c;

int func_callee(int c, int a, int b)
{
  return c ? a : b;
}


int func_caller()
{
  return func_callee(a, b, c);
}
