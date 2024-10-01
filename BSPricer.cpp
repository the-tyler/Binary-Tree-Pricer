//
// Created by Sarp Nalcin on 28/02/2024.
//

#include "BSPricer.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "EuropeanBinaryCall.h"
#include "EuropeanBinaryPut.h"

double BSPricer::Price(Option &option, double S0, double r, double v) {

    double d1_val = option.d1(S0, r, v);
    double d2_val = option.d2(S0, r, v);

    double K = option.GetStrike();
    double T = option.GetTimeToExpiration();

    // The dynamic_cast attempts to perform a runtime check to determine if the object pointed to by &option is of type EuropeanCall
    // or a class derived from EuropeanCall. If the object is indeed of type EuropeanCall or a derived class,
    // the dynamic_cast returns a pointer to that object. If the object is not of type EuropeanCall or a derived class,
    // the dynamic_cast returns a null pointer (nullptr)

    if(dynamic_cast<EuropeanCall*>(&option) != nullptr)
    {

        double price = S0 * Normal::cdf(d1_val) - K * pow(M_E, -r * T) * Normal::cdf(d2_val);
        return price;
    }
    else if(dynamic_cast<EuropeanPut*>(&option) != nullptr)
    {
        double price = -S0 * Normal::cdf(-d1_val) + K * pow(M_E, -r * T) * Normal::cdf(-d2_val);
        return price;
    }
    else if(dynamic_cast<EuropeanBinaryCall*>(&option) != nullptr)
    {
        double price = pow(M_E, -r * T) * Normal::cdf(d2_val);
        return price;
    }
    else if(dynamic_cast<EuropeanBinaryPut*>(&option) != nullptr)
    {
        double price = pow(M_E, -r * T) * Normal::cdf(-d2_val);
        return price;
    }
    else{
        std::cout << "Unsupported option type" << std::endl;
        return 0;
    }
};