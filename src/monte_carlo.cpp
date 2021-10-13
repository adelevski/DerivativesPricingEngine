#include "monte_carlo.hpp"

#include <math.h>
#include <random>
#include <time.h>
#include <vector>

#include "asian.hpp"
#include "payoff.hpp"


sim_prices euro_monte_carlo(input& in)
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



sim_prices asian_monte_carlo(asian_input& in)
{
    double call_pot, put_pot, shock;
    double dt = 1 / 252.0;
    double period = static_cast<int>(in.T * 252);
    double drift = exp((in.r - in.q - 0.5 * in.v * in.v) * dt);
    double vol_dt = in.v * sqrt(dt);
    std::vector<double> S_vec(period);

    call_payoff call_po(in.K);
    put_payoff put_po(in.K);
    asian_option* asian_call_ptr;
    asian_option* asian_put_ptr;

    if (in.type == 'a')
    {
        asian_call_ptr = new arithmetic_asian(call_po);
        asian_put_ptr = new arithmetic_asian(put_po);
    }
    else
    {
        asian_call_ptr = new geometric_asian(call_po);
        asian_put_ptr = new geometric_asian(put_po);
    }

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

        call_pot += (*asian_call_ptr).payoff_price(S_vec);
        put_pot += (*asian_put_ptr).payoff_price(S_vec);
    }
    delete asian_call_ptr;
    delete asian_put_ptr;
    sim_prices sp;
    sp.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    sp.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
    return sp;
}