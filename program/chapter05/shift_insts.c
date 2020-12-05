#include <stdint.h>

int32_t  sra32_insts_31(int32_t  a) { return a >> 31; }
uint32_t srl32_insts_31(uint32_t a) { return a >> 31; }

int64_t  sra64_insts_31(int64_t  a) { return a >> 31; }
int64_t  sra64_insts_32(int64_t  a) { return a >> 32; }
uint64_t srl64_insts_31(uint64_t a) { return a >> 31; }
uint64_t srl64_insts_32(uint64_t a) { return a >> 32; }
