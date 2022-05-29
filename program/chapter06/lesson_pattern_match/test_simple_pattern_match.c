#include <stdio.h>

extern int simple_pattern_match(int p0_a, int p0_b,
                                int p1_a, int p1_b,
                                int p2_a, int p2_b,
                                int p3_a, int p3_b,
                                int p4_a, int p4_b,
                                int threshold);

int main ()
{
  int search_data[5] = {2594, 249, 60, 195, 323};
  int target_data[5] = {243, 764, 598, 183, 60};

  int result = simple_pattern_match(search_data[0], target_data[0],
                                    search_data[1], target_data[1],
                                    search_data[2], target_data[2],
                                    search_data[3], target_data[3],
                                    search_data[4], target_data[4],
                                    6000000);

  printf("Pattern Match Result = %d\n", result);
}
