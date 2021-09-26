#pragma once


class Payoff
{
public:
    enum option_type { call, put, digital_call, digital_put };

    Payoff(double strike, option_type type);

    double operator()(double price) const;

private:
    double strike_;
    option_type type_;
};

