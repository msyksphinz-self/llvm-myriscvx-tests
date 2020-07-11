void test_math(int a, int b, unsigned int ua)
{
  (*(volatile          int *)0x100000) = a + b;    // ADD
  (*(volatile          int *)0x100004) = a - b;    // SUB
  (*(volatile          int *)0x100008) = a * b;    // MUL
  (*(volatile          int *)0x10000c) = a << 10;  // SLLI
  (*(volatile unsigned int *)0x100010) = ua << 11; // SLLI
  (*(volatile          int *)0x100014) = a >> 2;   // SRAI
  (*(volatile unsigned int *)0x100018) = ua >> 30; // SRLI
  (*(volatile          int *)0x10001c) = a << b;   // SLL
  (*(volatile          int *)0x100020) = a >> b;   // SRA
  (*(volatile unsigned int *)0x100024) = ua << b;  // SLL
  (*(volatile unsigned int *)0x100028) = ua >> b;  // SRL

  return;
}


int long_value()
{
  long long long_const = 0x0123456789abcdefULL;
  return 0;
}
