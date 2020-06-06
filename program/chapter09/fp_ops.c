#include <cmath>

void test_fp_math(float *a, float *b, float *c)
{
  float res_add = *a + *b + *c;
  float res_sub = *a - *b - *c;
  float res_mul = *a * *b * *c;
  float res_div = *a / *b / *c;

  float res_fmad  = fmaf(*a, *b, *c);
  float res_fsub  = *a * *b - *c;
  float res_fnmsub = (-*a) * *b + *c;
  float res_fnmadd = (-*a) * *b - *c;
}

void test_dp_math(double *a, double *b, double *c)
{
  double res_add = *a + *b + *c;
  double res_sub = *a - *b - *c;
  double res_mul = *a * *b * *c;
  double res_div = *a / *b / *c;

  double res_fmad  = fma(*a, *b, *c);
  // double res_fsub  = *a * *b - *c;
  // double res_fnmsub = (-*a) * *b + *c;
  // double res_fnmadd = (-*a) * *b - *c;
}
