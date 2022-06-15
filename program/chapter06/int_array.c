int int_array()
{
  volatile int array[4] = {100, 200, 300, 400};

  int a = array[0];
  int b = array[1];
  array[2] = 301;

  return 0;
}
