#include <stdio.h>
#include "func_struct_simple.h"

// extern int func (struct S elem);

extern int func_S32 (struct S32 elem);
extern int func_S64 (struct S64 elem);
extern int func_S128 (struct S128 elem);
extern int func_S256 (struct S256 elem);

int main()
{
  // struct S elem;
  // for (int i = 0; i < STRUCT_SIZE; i++) {
  //   elem.x[i] = i + 100;
  // }
  // int total = func (elem);
  //
  // printf("total = %d\n", total);
  //
  // int ref_total = 0;
  // for (int i = 0; i < STRUCT_SIZE; i++) {
  //   ref_total += (100 + i);
  // }
  //
  // printf("ref_total = %d\n", ref_total);

  struct S128 s128;
  s128.s64.s32.a = 100;
  s128.s64.s32.b = 200;
  s128.s64.s32.c = 300;
  s128.s64.d     = 400;
  s128.e         = 500;

  int ret = func_S128(s128);
  printf("total = %d\n", ret);

  return ret;
}
