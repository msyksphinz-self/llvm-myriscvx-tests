void process_list(int *array, int size);

int func_caller()
{
  int array[100];
  for (int i = 0; i < 100; i++) {
    array[i] = i;
  }
  process_list(array, 100);
}


void process_list(int *array, int size)
{
  for (int i = 0; i < 100; i++) {
    *array = *array + 1;
    array++;
  }
}
