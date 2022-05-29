int simple_pattern_match(int p0_a, int p0_b,
                         int p1_a, int p1_b,
                         int p2_a, int p2_b,
                         int p3_a, int p3_b,
                         int p4_a, int p4_b,
                         int threshold)
{
  int p0_diff = p0_a - p0_b;
  int p1_diff = p1_a - p1_b;
  int p2_diff = p2_a - p2_b;
  int p3_diff = p3_a - p3_b;
  int p4_diff = p4_a - p4_b;

  int result = p0_diff * p0_diff +
      p1_diff * p1_diff +
      p2_diff * p2_diff +
      p3_diff * p3_diff +
      p4_diff * p4_diff;

  return (result < threshold);

}
