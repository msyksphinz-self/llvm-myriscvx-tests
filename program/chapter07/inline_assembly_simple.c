int inline_assembly(int a)
{
  int ret;
  asm volatile ("addi  %0,%1,%2":"=r"(ret): "r"(a), "i"(100));

  return ret;
}
