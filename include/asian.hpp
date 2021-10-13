#pragma once

#include <vector>

#include "payoff.hpp"


class asian_option
{
public:
    asian_option() {};
    virtual ~asian_option() {};
    virtual double payoff_price(const std::vector<double>& S_vec) const = 0;
};


class arithmetic_asian : public asian_option
{
public:
    arithmetic_asian(payoff& po);
    virtual ~arithmetic_asian() {};
    virtual double payoff_price(const std::vector<double>& S_vec) const;

private:
    payoff& po_;
};


class geometric_asian : public asian_option 
{
public:
    geometric_asian(payoff& po);
    virtual ~geometric_asian() {};
    virtual double payoff_price(const std::vector<double>& S_vec) const;

private:
    payoff& po_;
};

