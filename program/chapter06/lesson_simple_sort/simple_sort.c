int select_min_index(int array[], int start_index, int array_size)
{
  int min = start_index;
  for (int j = start_index+1; j < array_size; j++) {
    if (array[j] < array[min]) {
      min = j;
    }
  }
  return min;
}


void simple_sort(int array[], int array_size)
{
  for (int i = 0; i < array_size-1; i++) {
    int min = select_min_index(array, i, array_size);
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}
