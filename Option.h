//
// Created by Sarp Nalcin on 22/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V1_OPTION_H
#define OO_BS_OPTION_PRICER_V1_OPTION_H

#include "Normal.h"
#include <iostream>

class Option{
public:
    // parametrized constructor
    Option(double K, double T);
    // destructor - you could also write virtual ~Option() = default; which is the same as long as there is no implementation
    virtual ~Option() = default;

    // pure virtual functions need = 0 but only virtual function without 0 need default implementation in the .cpp
    virtual double CalcDelta(double S0, double r, double v) = 0;
    virtual double CalcGamma(double S0, double r, double v) = 0;
    virtual double GetExpirationPayoff(double ST) const = 0;
    virtual double GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const = 0;

    double GetDiscountedExpectedPayoff(double St_up, double St_down, double r, double dt, double up_prob=0.5) const;
    double GetTimeToExpiration() const;
    double GetStrike() const;

// For BSPricer to use d1 and d2, I changed them from protected to public
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);

protected:
    double K_;
    double T_;
};

#endif //OO_BS_OPTION_PRICER_V1_OPTION_H
