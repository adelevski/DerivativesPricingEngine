#include <iostream>
#include "BSM.h"

int main(int argc, const char * argv[])
{ 
    float asset;
    float strike;
    float rfr;
    float volatility;
    float years;
    long steps;
    long simulations;

    std::cout << "Asset price?: "; std::cin >> asset;
    std::cout << "Strike price?: "; std::cin >> strike;
    std::cout << "RFR?: "; std::cin >> rfr;
    std::cout << "Volatility?: "; std::cin >> volatility;
    std::cout << "Years?: "; std::cin >> years;
    std::cout << "Steps?: "; std::cin >> steps;
    std::cout << "Simulations?: "; std::cin >> simulations;
    std::cout << "One moment please! \n" << std::endl;

    BSM bsm(asset, strike, rfr, volatility, years, steps, simulations);

    std::cout << "Asset:  " << bsm.getBsmAsset() << std::endl <<
                 "Strike: " << bsm.getBsmStrike() << std::endl <<
                 "RFR:    " << bsm.getBsmRFR() << std::endl <<
                 "Vol:    " << bsm.getBsmVol() << std::endl <<
                 "Years:  " << bsm.getBsmYears() << std::endl <<
                 "Steps:  " << bsm.getBsmSteps() << std::endl <<
                 "Sims:   " << bsm.getBsmMonteCarloSims() << std::endl;

    bsm.logNormalRandomWalk();

    std::cout << std::endl;
     
    std::cout << "Call option price: " << bsm.getCallPrice() << std::endl;
    std::cout << "Put option price: " << bsm.getPutPrice() << std::endl;

    return 0;
}

