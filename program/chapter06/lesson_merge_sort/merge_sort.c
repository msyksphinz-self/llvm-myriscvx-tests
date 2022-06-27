#define SORT_MAX_NUM 128

void merge_sort_impl (int array[], int left, int right) {
  int i, j, k, mid;
  int work[SORT_MAX_NUM];
  if (left < right) {
    mid = (left + right)/2;
    merge_sort_impl(array, left, mid);
    merge_sort_impl(array, mid+1, right);

    for (i = mid; i >= left; i--) {
      work[i] = array[i];
    }
    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j];
    }
    i = left; j = right;
    for (k = left; k <= right; k++) {
      if (work[i] < work[j]) { array[k] = work[i++]; }
      else                   { array[k] = work[j--]; }
    }
  }
}


int merge_sort(int array[], int array_size)
{
  if (array_size > SORT_MAX_NUM) {
    return -1;
  }
  merge_sort_impl(array, 0, array_size-1);
  return 0;
}
