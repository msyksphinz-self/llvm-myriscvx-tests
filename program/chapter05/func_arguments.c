#include <stdio.h>

int total(int val1, int val2, int val3, int val4, int val5,
          int val6, int val7, int val8, int val9, int val10) {
  return val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10;
}

int main()
{
  printf("Total = %d\n", total(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}
