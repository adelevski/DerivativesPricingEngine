#include "payoff.hpp"

#include <algorithm>

#include "math_functions.hpp"


PayoffCall::PayoffCall(double strike)
    : strike_(strike)
{}

PayoffPut::PayoffPut(double strike)
    : strike_(strike)
{}

PayoffDigitalCall::PayoffDigitalCall(double strike)
    : strike_(strike)
{}

PayoffDigitalPut::PayoffDigitalPut(double strike)
    : strike_(strike)
{}

PayoffDoubleDigital::PayoffDoubleDigital(
    double lower_strike,
    double upper_strike)
    : lower_strike_(lower_strike), upper_strike_(upper_strike)
{}


double PayoffCall::operator()(double price) const
{
    return std::max(price - strike_, 0.0)
}

double PayoffPut::operator()(double price) const
{
    return std::max(strike_ - price, 0.0)
}

double PayoffDigitalCall::operator()(double price) const
{
    return step_func(price - strike_)
}

double PayoffDigitalPut::operator()(double price) const
{
    return step_func(strike_ - price)
}

double PayoffDoubleDigital::operator()(double price) const
{
    if (price >= lower_strike_ && price <= upper_strike_)
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}

Payoff* PayoffCall::clone() const
{
    return new PayoffCall(*this);
}

Payoff* PayoffPut::clone() const
{
    return new PayoffPut(*this);
}

Payoff* PayoffDigitalCall::clone() const
{
    return new PayoffDigitalCall(*this);
}

Payoff* PayoffDigitalPut::clone() const
{
    return new PayoffDigitalPut(*this);
}

Payoff* PayoffDoubleDigital::clone() const
{
    return new PayoffCall(*this);
}