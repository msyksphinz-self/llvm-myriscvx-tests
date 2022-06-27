// #include <math.h>

#include "mandelbrot.h"

double mandelbrot(double a, double b)
{
  double x = 0.0;
  double y = 0.0;

  for (int i = 1; i <= NMAX; i++) {
    double zr = x * x - y * y + a;
    double zi = 2 * x * y + b;
    if (zr * zi + zi * zr > 4.0) {
      // *ret_r = zr;
      // *ret_i = zi;
      return log((double)i);
    }
    x = zr;
    y = zi;
  }
  return 0.0;
}
