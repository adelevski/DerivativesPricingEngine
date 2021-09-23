#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

#include "math_funcs.h"

struct input
{
    double S, K, T, v, q, r;
    int num_sims;
};

input get_input()
{
    input in;
    char std;
    std::cout << "Standard? [y/n]: "; std::cin >> std;
    if (std == 'y')
    {
        in.S = 100;
        in.K = 100;
        in.T = 1.0;
        in.v = 0.2;
        in.q = 0.0;
        in.r = 0.05;
        in.num_sims = 1e7;
    }
    else
    {
        std::cout << "Spot price?: ";     std::cin >> in.S;
        std::cout << "Strike price?: ";   std::cin >> in.K;
        std::cout << "Years?: ";          std::cin >> in.T;
        std::cout << "Volatility?: ";     std::cin >> in.v;
        std::cout << "Dividend yield?: "; std::cin >> in.q;
        std::cout << "RFR?: ";            std::cin >> in.r;
        std::cout << "Simulations?: ";    std::cin >> in.num_sims;
    }
	std::cout << "One moment please!\n" << std::endl;
    return in;
}

struct sim_prices
{
    double sim_call;
    double sim_put;
};

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

struct cf_prices
{
    double cf_call;
    double cf_put;
};



cf_prices black_scholes(
    input& in)
{
    double d1 = (log(in.S / in.K) + (in.r - in.q + 0.5 * in.v * in.v) * in.T) / in.v / sqrt(in.T);
    double d2 = d1 - in.v * sqrt(in.T);
    cf_prices cp;
    cp.cf_call = in.S * exp(-in.q * in.T) * norm_cdf(d1) - in.K * exp(-in.r * in.T) * norm_cdf(d2);
    cp.cf_put = cp.cf_call - in.S * exp(-in.q * in.T) + in.K * exp(-in.r * in.T);
    return cp;
}

void print_results(
    input& in,
    sim_prices& sp,
    cf_prices& cp)
{
    double call_error = cp.cf_call - sp.sim_call;
    double put_error = cp.cf_put - sp.sim_put;

    std::cout << std::setprecision(4) << std::fixed;
    std::cout << "Using " << in.num_sims << " simulations..."               << std::endl;
    std::cout << "================================="                        << std::endl;
    std::cout << "Method      |   call   |   put   "                        << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Simulation  |  " << sp.sim_call   << " |  " << sp.sim_put << std::endl;
    std::cout << "Closed form |  " << cp.cf_call    << " |  " << cp.cf_put  << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Error:         " << call_error    << "    " << put_error  << std::endl;
    std::cout << "================================="                        << std::endl;
}

int main()
{
    input in = get_input();
    sim_prices sp = monte_carlo(in);
    cf_prices cp = black_scholes(in);
    print_results(in, sp, cp);
}