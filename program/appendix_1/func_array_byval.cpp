#define ARRAY (17)

int func (int elem[ARRAY]) {
  int total = 0;
  for(int i = 0; i < ARRAY; i++) {
    total += elem[i];
  }
  return total;
}

int call_func () {
  int elem[ARRAY];
  for (int i = 0; i < ARRAY; i++) {
    elem[i] = i + 1;
  }
  return func (elem);
}
