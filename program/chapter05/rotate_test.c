int rotate_left(int a)
{
  int result = ((a << 30) | (a >> 2));

  return result;
}
