#include <stdio.h>

int if_ctrl(int a, int b);

int main ()
{
  printf("Test Start");

  if (if_ctrl(10, 20)   == 1) { printf("Correct."); } else { printf("Incorrect."); }
  if (if_ctrl(20, 10)   == 2) { printf("Correct."); } else { printf("Incorrect."); }
  if (if_ctrl(10, 10)   == 2) { printf("Correct."); } else { printf("Incorrect."); }
  if (if_ctrl(-10, -20) == 2) { printf("Correct."); } else { printf("Incorrect."); }
  if (if_ctrl(-10, 20)  == 1) { printf("Correct."); } else { printf("Incorrect."); }
  if (if_ctrl(10, -20)  == 2) { printf("Correct."); } else { printf("Incorrect."); }

  return 0;
}
