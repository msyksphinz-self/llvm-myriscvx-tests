#include <math.h>

void test_fp_math(float *a, float *b, float *c, float *result)
{
  float res_fmad  = *a * *b + *c;
  float res_fsub  = *a * *c - res_fmad;
  float res_fnmadd = (-*b) * *c + res_fsub;
  float res_fnmsub = (-*a) * *c - res_fnmadd;
  *result = res_fnmsub;
}

void test_dp_math(double *a, double *b, double *c, double *result)
{
  double res_fmad  = *a * *b + *c;
  double res_fsub  = *a * *b - res_fmad;
  double res_fnmadd = (-*b) * *c + res_fsub;
  double res_fnmsub = (-*a) * *c - res_fnmadd;
  *result = res_fnmsub;
}
