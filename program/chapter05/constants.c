#include <stdint.h>

int simm_const()
{
  return 0x123;
}

int lui_const()
{
  return 0x12345000;
}


int word_const()
{
  return 0x12345678;
}


int word_const2()
{
  return 0x12345abc;
}


int16_t hword_const2()
{
  return 0x1234;
}

uint16_t huword_const2()
{
  return 0x1234;
}

int8_t bword_const2()
{
  return 0x12;
}

uint8_t buword_const2()
{
  return 0x12;
}
