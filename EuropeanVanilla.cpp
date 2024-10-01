//
// Created by Sarp Nalcin on 28/02/2024.
//

#include "EuropeanVanilla.h"

EuropeanVanilla::EuropeanVanilla(double K, double T): Option(K, T) {};

double EuropeanVanilla::CalcGamma(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val);
}