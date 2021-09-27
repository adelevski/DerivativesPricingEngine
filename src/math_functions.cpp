#include "math_functions.hpp"

#include <math.h>


double norm_cdf(double x)
{
    return std::erfc(-x / std::sqrt(2)) / 2;
}