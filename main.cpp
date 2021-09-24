#include "print_funcs.hpp"


int main()
{

    input in = get_input();
    sim_prices sp = monte_carlo(in);
    cf_prices cp = black_scholes(in);
    print_results(in, sp, cp);
}


