#include "BSM.h"


BSM::BSM(float ass, float strk, float grwth, float volty, float yrs, long steps, long sims)
{
    bsmAsset = ass;
    bsmStrike = strk;
    bsmGrowth = grwth;
    bsmVol = volty;
    bsmYears = yrs;
    bsmSteps = steps;
    bsmMonteCarloSims = sims;
}

BSM::~BSM(){std::cout << "Destroyed";}

void BSM::logNormalRandomWalk(){}
double BSM::rn(){return 0.0;}

float BSM::getBsmAsset(){return bsmAsset;}
float BSM::getBsmStrike(){return bsmStrike;}
float BSM::getBsmGrowth(){return bsmGrowth;}
float BSM::getBsmVol(){return bsmVol;}
float BSM::getBsmYears(){return bsmYears;}
long BSM::getBsmSteps(){return bsmSteps;}
long BSM::getBsmMonteCarloSims(){return bsmMonteCarloSims;}

double BSM::getCallPrice(){return bsmCallPrice;}
double BSM::getPutPrice(){return bsmPutPrice;}


