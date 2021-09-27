#pragma once

#include "input.hpp"
#include "monte_carlo.hpp"
#include "closed_form.hpp"

void print_results(
    Input& in,
    double sim_call,
    double put_call,
    Cf_prices& cp);