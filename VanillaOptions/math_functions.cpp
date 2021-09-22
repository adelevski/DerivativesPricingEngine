
#include <math.h>
#include <vector>
#include "math_functions.h"


// Standard normal distribution probability density function
double norm_pdf(double x)
{
  return exp(-0.5 * x * x) / sqrt(2 * M_PI);
}


// Boole's Rule
double booles_rule(double start_point, double end_point, int n)
{
  double X;
  std::vector<double> Y(n);
  double delta_x = (end_point - start_point) / (double)n;
  for (int i = 0; i < n; i++)
  {
    X = start_point + i * delta_x;
    Y[i] = norm_pdf(X);
  }
  double sum = 0;
  for (int t = 0; t < (n - 1) / 4; t++)
  {
    sum += (1 / 45.0) * (14 * Y[4 * t] + 
                         64 * Y[4 * t + 1] + 
                         24 * Y[4 * t + 2] +
                         64 * Y[4 * t + 3] + 
                         14 * Y[4 * t + 4]) * delta_x;
  }
  return sum;
}


// Standard normal distribtuion CDF by Boole's Rule
double booles_cdf(double x)
{
  return booles_rule(-10.0, x, 240);
}