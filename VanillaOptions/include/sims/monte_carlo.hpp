#pragma once

#include "input/input_funcs.hpp"


struct sim_prices
{
    double sim_call;
    double sim_put;
};

sim_prices monte_carlo(
    input& in);