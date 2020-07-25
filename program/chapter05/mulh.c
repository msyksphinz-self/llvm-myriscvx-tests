#include <stdint.h>

int64_t mul_1(int32_t a, uint32_t b)
{
  return (int64_t)a * (uint64_t)b;
}

int64_t mul_2(int32_t a, int32_t b)
{
  return (int64_t)a * (int64_t)b;
}


uint64_t mul_3(uint32_t a, uint32_t b)
{
  return (uint64_t)a * (uint64_t)b;
}
