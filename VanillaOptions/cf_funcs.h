#pragma once
#include "input_funcs.h"


struct cf_prices
{
    double cf_call;
    double cf_put;
};

cf_prices black_scholes(
    input& in);