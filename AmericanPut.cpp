//
// Created by Sarp Nalcin on 06/03/2024.
//

#include "AmericanPut.h"

AmericanPut::AmericanPut(double K, double T) : AmericanVanilla(K, T) {};

AmericanPut::~AmericanPut() = default;

double AmericanPut::CalcDelta(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val);

};

double AmericanPut::GetExpirationPayoff(double ST) const{

    double strike = GetStrike();

    if (ST > strike){
        return ST - strike;
    }
    else{
        return 0;
    }

};

double AmericanPut::GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const {

    double immediatePayoff = std::max(0.0, discountedExpectedPayoff - ST);
    double earlyExercisePayoff = std::max(0.0, K_ - ST);
    return std::max(immediatePayoff, earlyExercisePayoff);
};