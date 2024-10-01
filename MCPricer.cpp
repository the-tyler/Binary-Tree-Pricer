//
// Created by Sarp Nalcin on 28/02/2024.
//

#include "MCPricer.h"
#include <iostream>

double MCPricer::GenStockPrice(const Option& option, double stockPrice, double vol, double rate) {

    double z_i = RandNumGen::BoxMuller();
    double T = option.GetTimeToExpiration();
    double st_i = stockPrice*exp((rate - vol*vol/2.0)*T + vol*z_i*sqrt(T));
    return st_i;
};

double MCPricer::Price(const Option& option, double stockPrice, double vol, double rate, unsigned long paths) {

    double T = option.GetTimeToExpiration();

    for(unsigned int i=0; i<paths; ++i){

        double st_i = GenStockPrice(option, stockPrice, vol, rate);
        double payoff = option.GetExpirationPayoff(st_i);
        double price_i = exp(-rate*T)*payoff;
        prc_container.push_back(price_i);
    }
    double sum = 0.0;
    // Iterate over the elements of price_vec and accumulate their sum
    for (double value : prc_container) {
        sum += value;
    }
    // Calculate the average by dividing the sum by the number of elements in price_vec
    double average_price = sum / prc_container.size();

    return average_price;

};