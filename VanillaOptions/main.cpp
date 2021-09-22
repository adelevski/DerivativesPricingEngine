#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

struct vanilla_input
{
    double S, K, T, v, q, r;
    int num_sims;
};

void get_vanilla_input(vanilla_input& in)
{
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
}

struct vanilla_payoff
{
    double sim_call;
    double sim_put;
};

void vanilla_monte_carlo(
    vanilla_input& in,
    vanilla_payoff& payoff)
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
    payoff.sim_call = exp(-in.r * in.T) * (call_pot / in.num_sims);
    payoff.sim_put = exp(-in.r * in.T) * (put_pot / in.num_sims);
}

struct bs_results
{
    double bs_call;
    double bs_put;
};

double norm_cdf(double x)
{
    return std::erfc(-x / std::sqrt(2)) / 2;
}

void black_scholes(
    vanilla_input& in,
    bs_results& results)
{
    double d1 = (log(in.S / in.K) + (in.r - in.q + 0.5 * in.v * in.v) * in.T) / in.v / sqrt(in.T);
    double d2 = d1 - in.v * sqrt(in.T);
    results.bs_call = in.S * exp(-in.q * in.T) * norm_cdf(d1) - in.K * exp(-in.r * in.T) * norm_cdf(d2);
    results.bs_put = results.bs_call - in.S * exp(-in.q * in.T) + in.K * exp(-in.r * in.T);
}

void print_results(
    vanilla_payoff& sp,
    bs_results& cfp)
{
    double call_error = cfp.bs_call - sp.sim_call;
    double put_error = cfp.bs_put - sp.sim_put;

    std::cout << std::setprecision(4) << std::fixed;
    std::cout << "================================="                        << std::endl;
    std::cout << "Method      |   call   |   put   "                        << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Simulation  |  " << sp.sim_call   << " |  " << sp.sim_put << std::endl;
    std::cout << "Closed form |  " << cfp.bs_call   << " |  " << cfp.bs_put << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Error:         " << call_error    << "    " << put_error  << std::endl;
    std::cout << "================================="                        << std::endl;
}

int main()
{
    vanilla_input in;
    get_vanilla_input(in);

    vanilla_payoff sp;
    vanilla_monte_carlo(in, sp);

    bs_results cfp;
    black_scholes(in, cfp);

    print_results(sp, cfp);
}