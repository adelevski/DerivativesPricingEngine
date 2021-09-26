#pragma once

#include "input.hpp"


struct Sim_prices
{
    double sim_call;
    double sim_put;
};

Sim_prices monte_carlo(
    const Input& in);