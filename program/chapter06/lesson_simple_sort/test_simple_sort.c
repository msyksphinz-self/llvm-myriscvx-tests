#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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


void simple_sort(int numbers[], int array_size);

// #define NUM_ITEMS 10
// int numbers[NUM_ITEMS] = {
//  3840 , 11679, 5789 , 14883, 11411,
//  8775 , 11607, 4386 , 11391, 24758
// };

#define NUM_ITEMS 100
int numbers[NUM_ITEMS] = {
  15515, 4178 , 5341 , 4416 , 19615, 7749 , 21789, 1143 , 22773, 13051,
  26197, 7844 , 4155 , 26292, 974  , 11972, 14815, 14502, 1744 , 14650,
  10123, 5076 , 32631, 8235 , 25286, 5386 , 17116, 19010, 6199 , 14075,
  729  , 21714, 18254, 6070 , 26130, 5101 , 13820, 15151, 6244 , 3825 ,
  28203, 32441, 11669, 32358, 25966, 12643, 11563, 8013 , 27146, 13307,
  22663, 4501 , 18383, 22526, 12737, 10901, 27912, 29853, 29911, 1344 ,
  11160, 30641, 23058, 29414, 3943 , 16421, 1747 , 17763, 31572, 7992 ,
  21588, 27007, 7665 , 490  , 26598, 863  , 13133, 5393 , 8876 , 7511 ,
  18700, 31539, 12013, 4316 , 21297, 24750, 15217, 16442, 21835, 12361,
  17786, 227  , 10234, 8076 , 29642, 14177, 24497, 31389, 31941, 23302
};

int main()
{
  int i;

  simple_sort(numbers, NUM_ITEMS);

  for (i = 0; i < NUM_ITEMS; i++) {
    printf("%d\n", numbers[i]);
    if (i > 1 && numbers[i] < numbers[i-1]) {
      printf("Sort result failed. %d < %d\n", numbers[i], numbers[i-1]);
      return 1;
    }
  }

  printf("Sort succeeded\n");

  return 0;
}
