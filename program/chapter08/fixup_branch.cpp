extern int global_a;

extern int funcA(int b);
extern int funcB(int c);

int branch_test(int b, int c)
{
  return global_a ? funcA(b) : funcB(c);
}
