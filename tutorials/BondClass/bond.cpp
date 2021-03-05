#include "bond.h"
#include <iostream>

Bond::Bond()
{
    std::cout << "I have created a default Bond" << std::endl;

    principal = 100.0;
    rate = 0.1;
    yearsToMaturity = 1.0;
    paymentType = 'A';

}   

double Bond::getPrincipal(){return principal;}
double Bond::getRate(){return rate;}
double Bond::getYearsToMaturity(){return yearsToMaturity;}
char Bond::getPaymentType(){return paymentType;}

void Bond::setPrincipal(double principal){principal=principal;}
void Bond::setRate(double rate){rate=rate;}
void Bond::setYearsToMaturity(double yearsToMaturity){yearsToMaturity=yearsToMaturity;}
void Bond::setPaymentType(char paymentType){paymentType=paymentType;}


