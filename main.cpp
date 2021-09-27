#include "output.hpp"

#include <iostream>


char repeat()
{
    char choice;
    std::cout << "Would you like to price another option? [y/n]: ";
    std::cin >> choice;
    return choice; 
}

int main()
{
    while (true)
    {
        input in = get_input();
        sim_prices sp = monte_carlo(in);
        cf_prices cp = black_scholes(in);
        print_results(in, sp, cp);
        char choice = repeat();
        if (choice != 'y')
        {
            break;
        }
    }
}

