extern int global;
extern int external_func(int global, int i);

int object_sample(int a)
{
  int total = external_func(global, a);
  for (int i = 0; i < a; i++) {
    total += i;
  }
  return total;
}
