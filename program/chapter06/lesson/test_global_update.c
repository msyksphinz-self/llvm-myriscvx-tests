#include <stdio.h>
int global_value = 0;

int global_update(int inc);

int main ()
{
  int ret;
  ret = global_update(1);
  if (ret != 0) {
    printf("global_update(1) error. Expected = %d, result = %d\n", ret, 1);
    return 1;
  }

  ret = global_update(10);
  if (ret != 1) {
    printf("global_update(10) error. Expected = %d, result = %d\n", ret, 11);
    return 1;
  }

  ret = global_update(100);
  if (ret != 11) {
    printf("global_update(100) error. Expected = %d, result = %d\n", ret, 110);
    return 1;
  }

  printf("global_update() Test is passed.\n");

  return 0;
}
