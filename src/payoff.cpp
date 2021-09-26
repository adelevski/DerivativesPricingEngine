#include "payoff.hpp"

#include <math.h>

#include "math_functions.hpp"


Payoff::Payoff(double strike, option_type type)
    : strike_(strike), type_(type)
{
}

double Payoff::operator()(double price) const
{
    switch(type_)
    {
        case call:
            return std::max(price - strike_, 0.0);
        case put:
            return std::max(strike_ - price, 0.0);
        case digital_call:
            return step_func(price - strike_);
        case digital_put:
            return step_func(strike_ - price);
        default:
            throw("Use proper option type!");
    }
}