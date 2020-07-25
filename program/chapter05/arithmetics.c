#include <stdint.h>

int32_t  add32           ( int32_t a,  int32_t b)  { return a + b;    }  // ADD
int32_t  sub32           ( int32_t a,  int32_t b)  { return a - b;    }  // SUB
int32_t  mul32           ( int32_t a,  int32_t b)  { return a * b;    }  // MUL
int32_t  div32           ( int32_t a,  int32_t b)  { return a / b;    }  // MUL
int32_t  div32u          (uint32_t a, uint32_t b)  { return a / b;    }  // MUL
int32_t  shift_left32    ( int32_t a)              { return a  << 10; }  // SLLI
uint32_t shift_left32u   (uint32_t ua)             { return ua << 11; }  // SLLI
int32_t  shift_right32   ( int32_t a)              { return a  >> 2;  }  // SRAI
uint32_t shift_right32u  (uint32_t ua)             { return ua >> 30; }  // SRLI
int32_t  shift_leftv32   ( int32_t a,  uint32_t b) { return a << b;   }  // SLL
int32_t  shift_rightv32  ( int32_t a,  uint32_t b) { return a >> b;   }  // SRA
uint32_t shift_leftv32u  (uint32_t ua, uint32_t b) { return ua << b;  }  // SLL
uint32_t shift_rightv32u (uint32_t ua, uint32_t b) { return ua >> b;  }  // SRL

#ifdef RV64

int64_t  add64           ( int64_t a,  int64_t b)  { return a + b;    }  // ADD
int64_t  sub64           ( int64_t a,  int64_t b)  { return a - b;    }  // SUB
int64_t  mul64           ( int64_t a,  int64_t b)  { return a * b;    }  // MUL
int64_t  div64           ( int64_t a,  int64_t b)  { return a / b;    }  // MUL
int64_t  div64u          (uint64_t a, uint64_t b)  { return a / b;    }  // MUL
int64_t  shift_left64    ( int64_t a)              { return a  << 10; }  // SLLI
uint64_t shift_left64u   (uint64_t ua)             { return ua << 11; }  // SLLI
int64_t  shift_right64   ( int64_t a)              { return a  >> 2;  }  // SRAI
uint64_t shift_right64u  (uint64_t ua)             { return ua >> 30; }  // SRLI
int64_t  shift_leftv64   ( int64_t a,  uint64_t b) { return a << b;   }  // SLL
int64_t  shift_rightv64  ( int64_t a,  uint64_t b) { return a >> b;   }  // SRA
uint64_t shift_leftv64u  (uint64_t ua, uint64_t b) { return ua << b;  }  // SLL
uint64_t shift_rightv64u (uint64_t ua, uint64_t b) { return ua >> b;  }  // SRL

#endif // RV64
