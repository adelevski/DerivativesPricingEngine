#pragma once


struct Input
{
    double S, K, T, v, q, r;
    int num_sims;
};

Input get_input();

