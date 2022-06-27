#include <stdint.h>

#ifdef RV64

uint64_t rotate_left(uint64_t a)
{
  uint64_t result = ((a << 62) | (a >> 2));

  return result;
}

#else // RV64

uint32_t rotate_left(uint32_t a)
{
  uint32_t result = ((a << 30) | (a >> 2));

  return result;
}

#endif // RV64
