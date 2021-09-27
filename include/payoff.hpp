#pragma once


class Payoff
{
public:
    Payoff() {};
    virtual double operator()(double price) const = 0;
    virtual ~Payoff() {};
    virtual Payoff* clone() const = 0;

private:
};


class PayoffCall : public Payoff
{
public:
    PayoffCall(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffCall() {};
    virtual Payoff* clone() const;
private:
    double strike_;
};

class PayoffPut : public Payoff
{
public:
    PayoffPut(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffPut() {};
    virtual Payoff* clone() const;
private:
    double strike_;
};

class PayoffDigitalCall : public Payoff
{
public:
    PayoffDigitalCall(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDigitalCall() {};
    virtual Payoff* clone() const;
private:
    double strike_;
};

class PayoffDigitalPut : public Payoff
{
public:
    PayoffDigitalPut(double strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDigitalPut() {};
    virtual Payoff* clone() const;
private:
    double strike_;
};


class PayoffDoubleDigital : public Payoff
{
public:
    PayoffDoubleDigital(double lower_strike, double upper_strike);
    virtual double operator()(double price) const;
    virtual ~PayoffDoubleDigital() {};
    virtual Payoff* clone() const;
private:
    double lower_strike_;
    double upper_strike_;
};