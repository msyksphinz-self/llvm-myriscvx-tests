#include <stdio.h>
#include "pattern_match.h"

int pattern_match(struct color *c0,
                  struct color *c1);

int main ()
{
  struct color c0, c1;
  c0.red   = 62;
  c0.green = 92;
  c0.blue  = 212;

  c1.red   = 44;
  c1.green = 46;
  c1.blue  = 129;

  int result = pattern_match(&c0, &c1);

  int red_diff   = c0.red   - c1.red;
  int green_diff = c0.green - c1.green;
  int blue_diff  = c0.blue  - c1.blue;

  int answer = red_diff * red_diff +
      green_diff * green_diff +
      blue_diff * blue_diff;

  if (result == answer) {
    printf("Correct.");
  } else {
    printf("Incorrect.");
  }
  printf(" Result = %d, Answer = %d\n", result, answer);

  return 0;
}
