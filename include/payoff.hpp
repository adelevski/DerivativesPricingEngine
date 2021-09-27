#pragma once


class Payoff
{
public:
    Payoff() {};
    virtual double operator()(double price) const = 0;
    virtual ~Payoff() {};

private:
};


class PayoffCall : public Payoff
{
public:
    PayoffCall(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffCall() {};
private:
    double strike_;
}

class PayoffPut : public Payoff
{
public:
    PayoffPut(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffPut() {};
private:
    double strike_;
}

class PayoffDigitalCall : public Payoff
{
public:
    PayoffDigitalCall(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDigitalCall() {};
private:
    double strike_;
}

class PayoffDigitalPut : public Payoff
{
public:
    PayoffDigitalPut(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDigitalPut() {};
private:
    double strike_;
}


class PayoffDoubleDigital : public Payoff
{
public:
    PayoffDoubleDigital(double upper_strike, double lower_strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDoubleDigital() {};
private:
    double upper_strike_;
    double lower_strike_;
}