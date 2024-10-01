//
// Created by Sarp Nalcin on 22/02/2024.
//

#include "EuropeanPut.h"

EuropeanPut::EuropeanPut(double K, double T) : EuropeanVanilla(K, T) {};

EuropeanPut::~EuropeanPut() = default;

double EuropeanPut::CalcDelta(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val) - 1;

};

double EuropeanPut::GetExpirationPayoff(double ST) const {

    double strike = GetStrike();

    if (strike > ST){
        return strike-ST;
    }
    else{
        return 0;
    }
};

double EuropeanPut::GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const {

    if (discountedExpectedPayoff > ST){
        return discountedExpectedPayoff-ST;
    }
    else{
        return 0;
    }

};
