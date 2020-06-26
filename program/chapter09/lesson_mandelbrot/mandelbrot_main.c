#include <stdio.h>
#include "mandelbrot.h"

#define SCALE (1000)

int main() {
  const int width = 640, height = 480;
  // const int width = 320, height = 240;
  // const int width = 160, height = 120;
  double rstart = -2.3, rstop = 0.7;
  double istart = -1.5, istop = 1.5;
  printf("P2\n%d %d\n%d\n", width, height, (int)(log(NMAX) * SCALE));

  for (int y = 0; y < height; y++) {
    double y_target = (y * (istop - istart) / height);
    for (int x = 0; x < width; x++) {
      double x_target = (x * (rstop - rstart) / width);
      double color = mandelbrot(x_target, y_target);
      int int_color = (int)(color * SCALE);

      printf("%d ", int_color);
    }
    printf("\n");
  }

  return 0;
}
