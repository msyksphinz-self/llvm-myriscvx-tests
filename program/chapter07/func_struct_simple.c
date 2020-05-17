#define STRUCT_SIZE (5)

struct S
{
  int x[STRUCT_SIZE];
};

int func (struct S elem) {
  int total = 0;
  for(int i = 0; i < STRUCT_SIZE; i++) {
    total += elem.x[i];
  }
  return total;
}

int call_func () {
  struct S elem;
  for (int i = 0; i < STRUCT_SIZE; i++) {
    elem.x[i] = i;
  }
  return func (elem);
}
