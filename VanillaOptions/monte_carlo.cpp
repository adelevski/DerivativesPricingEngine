#include "monte_carlo.h"
#include <math.h>
#include <random>
#include <time.h>
#include <algorithm>


vanilla_payoff vanilla_monte_carlo(
    double S,
    double K,
    double T,
    double v,
    double q,
    double r,
    int num_sims)
{
    double S_current, call_pot, put_pot;
    double S_adjusted = S * exp((r - q - 0.5 * v * v) * T);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    for (int i = 0; i < num_sims; i++)
    {
        S_current = S_adjusted * exp(v * sqrt(T) * d(gen));
        call_pot += std::max(S_current - K, 0.0);
        put_pot += std::max(K - S_current, 0.0);
    }

    vanilla_payoff payoff;
    payoff.sim_call = exp(-r * T) * (call_pot / num_sims);
    payoff.sim_put = exp(-r * T) * (put_pot / num_sims);
    return payoff;
}
