int local_pointer()
{
  int b = 3;
  int* local_ptr_b = &b;

  return *local_ptr_b;
}
