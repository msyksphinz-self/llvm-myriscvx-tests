int compare_slt(int a, int b)
{
  int c, d, e, f, g, h;

  c = (a == b); // seq, c = 0
  d = (a != b); // sne, d = 1
  e = (a < b);  // slt, e = 0
  f = (a <= b); // sle, f = 0
  g = (a > b);  // sgt, g = 1
  h = (a >= b); // sge, g = 1

  return (c+d+e+f+g+h); // 3
}
