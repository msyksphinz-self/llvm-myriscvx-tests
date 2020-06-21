#include <stdio.h>
#include "mandelbrot.h"

#define SCALE (1000)

int main() {
  const int width = 640, height = 480;
  // const int width = 320, height = 240;
  // const int width = 160, height = 120;
  double rstart = -0.32, rstop = 0.32;
  double istart = -0.24, istop = 0.24;
  printf("P2\n%d %d\n%d\n", width, height, (int)(log(NMAX) * SCALE));

  for (int y = 0; y < height; y++) {
    double y_target = y * (istop - istart) / height;
    for (int x = 0; x < width; x++) {
      double x_target = x * (rstop - rstart) / width;
      double ret_r, ret_i;
      double color = mandelbrot(x_target, y_target, &ret_r, &ret_i);
      int int_color = (int)(color * SCALE);

      printf("%d\n", int_color);
    }
  }

  return 0;
}
