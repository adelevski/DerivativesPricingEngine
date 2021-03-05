#include "bond.h"
#include <iostream>

Bond::Bond(double prin, double coup, double market, double yTM, char typ)
{
    setPrincipal(prin);
    setCouponRate(coup);
    setMarketRate(market);
    setYearsToMaturity(yTM);
    setPaymentType(typ);
}  

double Bond::getBondPrice()
{
    return 42.0;
}

void Bond::printBondDetails()
{
    std::cout << "Bond Details" << std::endl;
    std::cout << "Principal: " << getPrincipal() << std::endl;
    std::cout << "Coupon Rate: " << getCouponRate() << std::endl;
    std::cout << "Market Rate: " << getMarketRate() << std::endl;
    std::cout << "YearsToMaturity: " << getYearsToMaturity() << std::endl;
    std::cout << "Payment Type: " << getPaymentType() << std::endl;
}

double Bond::getPrincipal(){return principal;}
double Bond::getCouponRate(){return couponRate;}
double Bond::getMarketRate(){return marketRate;}
double Bond::getYearsToMaturity(){return yearsToMaturity;}
char Bond::getPaymentType(){return paymentType;}

void Bond::setPrincipal(double prin){principal=prin;}
void Bond::setCouponRate(double coup){couponRate=coup;}
void Bond::setMarketRate(double market){marketRate=market;}
void Bond::setYearsToMaturity(double yTM){yearsToMaturity=yTM;}
void Bond::setPaymentType(char typ){paymentType=typ;}


