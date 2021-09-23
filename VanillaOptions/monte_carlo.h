#pragma once

#include "input_funcs.h"


struct sim_prices
{
    double sim_call;
    double sim_put;
};

sim_prices monte_carlo(
    input& in);