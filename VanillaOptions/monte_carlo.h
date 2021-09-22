#pragma once


struct vanilla_payoff
{
    double sim_call, sim_put;
};

vanilla_payoff vanilla_monte_carlo(
    double S,
    double K,
    double T,
    double v,
    double q,
    double r,
    int num_sims);