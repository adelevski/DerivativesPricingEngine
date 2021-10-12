#include "output.hpp"

#include <iostream>


char repeat()
{
    char choice;
    std::cout << "Would you like to price another option? [y/n]: ";
    std::cin >> choice;
    return choice; 
}

char type()
{
    char choice;
    std::cout << "Asian or European? [a/e]: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    while (true)
    {
        char choice = type();
        if (choice == 'a')
        {
            asian_input in = get_asian_input();
            sim_prices sp = asian_monte_carlo(in);
            print_asian_results(in, sp);
        }
        else if (choice == 'e')
        {
            input in = get_simple_input();
            sim_prices sp = euro_monte_carlo(in);
            cf_prices cp = black_scholes(in);
            print_simple_results(in, sp, cp);
        }
        else
        {
            break;
        }
        
        choice = repeat();
        if (choice != 'y')
        {
            break;
        }
    }
}

