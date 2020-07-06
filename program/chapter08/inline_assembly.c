#define MCYCLE (0xB00)

int inline_assembly(int a)
{
  int mcycle;

  asm volatile ("csrrs %0, %1, zero": "=r"(mcycle): "i"(MCYCLE));
  asm volatile ("add  %0,%1,%2":"=r"(mcycle): "r"(mcycle), "r"(a));

  return mcycle;
}
