#pragma once

#include "payoff.hpp"



class Option
{
public:
    Option(const Payoff& payoff, double years);
    Option(const Option& original);
    Option& operator=(const Option& original);
    ~Option();

    double get_years() const;
    double option_payoff(double spot) const;
private:
    double years_;
    Payoff* payoff_ptr_;
};