#include <math.h>

double fma1(double a, double b, double c)
{
  double f1 = fma(a, b, c);
  double f2 = fma(a, b, -f1);
  double f3 = fma(c, -b, f2);
  double f4 = fma(-a, c, f3);
  return f4;
}
