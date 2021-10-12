#include "asian.hpp"

#include <math.h>
#include <numeric>


asian_option::asian_option(payoff* po)
    :po_(po)
{}


arithmetic_asian::arithmetic_asian(payoff* po)
    : asian_option(po)
{}

double arithmetic_asian::payoff_price(const std::vector<double>& S_vec) const
{
    int period = S_vec.size();
    double sum = std::accumulate(S_vec.begin(), S_vec.end(), 0);
    double mean = sum / period;
    return (*po_)(mean);
}


geometric_asian::geometric_asian(payoff* po)
    : asian_option(po)
{}

double geometric_asian::payoff_price(const std::vector<double>& S_vec) const
{
    int period = S_vec.size();
    double sum = 0.0;
    for (int i = 0; i < period; i++)
    {
        sum += log(S_vec[i]);
    }
    double mean = exp(sum / period);
    return (*po_)(mean);
}