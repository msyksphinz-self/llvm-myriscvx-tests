#include <stdint.h>

#ifdef RV64

int64_t  add64           ( int64_t a,  int64_t b)  { return a + b;    }  // ADD
int64_t  sub64           ( int64_t a,  int64_t b)  { return a - b;    }  // SUB
int64_t  mul64           ( int64_t a,  int64_t b)  { return a * b;    }  // MUL
int64_t  div64           ( int64_t a,  int64_t b)  { return a / b;    }  // MUL
int64_t  div64u          (uint64_t a, uint64_t b)  { return a / b;    }  // MUL
int64_t  shift_left64    ( int64_t a)              { return a  << 10; } // SLLI
uint64_t shift_left64u   (uint64_t ua)             { return ua << 11; } // SLLI
int64_t  shift_right64   ( int64_t a)              { return a  >> 2;  } // SRAI
uint64_t shift_right64u  (uint64_t ua)             { return ua >> 30; } // SRLI
int64_t  shift_leftv64   ( int64_t a,  uint64_t b) { return a << b;   } // SLL
int64_t  shift_rightv64  ( int64_t a,  uint64_t b) { return a >> b;   } // SRA
uint64_t shift_leftv64u  (uint64_t ua, uint64_t b) { return ua << b;  } // SLL
uint64_t shift_rightv64u (uint64_t ua, uint64_t b) { return ua >> b;  } // SRL

#endif // RV64
