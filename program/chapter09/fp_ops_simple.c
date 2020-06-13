void fp_math_simple(float *a, float *b,
                    float *res_add, float *res_sub, float *res_mul, float *res_div)
{
  *res_add = *a + *b;
  *res_sub = *a - *b;
  *res_mul = *a * *b;
  *res_div = *a / *b;
}


void fp_math_double(double *a, double *b,
                    double *res_add, double *res_sub, double *res_mul, double *res_div)
{
  *res_add = *a + *b;
  *res_sub = *a - *b;
  *res_mul = *a * *b;
  *res_div = *a / *b;
}
