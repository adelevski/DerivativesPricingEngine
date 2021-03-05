#include <iostream>
#include "bond.h"
#include "DurationBond.h"

int main(int argc, const char * argv[])
{
    try
    {
        Bond tailoredBond(7000, 0.07, 0.15, 12, 'S');
        tailoredBond.printBondPrice();

        DurationBond db(7000, 0.07, 0.15, 36, 'A');
        db.printBondPrice();
    }
    catch(int error)
    {
        std::cout << "Bond creation failed, ERROR: " << error << std::endl;
    }

    return 0;
}