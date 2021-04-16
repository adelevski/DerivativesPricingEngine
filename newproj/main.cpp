#include <iostream>
#include <iomanip>

class Trader
{
    public:
        Trader(double);

        void tripleBonus();
        double getBonus();

    private:
        double bonus;
};

Trader::Trader(double initialBonus)
{
    bonus = initialBonus;
}

void Trader::tripleBonus()
{
    bonus *= 3;
}

double Trader::getBonus()
{
    return bonus;
}

void valueBoostBonus(Trader &valueTrad)
{
    valueTrad.tripleBonus();

    return;
}

int main(int argc, const char * argv[])
{
    Trader trader(1000000.01);

    std::cout  << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    std::cout << "Trader initial bonus: " << trader.getBonus() << std::endl;

    valueBoostBonus(trader);
    
    std::cout << "Value, bonus now: " << trader.getBonus() << std::endl;

    return 0;
}