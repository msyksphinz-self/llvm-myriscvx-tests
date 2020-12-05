int if_ctrl(int a, int b, int c, int d)
{
  int ret;
  if (a < b) {
 	ret = c;
  } else {
    ret = d;
  }
  return ret;
}
