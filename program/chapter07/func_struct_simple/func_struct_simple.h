// #define STRUCT_SIZE (1)
#include <stdint.h>

struct S32
{
  uint8_t  a, b;
  uint16_t c;
};

struct S64
{
  struct S32 s32;
  uint32_t   d;
};

struct S128
{
  struct S64 s64;
  uint64_t   e;
};

struct S256
{
  struct S128 s128_0;
  struct S128 s128_1;
};
