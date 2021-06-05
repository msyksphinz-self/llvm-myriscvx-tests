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
  int gcd_val;
  int mstart_cycle, mstop_cycle;

  asm volatile ("rdcycle %0": "=r"(mstart_cycle));
  gcd_val = gcd(273, 21);
  asm volatile ("rdcycle %0": "=r"(mstop_cycle));

  printf ("GCD(273, 21) = %d\n", gcd_val);
  printf ("start = %d, stop = %d, diff = %d\n",
          mstart_cycle, mstop_cycle, mstop_cycle - mstart_cycle);


  asm volatile ("rdcycle %0": "=r"(mstart_cycle));
  gcd_val = gcd(411, 27117);
  asm volatile ("rdcycle %0": "=r"(mstop_cycle));
  printf ("GCD(411, 27117) = %d\n", gcd_val);
  printf ("start = %d, stop = %d, diff = %d\n",
          mstart_cycle, mstop_cycle, mstop_cycle - mstart_cycle);

  return 0;
}
