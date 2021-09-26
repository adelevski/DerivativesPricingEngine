#include "output.hpp"


int main()
{
    Input in = get_input();
    Sim_prices sp = monte_carlo(in);
    Cf_prices cp = black_scholes(in);
    print_results(in, sp, cp);
}


