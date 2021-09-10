#include <iostream>
#include "BlackScholesModel.h"

int main(int argc, const char * argv[])
{ 
    float a_price;
    float s_price;
    float rfr;
    float vol;
    float yrs;
    long steps;
    long sims;

    std::cout << "Asset price?: "; std::cin >> a_price;
    std::cout << "Strike price?: "; std::cin >> s_price;
    std::cout << "RFR?: "; std::cin >> rfr;
    std::cout << "Volatility?: "; std::cin >> vol;
    std::cout << "Years?: "; std::cin >> yrs;
    std::cout << "Steps?: "; std::cin >> steps;
    std::cout << "Simulations?: "; std::cin >> sims;
    std::cout << "One moment please! \n" << std::endl;

    BlackScholesModel BlackScholesModel(a_price, s_price, rfr, vol, yrs, steps, sims);

    BlackScholesModel.log_normal_random_walk();

    std::cout << std::endl;
     
    std::cout << "Call option price: " << BlackScholesModel.get_call_price() << std::endl;
    std::cout << "Put option price: " << BlackScholesModel.get_put_price() << std::endl;

    return 0;
}

