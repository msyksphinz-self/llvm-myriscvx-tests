#include <stdio.h>

int global_val = 0;
extern int global_val2;

extern void update_global();

int main()
{
  global_val2 ++;
  update_global ();
  // printf("Final value = %d\n", global_val);
}
