#include "math_functions.hpp"

#include <math.h>


double norm_cdf(double& x)
{
    return std::erfc(-x / std::sqrt(2)) / 2;
}

double step_func(double& x)
{
    if (x >= 0)
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}