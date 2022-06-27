#include <stdio.h>

int gcd (int a, int b)
{
  int c;
  if (a < b) {
    int tmp;
    tmp = b; b = a; a = tmp;
  }
  while (b != 0) {
    c = a % b; a = b; b = c;
  }
  return a;
}

int main ()
{
  printf ("GCD(273, 21) = %d\n", gcd(273, 21));
  printf ("GCD(411, 27117) = %d\n", gcd(411, 27117));

  return 0;
}
