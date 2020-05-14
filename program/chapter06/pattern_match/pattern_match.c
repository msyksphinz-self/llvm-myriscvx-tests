#include "pattern_match.h"

int pattern_match(struct color *c0,
                  struct color *c1,
                  int threshold)
{
  int red_diff   = c0->red   - c1->red;
  int green_diff = c0->green - c1->green;
  int blue_diff  = c0->blue  - c1->blue;

  return red_diff * red_diff +
      green_diff * green_diff +
      blue_diff * blue_diff;
}
