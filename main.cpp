#include "output.hpp"



int main()
{
    while (true)
    {
        Input in = get_input();
        if (in.option_ptr[1] == Option*)
        {
            double call = monte_carlo(in, in.option_ptr[0]);
            double put = monte_carlo(in, in.option_ptr[1]);
            Cf_prices cp = black_scholes(in);
            print_results(in, call, put, cp);
        }
        else
        {
            double d_digital = monte_carlo(in, in.option_ptr[0]);
            std::cout << "Double Digital: " << d_digital << std::endl;
        }
        int again = repeat();
        if (again == 0)
        {
            break;
        }
    }
}


