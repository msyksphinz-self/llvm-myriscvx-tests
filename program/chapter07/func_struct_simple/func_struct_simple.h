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
  int64_t   e;
};

struct S256
{
  struct S128 s128;
  uint32_t    f[4];
};
