#ifndef BlackScholesModel_H
#define BlackScholesModel_H

#include <iostream>

class BlackScholesModel
{
    public:
        BlackScholesModel(float, float, float, float, float, long, long);

        ~BlackScholesModel();

        float get_asset_price();
        float get_strike_price();
        float get_rfr();
        float get_volatility();
        float get_num_years();
        long get_num_steps();
        long get_num_simulations();

        void log_normal_random_walk();
        double get_call_price();
        double get_put_price();

        double random_number(int); 

    private:
        
        float asset_price;
        float strike_price;
        float rfr;
        float volatility;
        float num_years;
        long num_steps;
        long num_simulations;

        double call_price;
        double put_price;
};

#endif