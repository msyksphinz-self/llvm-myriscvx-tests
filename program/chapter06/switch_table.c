int test_switch (int operation, int a, int b)
{
  int ret;
  switch (operation)
  {
    case 1 : ret = a + b; break;
    case 2 : ret = a - b; break;
    case 3 : ret = a * b; break;
    case 4 : ret = a / b; break;
    default : ret = a;
  }
  return ret;
}
