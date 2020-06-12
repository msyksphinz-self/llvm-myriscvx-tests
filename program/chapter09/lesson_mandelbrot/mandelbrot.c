// #include <math.h>

#define NMAX (20000)


double mandelbrot(double a, double b)
{
  double x = 0.0;
  double y = 0.0;
  double x1, y1;

  int n;

  for (n = 1; n <= NMAX; n++) {
    x1 = x * x - y * y + a;
    y1 = 2.0 * x * y + b;
    if ( x1 * x1 + y1 * y1 > 4.0) return log(n);
    x = x1;
    y = y1;
  }
  return 0;
}
