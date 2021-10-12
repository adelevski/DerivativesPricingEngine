# Option Pricing Engine

A lightweight option pricing engine that uses Monte Carlo methods to simulate asset prices after a given amount of time, and uses the results to price call and put contracts. Currently the engine is able to price European vanilla, Asian arithmetic fixed-strike, and Asian geometric fixed-strike options. Standard error for European options is calculated using the closed-form Black-Sholes-Merton model for option pricing. 

The very simplistic GUI asks the user if they want to price Asian or European, and then asks the user to input the corresponding inputs before displaying the results. 

### To Do

- Implement digitals
- Implement double digital
- Implement closed form solutions for Asian options
