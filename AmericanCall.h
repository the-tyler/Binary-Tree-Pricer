//
// Created by Sarp Nalcin on 06/03/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_AMERICANCALL_H
#define OO_BS_OPTION_PRICER_V2_AMERICANCALL_H

#include "AmericanVanilla.h"
class AmericanCall : public AmericanVanilla{
public:
    AmericanCall(double K, double T);
    ~AmericanCall() override;
    double CalcDelta(double S0, double r, double v) override;
    double GetExpirationPayoff(double ST) const override;
    double GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const override;
};

#endif //OO_BS_OPTION_PRICER_V2_AMERICANCALL_H
