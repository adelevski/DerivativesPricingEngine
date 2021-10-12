#pragma once

#include "input.hpp"
#include "monte_carlo.hpp"
#include "closed_form.hpp"


void print_simple_results(
    input& in,
    sim_prices& sp,
    cf_prices& cp
);


void print_asian_results(
    asian_input& in,
    sim_prices& sp
);