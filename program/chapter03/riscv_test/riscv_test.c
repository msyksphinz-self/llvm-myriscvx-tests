#include <stdio.h>

int main ()
{
  int total = 0;
  for (int i = 1; i <= 10; i++) {
    total += i;
  }

  printf ("Total = %d\n", total);
}
