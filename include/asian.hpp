#pragma once

#include <vector>

#include "payoff.hpp"


class asian_option
{
protected:
    payoff* po;

public:
    asian_option(payoff* po);
    virtual ~asian_option() {};

    virtual double payoff_price(const std::vector<double>& S) const = 0;
};
