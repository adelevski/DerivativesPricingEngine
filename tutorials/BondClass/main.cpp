#include <iostream>
#include "bond.h"

int main(int argc, const char * argv[])
{
    Bond tailoredBond(1000, 0.1, 0.1, 10, 'S');
    
    tailoredBond.printBondDetails();

    std::cout << "Tailored Bond Price: " << tailoredBond.getBondPrice() << std::endl;

    return 0;
}