#include <stdio.h>
#include "func_struct_simple.h"

// extern int func (struct S elem);

extern int func_S32 (struct S32 elem);
extern int func_S64 (struct S64 elem);
extern int func_S128 (struct S128 elem);
extern int func_S256 (struct S256 elem);

int main()
{
  printf("Hello World\n");

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



  struct S256 s256;
  s256.s128.s64.s32.a = 100;
  s256.s128.s64.s32.b = 200;
  s256.s128.s64.s32.c = 300;
  s256.s128.s64.d     = 400;
  s256.s128.e         = 500;
  s256.f[0]           = 600;
  s256.f[1]           = 700;
  s256.f[2]           = 800;
  s256.f[3]           = 900;

  printf("total_S32  = %d\n", func_S32 (s256.s128.s64.s32));
  printf("total_S64  = %d\n", func_S64 (s256.s128.s64));
  printf("total_S128 = %d\n", func_S128(s256.s128));
  printf("total_S256 = %d\n", func_S256(s256));

  return 0;
}
