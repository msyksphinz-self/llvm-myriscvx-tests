#include "func_struct_simple.h"

// int func (struct S elem) {
//   int total = 0;
//   total = elem.x + elem.y;
//   // for(int i = 0; i < STRUCT_SIZE; i++) {
//   //   total += elem.x[i] + 1;
//   // }
//   return total;
// }

// int call_func () {
//   struct S elem;
//   for (int i = 0; i < STRUCT_SIZE; i++) {
//     elem.x[i] = i;
//   }
//   return func (elem);
// }


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
  return func_S128(elem.s128_0) + func_S128(elem.s128_1);
}
