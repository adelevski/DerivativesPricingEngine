#ifndef BOND_H
#define BOND_H

class Bond
{
public:

    const char BOND_ANNUAL_TYPE = 'A';
    const char BOND_SEMIANNUAL_TYPE = 'S';
    const char BOND_QUARTERLY_TYPE = 'Q';

    const int ANNUAL_FACTOR = 1;
    const int SEMIANNUAL_FACTOR = 2;
    const int QUARTERLY_FACTOR = 4;

    Bond(double, double, double, double, char);

    void printBondPrice();
    void printBondDetails();

    void setPrincipal(double);
    void setCouponRate(double);
    void setMarketRate(double);
    void setYearsToMaturity(double);
    void setPaymentType(char);

    double getPrincipal();
    double getCouponRate();
    double getMarketRate();
    double getYearsToMaturity();
    char getPaymentType();

    
private:   
    double principal;
    double couponRate;
    double marketRate;
    double yearsToMaturity;
    char paymentType; // 'A'nnual, 'S'emi-Annual, 'Q'uarterly

};

#endif

