extern int global_value;

int global_update(int inc)
{
  int ret = global_value;
  global_value += inc;
  return ret;
}
