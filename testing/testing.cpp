#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(1);
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d(0,1);
 
    std::map<int, int> hist;
    for(int n=0; n<100000; ++n) {
        ++hist[std::round(d(gen))];
    }
    for(auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/1000, '*') << '\n';
    }
}


std::random_device rd;
  std::mt19937 gen(rd());
  gen.seed(1);
  std::normal_distribution<> d(0,1);

  d(gen)