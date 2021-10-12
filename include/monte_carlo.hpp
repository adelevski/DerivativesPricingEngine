#pragma once

#include "input.hpp"


struct sim_prices
{
    double sim_call;
    double sim_put;
};

sim_prices simple_monte_carlo(
    input& in);

sim_prices path_dependent_monte_carlo(
    input& in);