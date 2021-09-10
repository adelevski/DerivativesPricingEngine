#include "BlackScholesModel.h"
#include <math.h>
#include <time.h>


BlackScholesModel::BlackScholesModel(float a_price, float s_price, float rfr, 
                                     float vol, float yrs, long steps, long sims)
{
    asset_price = a_price;
    strike_price = s_price;
    rfr = rfr;
    volatility = vol;
    num_years = yrs;
    num_steps = steps;
    num_simulations = sims;
}

BlackScholesModel::~BlackScholesModel(){}

/*

S{PHI}(d1) - Ke-rT{PHI}(d2) 

Asset price 100, Call option, strike price 110

100 -> 101 -> 99 -> 110 -> 125   (15)

100 -> 98 -> 97 -> 54 -> 109      (0)

100 -> 97 -> 112 -> 116 -> 116    (6) +
                                -----
                                  21/3 => 7


 */                               

void BlackScholesModel::log_normal_random_walk()
{
    srand((unsigned)time(0));

    double call_payoff_pot = 0.0;
    double put_payoff_pot = 0.0;

    double time_step = (get_num_years()/get_num_steps());
    double sqrt_ts = sqrt(time_step);

    for (long i = 1; i <= get_num_simulations(); i++)
    {
        double a_price = get_asset_price();

        for(int j = 1; j <= get_num_steps(); j++)
        {
            a_price = a_price * (1 + get_rfr()*time_step + get_volatility()*sqrt_ts*(random_number(12) - 6));
        }

        if (a_price > get_strike_price())
        {
            call_payoff_pot += (a_price - get_strike_price());
        } 
        else if (a_price < get_strike_price())
        {
            put_payoff_pot += (get_strike_price() - a_price);
        }

        if ((i % 10000) == 0)
        {
            std::cout << "." << std::flush;

            if ((i % 100000) == 0)
            {
                std::cout << i/1000 << "k" << std::flush;
            }
        }
    }

    call_price = call_payoff_pot / get_num_simulations();
    put_price = put_payoff_pot / get_num_simulations();
    
    return;
}

double BlackScholesModel::random_number(int num_calcs)
{
    double total = 0.0;
    for(int i = 1; i <= num_calcs; i++)
    {
        total += ((double)rand()/(double)(RAND_MAX + 1.0));
    }
    return total;
}

float BlackScholesModel::get_asset_price(){return asset_price;}
float BlackScholesModel::get_strike_price(){return strike_price;}
float BlackScholesModel::get_rfr(){return rfr;}
float BlackScholesModel::get_volatility(){return volatility;}
float BlackScholesModel::get_num_years(){return num_years;}
long BlackScholesModel::get_num_steps(){return num_steps;}
long BlackScholesModel::get_num_simulations(){return num_simulations;}

double BlackScholesModel::get_call_price(){return call_price;}
double BlackScholesModel::get_put_price(){return put_price;}


