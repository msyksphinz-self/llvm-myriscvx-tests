#include <stdint.h>

void load_memory_test()
{
  (*(volatile uint64_t *)0x001234);
  (*(volatile uint32_t *)0x001234);
  (*(volatile uint16_t *)0x001234);
  (*(volatile uint8_t  *)0x001234);

  (*(volatile int64_t *)0x001234);
  (*(volatile int32_t *)0x001234);
  (*(volatile int16_t *)0x001234);
  (*(volatile int8_t  *)0x001234);
}


void store_memory_test()
{
  (*(volatile uint64_t *)0x001234) = 1;
  (*(volatile uint32_t *)0x001234) = 1;
  (*(volatile uint16_t *)0x001234) = 1;
  (*(volatile uint8_t  *)0x001234) = 1;

  (*(volatile int64_t *)0x001234) = 1;
  (*(volatile int32_t *)0x001234) = 1;
  (*(volatile int16_t *)0x001234) = 1;
  (*(volatile int8_t  *)0x001234) = 1;
}
