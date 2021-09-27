#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>

#include "payoff.hpp"


double monte_carlo(
    const Input& in,
    const Payoff& payoff)
{
    double cur_price, pot;
    double adjustment = in.spot * exp((in.rate - in.dividend - 
                            0.5 * in.volatility * in.volatility) * in.years);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        cur_price = adjustment * exp(in.volatility * sqrt(in.years) * d(gen));
        pot += payoff(cur_price)
    }
    final_price = exp(-in.rate * in.years) * (pot / in.num_sims);
    return final_price;
}