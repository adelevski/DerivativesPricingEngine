#include "option.hpp"


Option::Option(const Payoff& payoff, double years)
    : years_(years)
{
    payoff_ptr_ = payoff.clone();
}

Option::Option(const Option& original)
{
    years_ = original.years_;
    payoff_ptr_ = original.payoff_ptr_->clone();
}

Option& Option::operator=(const Option& original)
{
    if (this != original)
    {
        years_ = original.years_;
        delete payoff_ptr_;
        payoff_ptr_ = original.payoff_ptr_->clone();
    }
    return *this;
}

Option::~Option()
{
    delete payoff_ptr_;
}

double Option::get_years() const
{
    return years_;
}

double Option::option_payoff(double spot) const
{
    return (*payoff_ptr_)(spot);
}