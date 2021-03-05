#include <iostream>
#include <cmath>
#include <iomanip>
#include "functions.h"
#include "globals.h"

enum AmortizeProgram
{
    LOAN_PRINCIPAL = 1,
    INTEREST_RATE = 2,
    YEARS_OF_LOAN = 3
};

enum AmortEnum
{
    YR_OUT = 2,
    MN_OUT = 2,
    CUM_MN_OUT = 5,
    PAYMENT_OUT = 12,
    INTEREST_OUT = 12,
    PRINCIPAL_OUT = 12,
    BALANCE_OUT = 16,
};

int main(int argc, char* argv[])
{
    double principal = 0.0;
    double humanInterest = 0.0;
    int yearsOfLoan = 0;
    
    if (argc == 1)
    {
        std::cout << "Enter the principal amount: ";
        std::cin >> principal;
        
        std::cout << "Enter the interest rate: ";
        std::cin >> humanInterest;
        
        std::cout << "Enter the years of loan: ";
        std::cin >> yearsOfLoan;
    }
    else
    {
        principal = atof(argv[LOAN_PRINCIPAL]);
        humanInterest = atof(argv[INTEREST_RATE]);
        yearsOfLoan = atoi(argv[YEARS_OF_LOAN]);

    }

    std::cout << "Loan Principal: $" << principal << std::endl;
    std::cout << "Interest Rate: " << humanInterest << "%" << std::endl;

    if (yearsOfLoan == 1)
    {
         std::cout << "Time Period: " << yearsOfLoan << " year" << std::endl;
    }
    else
    {
         std::cout << "Time Period: " << yearsOfLoan << " years" << std::endl;
    }

   

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

        std::cout << 
            std::setw(YR_OUT) << amorthMonth.year << " " <<
            std::setw(MN_OUT) << amorthMonth.yearMonth << " " <<
            std::setw(CUM_MN_OUT) << amorthMonth.loanMonth << " " <<
            std::setw(PAYMENT_OUT) << amorthMonth.payment << " " <<
            std::setw(INTEREST_OUT) << amorthMonth.pureInterest << " " <<
            std::setw(PRINCIPAL_OUT) << amorthMonth.paidDownPrincipal << " " <<
            std::setw(BALANCE_OUT) << amorthMonth.principalBalance <<
            std::endl;

        currLoanMonth++;
    }

    std::cout << "Loan complete." << std::endl;
    
    return 0;
}