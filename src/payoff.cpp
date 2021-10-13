#include "payoff.hpp"

#include <algorithm>



call_payoff::call_payoff(const double& K)
    : K_(K)
{}

double call_payoff::operator()(const double& S) const 
{
    return std::max(S - K_, 0.0);
}


put_payoff::put_payoff(const double& K)
    : K_(K)
{}

double put_payoff::operator()(const double& S) const 
{
    return std::max(K_ - S, 0.0);
}