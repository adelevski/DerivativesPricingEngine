#include "input.hpp"

#include <iostream>

int repeat()
{
    int again;
    std::cout << "Would you like to price another option?\n";
    std::cout << "0) No, quit.\n";
    std::cout << "1) Yes!\n";
    std::cout << "Choice?: "; std::cin >> again;
    return again;
}

int choice_menu()
{
    int choice;
    std::cout << "Please select the type of option to be priced\n"
    std::cout << "1) European vanilla\n"
    std::cout << "2) European digital\n"
    std::cout << "3) European double digital\n"
    std::cout << "Choice?: "; std::cin >> choice;
    return choice;
}

Input dd_menu()
{
    Input in;
    double years, lower, upper;
    std::cout << "Spot price?: ";     std::cin >> in.spot;
    std::cout << "Lower strike?: ";   std::cin >> lower;
    std::cout << "Upper strike?: ";   std::cin >> upper;
    std::cout << "Years?: ";          std::cin >> years;
    std::cout << "Volatility?: ";     std::cin >> in.volatility;
    std::cout << "Dividend yield?: "; std::cin >> in.dividend;
    std::cout << "RFR?: ";            std::cin >> in.rate;
    std::cout << "Simulations?: ";    std::cin >> in.num_sims;
    PayoffDoubleDigital payoff(lower, upper);
    Option option(payoff, years);
    in.option_ptr[0] = &option;
    return in;
}

Input get_input()
{
    int choice = choice_menu();

    if (choice == 3)
    {
        Input in = dd_menu();
        return in;
    }
    else
    {
        Input in;
        char std;
        std::cout << "Standard input? [y/n]: "; std::cin >> std;
        if (std == 'y')
        {
            in.spot = 100;
            in.volatility = 0.2;
            in.dividend = 0.0;
            in.rate = 0.05;
            in.num_sims = 1e7;
            if (choice == 1)
            {
                PayoffCall call_payoff(100);
                PayoffPut put_payoff(100);
            }
            else if (choice == 2)
            {
                PayoffDigitalCall call_payoff(100);
                PayoffDigitalPut put_payoff(100);
            }
            Option call_option(call_payoff, 1);
            Option put_option(put_payoff, 1);
            in.option_ptr[0] = call_option;
            in.option_ptr[1] = put_option;
        }
        else
        {
            double strike, years;
            std::cout << "Spot price?: ";     std::cin >> in.spot;
            std::cout << "Strike price?: ";   std::cin >> strike;
            std::cout << "Years?: ";          std::cin >> years;
            std::cout << "Volatility?: ";     std::cin >> in.volatility;
            std::cout << "Dividend yield?: "; std::cin >> in.dividend;
            std::cout << "RFR?: ";            std::cin >> in.rate;
            std::cout << "Simulations?: ";    std::cin >> in.num_sims;
            if (choice == 1)
            {
                PayoffCall call_payoff(strike);
                PayoffPut put_payoff(strike);
            }
            else if (choice == 2)
            {
                PayoffDigitalCall call_payoff(strike);
                PayoffDigitalPut put_payoff(strike);
            }
            Option call_option(call_payoff, years);
            Option put_option(put_payoff, years);
            in.option_ptr[0] = call_option;
            in.option_ptr[1] = put_option;
        }
    }

    
	std::cout << "One moment please!\n" << std::endl;
    return in;
}

