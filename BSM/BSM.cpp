#include "BSM.h"
#include <math.h>
#include <time.h>


BSM::BSM(float ass, float strk, float rfr, float volty, float yrs, long steps, long sims)
{
    bsmAsset = ass;
    bsmStrike = strk;
    bsmRFR = rfr;
    bsmVol = volty;
    bsmYears = yrs;
    bsmSteps = steps;
    bsmMonteCarloSims = sims;
}

BSM::~BSM(){}

/*

S{PHI}(d1) - Ke-rT{PHI}(d2) 

Asset price 100, Call option, strike price 110

100 -> 101 -> 99 -> 110 -> 125   (15)

100 -> 98 -> 97 -> 54 -> 109      (0)

100 -> 97 -> 112 -> 116 -> 116    (6) +
                                -----
                                  21/3 => 7


 */                               

void BSM::logNormalRandomWalk()
{
    srand((unsigned)time(0));

    double callPayoffPot = 0.0;
    double putPayoffPot = 0.0;

    double timeStep = (getBsmYears()/getBsmSteps());
    double sqrtTs = sqrt(timeStep);

    for (long i = 1; i <= getBsmMonteCarloSims(); i++)
    {
        double ass = getBsmAsset();

        for(int j = 1; j <= getBsmSteps(); j++)
        {
            ass = ass * (1 + getBsmRFR()*timeStep + getBsmVol()*sqrtTs*(rn(12) - 6));
        }

        // std::cout << "Final ass: " << ass << std::endl;

        if (ass > getBsmStrike())
        {
            callPayoffPot += (ass - getBsmStrike());
        } 
        else if (ass < getBsmStrike())
        {
            putPayoffPot += (getBsmStrike() - ass);
        }
        // std::cout << "Call Pot: " << callPayoffPot << std::endl;
        // std::cout << "Put pot:  " << putPayoffPot << std::endl;
        if ((i % 10000) == 0)
        {
            std::cout << "." << std::flush;

            if ((i % 100000) == 0)
            {
                long iMess = i/1000;

                std::cout << iMess << "k" << std::flush;
            }
        }
    }
    bsmCallPrice = callPayoffPot / getBsmMonteCarloSims();
    bsmPutPrice = putPayoffPot / getBsmMonteCarloSims();
    return;
}

double BSM::rn(int numCalcs)
{
    double total = 0.0;
    for(int i = 1; i <= numCalcs; i++)
    {
        total += (double)rand()/(double)(RAND_MAX + 1.0);
    }
    return total;
}

float BSM::getBsmAsset(){return bsmAsset;}
float BSM::getBsmStrike(){return bsmStrike;}
float BSM::getBsmRFR(){return bsmRFR;}
float BSM::getBsmVol(){return bsmVol;}
float BSM::getBsmYears(){return bsmYears;}
long BSM::getBsmSteps(){return bsmSteps;}
long BSM::getBsmMonteCarloSims(){return bsmMonteCarloSims;}

double BSM::getCallPrice(){return bsmCallPrice;}
double BSM::getPutPrice(){return bsmPutPrice;}


