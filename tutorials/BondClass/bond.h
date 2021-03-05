#ifndef BOND_H
#define BOND_H

class Bond
{
public:
    Bond();

    void setPrincipal(double);
    void setRate(double);
    void setYearsToMaturity(double);
    void setPaymentType(char);

    double getPrincipal();
    double getRate();
    double getYearsToMaturity();
    char getPaymentType();

    
private:   
    double principal;
    double rate;
    double yearsToMaturity;
    char paymentType; // 'A'nnual, 'S'emi-Annual, 'Q'uarterly

};

#endif

