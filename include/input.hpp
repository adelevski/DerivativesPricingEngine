#pragma once
#include "option.hpp"


struct Input
{
    Option* option_ptr[2];
    double spot, volatility, dividend, rate;
    int num_sims;
};


Input get_input();

int repeat();
int choice_menu();
Input dd_menu();