#pragma once


double black_scholes(
    double S,
    double K,
    double T,
    double v,
    double q,
    double r,
    char put_call);