#include "print_funcs.hpp"

#include <iostream>
#include <iomanip>


void print_results(
    input& in,
    sim_prices& sp,
    cf_prices& cp)
{
    double call_error = cp.cf_call - sp.sim_call;
    double put_error = cp.cf_put - sp.sim_put;

    std::cout << std::setprecision(4) << std::fixed;
    std::cout << "Using " << in.num_sims << " simulations..."               << std::endl;
    std::cout << "================================="                        << std::endl;
    std::cout << "Method      |   call   |   put   "                        << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Simulation  |  " << sp.sim_call   << " |  " << sp.sim_put << std::endl;
    std::cout << "Closed form |  " << cp.cf_call    << " |  " << cp.cf_put  << std::endl;
    std::cout << "---------------------------------"                        << std::endl;
    std::cout << "Error:         " << call_error    << "    " << put_error  << std::endl;
    std::cout << "================================="                        << std::endl;
}