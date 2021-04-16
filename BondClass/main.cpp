#include <iostream>
#include "bond.h"
#include "DurationBond.h"

int main(int argc, const char * argv[])
{
    try
    {
        DurationBond db(1000, 0.07, 0.08, 10, 'S');
        double bondPrice = db.getBondPrice();
        std::cout << "dbPrice: " << bondPrice << std::endl;
        
        double dbDuration = db.getDuration();
        std::cout << "dbDuration: " << dbDuration << std::endl;
    }
    catch(int error)
    {
        std::cout << "Bond creation failed, ERROR: " << error << std::endl;
    }

    return 0;
}