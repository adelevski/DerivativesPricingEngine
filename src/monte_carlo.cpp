#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>


sim_prices monte_carlo(
    input& in)
{
    double S_current, call_pot, put_pot;
    double S_adjusted = in.S * exp((in.r - in.q - 0.5 * in.v * in.v) * in.T);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        S_current = S_adjusted * exp(in.v * sqrt(in.T) * d(gen));
        call_pot += std::max(S_current - in.K, 0.0);
        put_pot += std::max(in.K - S_current, 0.0);
    }
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}