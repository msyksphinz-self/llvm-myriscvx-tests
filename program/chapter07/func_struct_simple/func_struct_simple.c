#include "func_struct_simple.h"

int func_S32 (struct S32 elem) {
  return elem.a + elem.b + elem.c;
}

int func_S64 (struct S64 elem) {
  return func_S32(elem.s32) + elem.d;
}

int func_S128 (struct S128 elem) {
  return func_S64(elem.s64) + elem.e;
}

int func_S256 (struct S256 elem) {
  return func_S128(elem.s128) + elem.f[0] + elem.f[1] + elem.f[2] + elem.f[3];
}


int func_S256_caller()
{
  struct S256 elem;
  elem.s128.s64.s32.a = 100;
  elem.s128.s64.s32.b = 200;
  elem.s128.s64.s32.c = 300;
  elem.s128.s64.d     = 400;
  elem.s128.e         = 500;
  elem.f[0]             = 600;
  elem.f[1]             = 700;
  elem.f[2]             = 800;
  elem.f[3]             = 900;

  return func_S256(elem);
}
