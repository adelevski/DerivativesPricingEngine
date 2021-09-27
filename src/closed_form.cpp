#include "closed_form.hpp"

#include <math.h>

#include "math_functions.hpp"


// Cf_prices black_scholes(
//     Input& in)
// {
//     double d1 = (log(in.spot / in.strike) + 
//             (in.rate - in.dividend + 0.5 * in.volatility * in.volatility) * 
//             in.years) / in.volatility / sqrt(in.years);
//     double d2 = d1 - in.volatility * sqrt(in.years);

//     Cf_prices cp;
//     cp.cf_call = in.spot * exp(-in.dividend * in.years) * norm_cdf(d1) - 
//                     in.strike * exp(-in.rate * in.years) * norm_cdf(d2);
//     cp.cf_put = cp.cf_call - in.spot * exp(-in.dividend * in.years) + 
//                             in.strike * exp(-in.rate * in.years);
//     return cp;
// }