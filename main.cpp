#include <iostream>
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "AmericanCall.h"
#include "AmericanPut.h"
#include "EuropeanBinaryCall.h"
#include "EuropeanBinaryPut.h"
#include "MCPricer.h"
#include "BSPricer.h"
#include "JRBinomialTree.h"


int main() {
    double stockPrice = 100.0;
    double K = 100.0;
    double T = 1.0;
    double vol = 0.3;
    double rate = 0.05;

    // For Binary Tree Pricer
    int step = 1000;

    // For Monte Carlo Simulation
    std::vector<double> paths = {10000, 100000, 1000000};

    // Seed the random number generator for Monte Carlo Simulation
    for (double path: paths){

        std::cout << "MC SIMULATION NUMBER OF PATHS: " << path << std::endl;
        std::cout << "CALL" << std::endl;
        MCPricer mc1;
        EuropeanCall eu_call(K, T);
        //EuropeanBinaryCall eu_b_call(K, T);

        // Re-seed the random number generator for Monte Carlo Simulation
        srand(static_cast<unsigned int>(time(0)));
        double mcEUCallPrice = mc1.Price(eu_call, stockPrice, vol, rate, path);
        // Re-seed the random number generator for Monte Carlo Simulation
        //srand(static_cast<unsigned int>(time(0)));
        //double mcBCallPrice = mc1.Price(eu_b_call, stockPrice, vol, rate, path);
        std:: cout << "MC Simulation European Call Price: " << mcEUCallPrice << std::endl;
        //std:: cout << "MC Simulation Binary Call Price: " << mcBCallPrice << std::endl;

        BSPricer bs;
        double bsEUCallPrice = bs.Price(eu_call, stockPrice, rate, vol);
        //double bsBCallPrice = bs.Price(eu_b_call, stockPrice, rate, vol);
        std:: cout << "Black-Scholes European Call Price: " << bsEUCallPrice << std::endl;
        //std:: cout << "Black-Scholes Binary Call Price: " << bsBCallPrice << std::endl << std::endl;

        std::cout << "PUT" << std::endl;
        MCPricer mc2;
        EuropeanPut eu_put(K, T);
        //EuropeanBinaryPut eu_b_put(K, T);

        // Re-seed the random number generator for Monte Carlo Simulation
        srand(static_cast<unsigned int>(time(0)));
        double mcEUPutPrice = mc2.Price(eu_put, stockPrice, vol, rate, path);
        // Re-seed the random number generator for Monte Carlo Simulation
        //srand(static_cast<unsigned int>(time(0)));
        //double mcBPutPrice = mc2.Price(eu_b_put, stockPrice, vol, rate, path);
        std::cout << "MC Simulation European Put Price: " << mcEUPutPrice << std::endl;
        //std::cout << "MC Simulation Binary Put Price: " << mcBPutPrice << std::endl;

        double bsEUPutPrice = bs.Price(eu_put, stockPrice, rate, vol);
        //double bsBPutPrice = bs.Price(eu_b_put, stockPrice, rate, vol);
        std::cout << "Black-Scholes European Put Price: " << bsEUPutPrice << std::endl << std::endl;
        //std::cout << "Black-Scholes Binary Put Price: " << bsBPutPrice << std::endl << std::endl;
    }

    std::cout << "BINARY TREE PRICER NUMBER OF STEPS: " << step <<std::endl;

    JRBinomialTree tree_eu_call(stockPrice, rate, vol, T, step);
    EuropeanCall eu_call(K, T);
    double tree_eu_call_price = tree_eu_call.Price(eu_call);
    std::cout << "EUROPEAN CALL" << std::endl;
    std::cout << "Binary Tree Call Price: " << tree_eu_call_price << std::endl;

    JRBinomialTree tree_eu_put(stockPrice, rate, vol, T, step);
    EuropeanPut eu_put(K, T);
    double tree_eu_put_price = tree_eu_put.Price(eu_put);
    std::cout << "EUROPEAN PUT" << std::endl;
    std::cout << "Binary Tree Put Price: " << tree_eu_put_price << std::endl;

    JRBinomialTree tree_ame_call(stockPrice, rate, vol, T, step);
    AmericanCall ame_call(K, T);
    double tree_ame_call_price = tree_ame_call.Price(ame_call);
    std::cout << "AMERICAN CALL" << std::endl;
    std::cout << "Binary Tree Call Price: " << tree_ame_call_price << std::endl;

    JRBinomialTree tree_ame_put(stockPrice, rate, vol, T, step);
    EuropeanPut ame_put(K, T);
    double tree_ame_put_price = tree_ame_put.Price(ame_put);
    std::cout << "AMERICAN PUT" << std::endl;
    std::cout << "Binary Tree Put Price: " << tree_ame_put_price << std::endl;

    return 0;

};
