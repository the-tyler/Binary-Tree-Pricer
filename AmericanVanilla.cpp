//
// Created by Sarp Nalcin on 06/03/2024.
//

#include "AmericanVanilla.h"

AmericanVanilla::AmericanVanilla(double K, double T): Option(K,T) {};

double AmericanVanilla::CalcGamma(double S0, double r, double v) {
    double d1_val = d1(S0, r, v);
    return Normal::cdf(d1_val);
}