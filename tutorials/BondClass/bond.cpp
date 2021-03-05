#include "bond.h"
#include <iostream>

Bond::Bond()
{
    std::cout << "I have created a default Bond" << std::endl;

    setPrincipal(100.0);
    setRate(0.1);
    setYearsToMaturity(1.0);
    setPaymentType('A');

}   

Bond::Bond(double prin, double rat, double yTM, char typ)
{
    std::cout << "I have created a tailored Bond" << std::endl;

    setPrincipal(prin);
    setRate(rat);
    setYearsToMaturity(yTM);
    setPaymentType(typ);

}  

double Bond::getBondPrice()
{
    return 42.0;
}

double Bond::getPrincipal(){return principal;}
double Bond::getRate(){return rate;}
double Bond::getYearsToMaturity(){return yearsToMaturity;}
char Bond::getPaymentType(){return paymentType;}

void Bond::setPrincipal(double prin){principal=prin;}
void Bond::setRate(double rat){rate=rat;}
void Bond::setYearsToMaturity(double yTM){yearsToMaturity=yTM;}
void Bond::setPaymentType(char typ){paymentType=typ;}


