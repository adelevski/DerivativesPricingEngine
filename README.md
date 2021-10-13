# Option Pricing Engine

A lightweight option pricing engine that uses Monte Carlo methods to simulate asset prices for the duration of a given maturity, and uses the results to price call and put contracts. 

Currently implemented:
- European vanilla
- Asian arithmetic fixed-strike
- Asian geometric fixed-strike 

Standard error for European options is calculated using the closed-form Black-Sholes-Merton model for option pricing. 

The very simplistic CLI menu asks the user if they want to price Asian or European, and then asks the user to provide the corresponding inputs before calculating and displaying the results. 

### To Do

- Implement digitals
- Implement double digitals
- Implement American options
- Implement closed form solutions for Asian options

