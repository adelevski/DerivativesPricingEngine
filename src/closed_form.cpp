#include "closed_form.hpp"

#include <math.h>

#include "math_functions.hpp"


cf_prices black_scholes(input& in)
{
    double d1 = (log(in.S / in.K) + (in.r - in.q + 0.5 * in.v * in.v) * in.T) / in.v / sqrt(in.T);
    double d2 = d1 - in.v * sqrt(in.T);
    cf_prices cp;
    cp.cf_call = in.S * exp(-in.q * in.T) * norm_cdf(d1) - in.K * exp(-in.r * in.T) * norm_cdf(d2);
    cp.cf_put = cp.cf_call - in.S * exp(-in.q * in.T) + in.K * exp(-in.r * in.T);
    return cp;
}