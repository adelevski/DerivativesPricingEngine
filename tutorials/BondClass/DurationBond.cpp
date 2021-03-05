#include "DurationBond.h"
#include <iostream>

DurationBond::DurationBond(double prin, double coup, double market, double yTM, char typ) : Bond(prin, coup, market, yTM, typ)
{

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
}

double DurationBond::getDuration()
{
    return duration;
}

void DurationBond::setDuration(double inpDurn)
{
    duration = inpDurn;
}

