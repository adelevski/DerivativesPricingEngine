#ifndef BOND_H
#define BOND_H

class Bond
{
public:

    const char BOND_ANNUAL_TYPE = 'A';
    const char BOND_SEMIANNUAL_TYPE = 'S';
    const char BOND_QUARTERLY_TYPE = 'Q';

    Bond(double, double, double, double, char);

    double getBondPrice();
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

