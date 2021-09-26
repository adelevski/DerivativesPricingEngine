#include "input.hpp"

#include <iostream>


Input get_input()
{
    Input in;
    char std;
    std::cout << "Standard? [y/n]: "; std::cin >> std;
    if (std == 'y')
    {
        in.spot = 100;
        in.strike = 100;
        in.years = 1.0;
        in.volatility = 0.2;
        in.dividend = 0.0;
        in.rate = 0.05;
        in.num_sims = 1e7;
    }
    else
    {
        std::cout << "Spot price?: ";     std::cin >> in.spot;
        std::cout << "Strike price?: ";   std::cin >> in.strike;
        std::cout << "Years?: ";          std::cin >> in.years;
        std::cout << "Volatility?: ";     std::cin >> in.volatility;
        std::cout << "Dividend yield?: "; std::cin >> in.dividend;
        std::cout << "RFR?: ";            std::cin >> in.rate;
        std::cout << "Simulations?: ";    std::cin >> in.num_sims;
    }
	std::cout << "One moment please!\n" << std::endl;
    return in;
}

