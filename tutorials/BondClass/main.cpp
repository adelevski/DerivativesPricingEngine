#include <iostream>
#include "bond.h"

int main(int argc, const char * argv[])
{
    try
    {
        Bond tailoredBond(7000, 0.07, 0.15, 12, 'S');
        tailoredBond.printBondDetails();
        tailoredBond.printBondPrice();
    }
    catch(int error)
    {
        std::cout << "Bond creation failed, ERROR: " << error << std::endl;
    }

    return 0;
}