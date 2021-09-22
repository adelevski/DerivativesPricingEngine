#include "math_functions.h"
#include "black_scholes.h"
#include <math.h>


double black_scholes(
    double S,
    double K,
    double T,
    double v,
    double q,
    double r,
    char put_call)
{

  double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / v / sqrt(T);
  double d2 = d1 - v * sqrt(T);
  double call = S * exp (-q * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
  if (put_call == 'C')
  {
      return call;
  }
  else
  {
      return call - S * exp(-q * T) + K * exp(-r * T);
  }
}