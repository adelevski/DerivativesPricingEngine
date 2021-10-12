#include "input.hpp"

#include <iostream>


input get_simple_input()
{
    input in;
    char choice;
    std::cout << "Debug input? [y/n]: "; std::cin >> choice;
    if (choice == 'y')
    {
        in.S = 100;
        in.K = 100;
        in.T = 1.0;
        in.v = 0.2;
        in.q = 0.0;
        in.r = 0.05;
        in.num_sims = 1e5;
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


asian_input get_asian_input()
{
    asian_input in;
    char choice;
    std::cout << "Arithmetic or Geometric pricing? [a/g]: "; std::cin >> choice;
    if (choice == 'a')
    {
        in.type = 'a';
    }
    else if (choice == 'g')
    {
        in.type = 'g';
    }
    else
    {
        std::cout << "Improper input, setting to arithmetic." << std::endl;
    }
    std::cout << "Spot price?: ";     std::cin >> in.S;
    std::cout << "Strike price?: ";   std::cin >> in.K;
    std::cout << "Years?: ";          std::cin >> in.T;
    std::cout << "Volatility?: ";     std::cin >> in.v;
    std::cout << "Dividend yield?: "; std::cin >> in.q;
    std::cout << "RFR?: ";            std::cin >> in.r;
    std::cout << "Simulations?: ";    std::cin >> in.num_sims;
    std::cout << "One moment please!\n" << std::endl;
    return in;
}