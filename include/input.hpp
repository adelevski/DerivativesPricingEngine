#pragma once


struct input
{
    double S, K, T, v, q, r;
    int num_sims;
};

input get_simple_input();


struct asian_input : input
{
    char type;
};

asian_input get_asian_input();
