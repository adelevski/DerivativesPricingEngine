#include "bond.h"
#include <iostream>
#include <cmath>

Bond::Bond(double prin, double coup, double market, double yTM, char typ)
{
    setPrincipal(prin);
    setCouponRate(coup);
    setMarketRate(market);
    setYearsToMaturity(yTM);
    setPaymentType(typ);
}  

void Bond::printBondPrice()
{
    int scalingFactor;

    if (getPaymentType() == BOND_ANNUAL_TYPE)
    {
        scalingFactor = ANNUAL_FACTOR;
    }
    else if (getPaymentType() == BOND_SEMIANNUAL_TYPE)
    {
        scalingFactor = SEMIANNUAL_FACTOR;
    }
    else if (getPaymentType() == BOND_QUARTERLY_TYPE)
    {
        scalingFactor = QUARTERLY_FACTOR;
    }

    double coupon = getPrincipal() * (getCouponRate()/scalingFactor);
    double periods = getYearsToMaturity() * scalingFactor;
    double yield = getMarketRate() / scalingFactor;
    double pvCoupons = (coupon * (1 - pow((1 + yield), -periods)))/yield;
    double pvRedemption = getPrincipal() * pow((1 + yield), -periods);
    double bondPrice = pvCoupons + pvRedemption;
   
    std::cout << "Coupon: " << coupon << std::endl;
    std::cout << "Periods: " << periods << std::endl;
    std::cout << "Yield: " << yield << std::endl;
    std::cout << "PV of Coupons: " << pvCoupons << std::endl;
    std::cout << "PV of Redemption: " << pvRedemption << std::endl;
    std::cout << "Internal Bond Price: " << bondPrice << std::endl;
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


