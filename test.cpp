#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>



// Standard normal probability density function
double norm_pdf(const double& x)
{
    return (1.0/(pow(2*M_PI, 0.5)))*exp(-0.5*x*x);
}



int main()
{
    std::cout << norm_pdf(5) << std::endl;
    return 0;
}