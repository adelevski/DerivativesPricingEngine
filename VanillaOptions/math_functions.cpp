#include <math.h>
#include "math_functions.h"


double norm_cdf(double x)
{
    return std::erfc(-x / std::sqrt(2)) / 2;
}

