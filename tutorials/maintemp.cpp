#include <iostream>
#include <cmath>
#include <iomanip>
#include "functions.h"
#include "globals.h"

int main()
{
    double principal = 0.0;
    double humanInterest = 0.0;
    int yearsOfLoan = 0;

    std::cout << "Enter the principal amount: ";
    std::cin >> principal;
    
    std::cout << "Enter the interest rate: ";
    std::cin >> humanInterest;
    
    std::cout << "Enter the years of loan: ";
    std::cin >> yearsOfLoan;

    double interest = divisor(humanInterest, gPercentDenominator);
    double monthInterest = divisor(interest, gMonthsInYear);
    long monthsOfLoan = multiplier(yearsOfLoan, gMonthsInYear);
    
    double payment = 0.0;
    
    payment = principal *
                (monthInterest /
                 (1 - (pow((double)1 + monthInterest,
                           (double)-monthsOfLoan))));
    
    std::cout << "Payment: " << std::setiosflags(std::ios::fixed) <<
        std::setprecision(2) << payment << std::endl;

    double currInterestPayment = 0.0;
    double currPrincipalPayment = 0.0;
    double currBalance = 0.0;
    
    currBalance = principal;

    long currLoanMonth = 1;

    while(currLoanMonth <= monthsOfLoan)
    {
        gAmortizeMonth amorthMonth;

        currInterestPayment = currBalance * monthInterest;
        currPrincipalPayment = payment - currInterestPayment;
        currBalance = currBalance - currPrincipalPayment;

        amorthMonth.year = 1;
        amorthMonth.yearMonth = 1;
        amorthMonth.loanMonth = currLoanMonth;
        amorthMonth.payment = payment;
        amorthMonth.pureInterest = currInterestPayment;
        amorthMonth.paidDownPrincipal = currPrincipalPayment;
        amorthMonth.principalBalance = currBalance;

        std::cout << "CM: " << amorthMonth.loanMonth;
        std::cout << " CI: " << amorthMonth.pureInterest;
        std::cout << " CP: " << amorthMonth.paidDownPrincipal;
        std::cout << " Bal: " << amorthMonth.principalBalance << std::endl;

        currLoanMonth++;
    }

    std::cout << "Loan complete." << std::endl;
    
    return 0;
}