#include "output.hpp"

#include <iostream>
#include <iomanip>


void print_results(
    const Input& in,
    double sim_call,
    double sim_put,
    const Cf_prices& cp)
{
    double call_error = cp.cf_call - sim_call;
    double put_error = cp.cf_put - sim_put;

    std::cout << std::setprecision(4) << std::fixed;
    std::cout << "Using " << in.num_sims << " simulations...\n";
    std::cout << "=================================\n";
    std::cout << "Method      |   call   |   put   \n";        
    std::cout << "---------------------------------\n";
    std::cout << "Simulation  |  " << sim_call   << " |  " << sim_put;
    std::cout << std::endl;
    std::cout << "Closed form |  " << cp.cf_call << " |  " << cp.cf_put;
    std::cout << std::endl;
    std::cout << "---------------------------------\n";
    std::cout << "Error:         " << call_error  << "    " << put_error;
    std::cout << std::endl;
    std::cout << "=================================\n";
}