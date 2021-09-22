#include <math.h>
#include <iostream>


int f(int& x)
{
    x = x - 1;
    return x;
}




int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << f(i) << std::endl;
    }
}