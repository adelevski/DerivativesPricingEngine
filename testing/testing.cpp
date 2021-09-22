#include <math.h>
#include <iostream>
#include <vector>


int f(int& x)
{
    x = x - 1;
    return x;
}




int main()
{
    int n = 6;
    std::vector<double> X (n, 5);
    for (int i = 0; i < (n-1)/2; i++)
    {
        // int ind = 2*i;
        std::cout << X[2*i] << X[2*i+1] << std::endl;
    }
    
}