int g = 100;
int test_g_acess() {
  int update = 101;
  int c = g;
  g = update;
  return c;
}
