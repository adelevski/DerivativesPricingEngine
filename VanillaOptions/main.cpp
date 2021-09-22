#include "black_scholes.h"
#include "monte_carlo.h"
#include <iostream>
#include <iomanip>


int main()
{
    double S, K, T, v, q, r; // spot, strike, vol, div, yrs, rfr
    int num_sims;            // Number of simulations
    char std;

    std::cout << "Standard? [y/n]: "; std::cin >> std;
    if (std == 'y')
    {
        S = 100;
        K = 100;
        T = 1.0;
        v = 0.2;
        q = 0.0;
        r = 0.05;
        num_sims = 1e7;
    }
    else
    {
        std::cout << "Spot price?: ";     std::cin >> S;
        std::cout << "Strike price?: ";   std::cin >> K;
        std::cout << "Years?: ";          std::cin >> T;
        std::cout << "Volatility?: ";     std::cin >> v;
        std::cout << "Dividend yield?: "; std::cin >> q;
        std::cout << "RFR?: ";            std::cin >> r;
        std::cout << "Simulations?: ";    std::cin >> num_sims;
    }
	std::cout << "One moment please!\n" << std::endl;

    vanilla_payoff payoff = vanilla_monte_carlo(S, K, T, v, q, r, num_sims);
    
    // Closed form prices
    double bs_call = black_scholes(S, K, T, v, q, r, 'C');
    double bs_put = black_scholes(S, K, T, v, q, r, 'P');

    // Errors
    double call_error = bs_call - payoff.sim_call;
    double put_error = bs_put - payoff.sim_put;

    // Output the results
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << "================================="                              << std::endl;
    std::cout << "Method      |   call   |   put   "                              << std::endl;
    std::cout << "---------------------------------"                              << std::endl;
    std::cout << "Simulation  |  " << payoff.sim_call << " |  " << payoff.sim_put << std::endl;
    std::cout << "Closed form |  " << bs_call         << " |  " << bs_put         << std::endl;
    std::cout << "---------------------------------"                              << std::endl;
    std::cout << "Error:         " << call_error      << "    " << put_error      << std::endl;
    std::cout << "================================="                              << std::endl;
}