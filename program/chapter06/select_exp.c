int test_ternary (int operation, int a, int b)
{
  int ret;
  ret = (operation == 1) ? a + b :
      (operation == 2) ? a - b :
      (operation == 3) ? a * b :
      (operation == 4) ? a / b :
      a;
  return ret;
}
