#include "input_funcs.h"

#include <iostream>


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

