#pragma once

#include "input.hpp"


struct sim_prices
{
    double sim_call;
    double sim_put;
};

sim_prices euro_monte_carlo(input& in);

sim_prices asian_monte_carlo(asian_input& in);