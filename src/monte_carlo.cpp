#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>

#include "payoff.hpp"


Sim_prices monte_carlo(
    Input& in)
{
    double S_current, call_pot, put_pot;
    double S_adjusted = in.spot * exp((in.rate - in.dividend - 
                            0.5 * in.volatility * in.volatility) * in.years);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    Payoff call_payoff(in.strike, Payoff::call);
    Payoff put_payoff(in.strike, Payoff::put)

    for (int i = 0; i < in.num_sims; i++)
    {
        S_current = S_adjusted * exp(in.volatility * sqrt(in.years) * d(gen));
        call_pot += call_payoff(S_current);
        put_pot += put_payoff(S_current);
    }
    Sim_prices sp;
    sp.sim_call = exp(-in.rate * in.years) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.rate * in.years) * (put_pot / in.num_sims);
    return sp;
}