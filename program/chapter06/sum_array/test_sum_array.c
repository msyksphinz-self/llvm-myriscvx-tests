#include <stdio.h>
int global_value = 0;

int sum_array(int array[10], int idx0, int idx1, int idx2);

int test(int array[], int idx0, int idx1, int idx2)
{
  int sum = sum_array(array, idx0, idx1, idx2);

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (i == idx0) { ans += array[i]; }
    if (i == idx1) { ans += array[i]; }
    if (i == idx2) { ans += array[i]; }
  }
  if (sum == ans) {
    printf("Result = %d. Correct\n", sum);
    return 0;
  } else {
    printf("Incorrect = %d != %d\n", sum, ans);
    return 1;
  }
}

int main ()
{
  int test_array[] = {239, -213, 363, 586, -1000, 475, -5, 158, -859, -648};

  test(test_array, 0, 1, 2);
  test(test_array, 0, 2, 4);
  test(test_array, 1, 5, 9);
  test(test_array, 5, 9, 2);
  test(test_array, 8, 9, 0);
  test(test_array, 9, 7, 3);

  return 0;
}
