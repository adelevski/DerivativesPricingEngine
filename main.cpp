#include "output.hpp"

#include <iostream>


int main()
{
    while (true)
    {
        Input in = get_input();
        double sim_price = monte_carlo(in);
        std::cout << "Sim: " << sim_price << std::endl;
        // Cf_prices cp = black_scholes(in);
        // print_results(in, call, put, cp);
        int again = repeat();
        if (again == 0)
        {
            break;
        }
    }
}


