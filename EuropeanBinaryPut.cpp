//
// Created by Sarp Nalcin on 29/02/2024.
//

#include "EuropeanBinaryPut.h"

EuropeanBinaryPut::EuropeanBinaryPut(double K, double T) : EuropeanBinary(K, T) {};

EuropeanBinaryPut::~EuropeanBinaryPut() = default;

double EuropeanBinaryPut::CalcDelta(double S0, double r, double v) {
    double d2_val = d2(S0, r, v);
    return (pow(M_E, -r * T_) * Normal::pdf(-d2_val)) / (S0 * v * sqrt(T_));
};

double EuropeanBinaryPut::CalcGamma(double S0, double r, double v) {
    double d2_val = d2(S0, r, v);
    return (pow(M_E, -r * T_) * Normal::pdf(-d2_val)) / (S0 * v * v * sqrt(T_));
};

double EuropeanBinaryPut::GetExpirationPayoff(double ST) const {

    if (ST < K_)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
