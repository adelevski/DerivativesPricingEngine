#include <math.h>
// #include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

// N(0,1) density
double f(double& x)
{
  // double pi = 4.0 * atan (1.0);
  return exp(-x * x * 0.5) / sqrt(2 * M_PI);
}


// Boole's Rule
double Boole(double&& StartPoint, const double& EndPoint, int&& n)
{
  double X;
  vector<double> Y (n, 0.0);
  double delta_x = (EndPoint - StartPoint) / (double)n;
  for (int i = 0; i < n; i++)
  {
    X = StartPoint + i*delta_x;
    Y[i] = f(X);
  }
  double sum = 0;
  for (int t = 0; t < (n-1) / 4; t++)
  {
    int ind = 4 * t;
    sum += (1/45.0)*(14*Y[ind] + 64*Y[ind + 1] + 24*Y[ind + 2] +
            64*Y[ind + 3] + 14*Y[ind + 4])*delta_x;
  }
  return sum;
}


// N(0,1) cdf by Boole's Rule
double N(double& x)
{
  return Boole(-10.0, x, 240);
}

// Black Scholes closed form price
double BS(double& S, double& K, double& v, double& T, double& r, double& q, char&& PutCall)
{
  double d1 = (log(S/K) + (r - q + 0.5*v*v)*T)/v/sqrt(T);
  double d2 = d1 - v*sqrt(T);
  double Call = S*exp(-q*T)*N(d1) - K*exp(-r*T)*N(d2);
  if (PutCall == 'C')
  {
    return Call;
  }
  else
  {
    return Call - S*exp(-q*T) + K*exp(-r*T); 
  }
}



int main()
{
  srand(time(0)); // Set the seed for random number generation
  double S;       // Spot Price
  double K;       // Strike Price
  double v;       // Volatility
  double q;       // Dividend yeild
  double T;       // Maturity in Years
  double r;       // Interest Rate
  int num_sims;   // Number of simulations

  cout << "Spot price?: "; cin >> S;
	cout << "Strike price?: "; cin >> K;
  cout << "Volatility?: "; cin >> v;
  cout << "Dividend yield?: "; cin >> q;
  cout << "Years?: "; cin >> T;
	cout << "RFR?: "; cin >> r;
	cout << "Simulations?: "; cin >> num_sims;
	cout << "One moment please! \n" << endl;

  double S_current;
  double S_adjusted = S * exp((r - q - 0.5*v*v) * T);
  double Z;                         // Random standard normal Z(0,1)
  double u1, u2;
  double pi = 3.141592653589793;
  double call_pot = 0.0;            // Initialize call payoff
  double put_pot = 0.0;             // Initialize put payoff

  for (int i = 0; i <= num_sims - 1; i++)
  {
    // Independent uniform random variables
    u1 = ((double) rand() / ((double) (RAND_MAX) + (double) (1)));
    u2 = ((double) rand() / ((double) (RAND_MAX) + (double) (1)));
    // Floor u1 to avoid errors with log function
    u1 = max(u1, 1.0e-10);
    // Z ~ N(0,1) by Box-Muller transformation
    Z = sqrt(-2.0*log(u1))*sin(2*pi*u2);
    S_current = S_adjusted * exp(v * sqrt(T) * Z); // Simulated terminal price S(T)
    call_pot += max(S_current - K, 0.0); // Call payoff
    put_pot += max(K - S_current, 0.0); // Put payoff
  }
  // Simulated prices as discounted average of terminal prices
  double BSCallSim = exp(-r*T)*(call_pot / num_sims);
  double BSPutSim = exp(-r*T)*(put_pot / num_sims);
  // Closed form prices
  double BSCall = BS(S, K, v, T, r, q, 'C');
  double BSPut = BS(S, K, v, T, r, q, 'P');
  // Errors
  double CallError = BSCall - BSCallSim;
  double PutError = BSPut - BSPutSim;
  // Output the results
  cout << setprecision (4) << fixed;
  cout << "Using " << num_sims << " simulations..." << endl;
  cout << " " << endl;
  cout << "Method CallPrice PutPrice " << endl;
  cout << "----------------------------------" << endl;
  cout << "Simulation " << BSCallSim << " " << BSPutSim << endl;
  cout << "Closed Form " << BSCall << " " << BSPut << endl;
  cout << "Error " << CallError << " " << PutError << endl;
  cout << "----------------------------------" << endl;
  cout << " " << endl;
}