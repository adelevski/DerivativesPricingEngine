#include <iostream>
#include "BSM.h"

enum BSMExecution
{
    ASSET = 1,
    STIKE = 2,
    GROWTH = 3,
    VOLATILITY = 4,
    YEARS = 5, 
    STEPS = 6, 
    SIMULATIONS = 7
};

int main(int argc, const char * argv[])
{                           
    BSM bsm(atof(argv[ASSET]), 
            atof(argv[STIKE]), 
            atof(argv[GROWTH]),
            atof(argv[VOLATILITY]),
            atof(argv[YEARS]),
            atol(argv[STEPS]),
            atol(argv[SIMULATIONS]));

    std::cout << "Asset:  " << bsm.getBsmAsset() << std::endl <<
                 "Strike: " << bsm.getBsmStrike() << std::endl <<
                 "Growth: " << bsm.getBsmGrowth() << std::endl <<
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

