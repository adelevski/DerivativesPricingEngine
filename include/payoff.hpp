#pragma once


class payoff 
{
public:
    payoff() {};
    virtual ~payoff() {};
    virtual double operator()(const double& S) const = 0;
};


class call_payoff : public payoff 
{
public:
    call_payoff(const double& K);
    virtual ~call_payoff() {};
    virtual double operator()(const double& S) const;

private:
    double K_;
};


class put_payoff : public payoff 
{
public:
    put_payoff(const double& K);
    virtual ~put_payoff() {};
    virtual double operator()(const double& S) const;

private:
    double K_;
};