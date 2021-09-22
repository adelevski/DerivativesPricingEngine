
#include <math.h>
#include <vector>
#include "math_functions.h"


// Standard normal distribution probability density function
double norm_pdf(double x)
{
  double pi = 4.0 * atan (1.0);
  return exp(-0.5 * x * x) / sqrt(2 * pi);
}


// Boole's Rule
double booles_rule(double start_point, double end_point, int n)
{
  double X;
  std::vector<double> Y (n + 1, 0.0);
  double delta_x = (end_point - start_point) / double (n);
  for (int i = 0; i <= n; i++)
  {
    X = start_point + i*delta_x;
    Y[i] = f(X);
  }
  double sum = 0;
  for (int t = 0; t <= (n - 1) / 4; t++)
  {
    int ind = 4 * t;
    sum += (1/45.0)*(14*Y[ind] + 64*Y[ind + 1] + 24*Y[ind + 2] +
            64*Y[ind + 3] + 14*Y[ind + 4])*delta_x;
  }
  return sum;
}


// N(0,1) cdf by Boole's Rule
double N(double x)
{
  return Boole(-10.0, x, 240);
}