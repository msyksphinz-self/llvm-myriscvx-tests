#include <stdarg.h>

int sum_i(int amount, ...)
{
  int i = 0;
  int val = 0;
  int sum = 0;

  va_list vl;
  va_start(vl, amount);
  for (i = 0; i < amount; i++)
  {
    val = va_arg(vl, int);
    sum += val;
  }
  va_end(vl);

  return sum;
}


int test_vararg()
{
  int a = sum_i(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  return a;
}
