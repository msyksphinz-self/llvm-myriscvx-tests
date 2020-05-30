int inline_assembly(int a)
{
  int ret;
  asm volatile ("addi %0,%1,100":"=r"(ret): "r"(a));
  return ret;
}
