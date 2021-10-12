#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>
#include <vector>

#include "asian.hpp"
#include "payoff.hpp"


sim_prices euro_monte_carlo(
    input& in)
{
    double S_current, call_pot, put_pot, shock;
    double drift = exp((in.r - in.q - 0.5 * in.v * in.v) * in.T);
    double S_adjusted = in.S * drift;
    double vol_dt = in.v * sqrt(in.T);

    call_payoff call_po(in.K);
    put_payoff put_po(in.K);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        shock = exp(vol_dt * d(gen));
        S_current = S_adjusted * shock;
        call_pot += call_po(S_current);
        put_pot += put_po(S_current);
    }
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}



sim_prices asian_monte_carlo(
    input& in)
{
    double call_pot, put_pot, shock;
    double dt = 1 / 252.0;
    double period = static_cast<int>(in.T * 252);
    double drift = exp((in.r - in.q - 0.5 * in.v * in.v) * dt);
    double vol_dt = in.v * sqrt(dt);
    std::vector<double> S_vec(period);

    call_payoff call_po(in.K);
    call_payoff* call_ptr = &call_po;

    put_payoff put_po(in.K);
    put_payoff* put_ptr = &put_po;

    arithmetic_asian asian_call(call_ptr);
    arithmetic_asian asian_put(put_ptr);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    gen.seed(time(0));

    for (int i = 0; i < in.num_sims; i++)
    {
        S_vec[0] = in.S;

        for (int i = 1; i < period; i++)
        {
            shock = exp(vol_dt * d(gen));
            S_vec[i] = S_vec[i-1] * drift * shock;
        }

        call_pot += asian_call.payoff_price(S_vec);
        put_pot += asian_put.payoff_price(S_vec);
    }
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}