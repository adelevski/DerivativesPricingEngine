#include <iostream>
#include "bond.h"

int main(int argc, const char * argv[])
{
    Bond tailoredBond(7000, 0.07, 0.15, 12, 'S');

    tailoredBond.printBondDetails();
    tailoredBond.printBondPrice();

    return 0;
}