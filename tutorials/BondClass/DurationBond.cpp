#include "DurationBond.h"
#include <iostream>

DurationBond::DurationBond(double prin, double coup, double market, double yTM, char typ) : Bond(prin, coup, market, yTM, typ)
{
    setDuration( calculateDuration() );
}

DurationBond::~DurationBond()
{

}

double DurationBond::calculateDuration()
{
    // Get the current YTM of the bond
    double origMarketRate = getMarketRate();
    // Shock interest rate factor is 'Y', it is the difference between rates, we often call it a 'Delta'
    double deltaY = DURATION_BOND_RATE_CHANGE;
    if (origMarketRate <= DURATION_BOND_RATE_CHANGE)
    {
        deltaY = origMarketRate - 0.0001;
    }
    // V1 is the CURRENT bond price 
    double v1 = getBondPrice();
    // Shock the interest rate down by deltaY
    double bipsLower = origMarketRate - deltaY;
    std::cout << "Original Market Rate: " << origMarketRate << std::endl;
    std::cout << "deltaY: " << deltaY << std::endl;
    std::cout << "Current bond price, v1: " << v1 << std::endl;
    std::cout << "BipsLower: " << bipsLower << std::endl;


    setMarketRate(bipsLower);
    double v2 = getBondPrice();
    // Shock the interest rate up by deltaY
    double bipsHigher = origMarketRate + deltaY;
    std::cout << "Higher bond price, v2: " << v2 << std::endl;
    std::cout << "BipsHigher: " << bipsHigher << std::endl;


    setMarketRate(bipsHigher);
    double v3 = getBondPrice();
    std::cout << "Lower bond price, v3: " << v3 << std::endl;


    // Reset YTM to actual current rate :)
    setMarketRate(origMarketRate);
    // Calculate the Bond duration (Duration = V2 - V3 / 2(V1)(DeltaY))
    double calcDuration = (v2 - v3) / (2 * v1 * deltaY);
    std::cout << "Internal, calcDuration: " << calcDuration << std::endl;
    return calcDuration;
}

double DurationBond::getDuration()
{
    return duration;
}

void DurationBond::setDuration(double inpDurn)
{
    duration = inpDurn;
}

