#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>

#include "payoff.hpp"


sim_prices simple_monte_carlo(
    input& in)
{
    double S_current, call_pot, put_pot;
    double S_adjusted = in.S * exp((in.r - in.q - 0.5 * in.v * in.v) * in.T);

    call_payoff call_po(in.K);
    put_payoff put_po(in.K);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        S_current = S_adjusted * exp(in.v * sqrt(in.T) * d(gen));
        call_pot += call_po(S_current);
        put_pot += put_po(S_current);
    }
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}



sim_prices path_dependent_monte_carlo(
    input& in)
{
    double call_pot, put_pot;
    double dt = in.T / 253.0;

    call_payoff call_po(in.K);
    put_payoff put_po(in.K);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, sqrt(dt));
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        double T = in.T;
        double S_current = in.S;
        double dYt = 0.0;

        while (T - dt > 0)
        {
            dYt = (in.r - in.q) * dt * S_current + in.v * S_current * d(gen);
            S_current += dYt;
            T -= dt;
        }
        call_pot += call_po(S_current);
        put_pot += put_po(S_current);
    }
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}