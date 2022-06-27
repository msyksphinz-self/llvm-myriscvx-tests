#include <stdio.h>

int global = 100;

extern int object_sample(int a);

int external_func(int global, int i)
{
  return global + i;
}


int main ()
{
  int ret = object_sample(10);
  printf("object_sample value = %d\n", ret);
}
