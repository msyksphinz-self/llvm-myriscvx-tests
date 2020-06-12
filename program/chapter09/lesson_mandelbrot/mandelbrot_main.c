#include <stdio.h>

#define C0r (-0.743)
#define C0i (0.1145)
#define VS  0.003
#define STEP (800.0)

extern double mandelbrot(double a, double b);

int main() {
  double a, b;

  for (a = C0r-VS; a < C0r+VS; a += 2.0*VS/STEP) {
    for (b = C0i-VS; b < C0i+VS; b += 2.0*VS/STEP) {
      printf("%1.14e %1.14e %1.14e\n", a, b, mandelbrot(a, b));
    }
    printf("\n"); // これがないとgnuplotでエラーが出る
  }
  return 0;
}
