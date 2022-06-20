void test_inline_csr()
{
  int csr_current, csr_new = 0x100;
  asm volatile ("csrrw %0, %1, %2":"=r"(csr_current): "i"(0x300), "r"(csr_new));
  asm volatile ("csrrs %0, %1, %2":"=r"(csr_current): "i"(0x300), "r"(csr_new));
  asm volatile ("csrrc %0, %1, %2":"=r"(csr_current): "i"(0x300), "r"(csr_new));

  asm volatile ("csrrwi %0, %1, %2":"=r"(csr_current): "i"(0x300), "i"(31));
  asm volatile ("csrrsi %0, %1, %2":"=r"(csr_current): "i"(0x300), "i"(31));
  asm volatile ("csrrci %0, %1, %2":"=r"(csr_current): "i"(0x300), "i"(31));
}
