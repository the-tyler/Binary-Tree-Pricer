//
// Created by Sarp Nalcin on 06/03/2024.
//

#include "AmericanCall.h"

AmericanCall::AmericanCall(double K, double T) : AmericanVanilla(K, T) {};

AmericanCall::~AmericanCall() = default;

double AmericanCall::CalcDelta(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val);

};

double AmericanCall::GetExpirationPayoff(double ST) const{

    double strike = GetStrike();

    if (ST > strike){
        return ST - strike;
    }
    else{
        return 0;
    }

};

double AmericanCall::GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const {

    double immediatePayoff = std::max(0.0, ST - discountedExpectedPayoff);
    double earlyExercisePayoff = std::max(0.0, ST - K_);
    return std::max(immediatePayoff, earlyExercisePayoff);

};

