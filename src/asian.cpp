#include "asian.hpp"

#include <math.h>
#include <numeric>



arithmetic_asian::arithmetic_asian(payoff& po)
    : po_(po)
{}

double arithmetic_asian::payoff_price(const std::vector<double>& S_vec) const
{
    int period = S_vec.size();
    double sum = std::accumulate(S_vec.begin(), S_vec.end(), 0);
    double mean = sum / period;
    return po_(mean);
}


geometric_asian::geometric_asian(payoff& po)
    : po_(po)
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
    return po_(mean);
}