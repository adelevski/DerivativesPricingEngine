#include <iostream>
#include "bond.h"

int main(int argc, const char * argv[])
{
    Bond basicBond;
    std::cout << "Principal: " << basicBond.getPrincipal() << std::endl;
    std::cout << "Basic Bond Price: " << basicBond.getBondPrice() << std::endl;

    Bond tailoredBond(1000, 100, 100, 'S');
    std::cout << "Principal: " << tailoredBond.getPrincipal() << std::endl;
    std::cout << "Tailored Bond Price: " << tailoredBond.getBondPrice() << std::endl;

    return 0;
}