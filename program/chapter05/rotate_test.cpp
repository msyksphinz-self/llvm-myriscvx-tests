int rotate_left()
{
  unsigned int a = 8;
  int result = ((a << 30) | (a >> 2));

  return result;
}
