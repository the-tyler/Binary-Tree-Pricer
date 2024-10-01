//
// Created by Sarp Nalcin on 22/02/2024.
//

#include "EuropeanCall.h"

EuropeanCall::EuropeanCall(double K, double T) : EuropeanVanilla(K, T) {};

EuropeanCall::~EuropeanCall() = default;

double EuropeanCall::CalcDelta(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val);

};

double EuropeanCall::GetExpirationPayoff(double ST) const{

    double strike = GetStrike();

    if (ST > strike){
        return ST - strike;
    }
    else{
        return 0;
    }

};

double EuropeanCall::GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const {

    if (ST > discountedExpectedPayoff){
        return ST - discountedExpectedPayoff;
    }
    else{
        return 0;
    }

};



