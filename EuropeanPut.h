
//
// Created by Sarp Nalcin on 22/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V1_EUROPEANPUT_H
#define OO_BS_OPTION_PRICER_V1_EUROPEANPUT_H

#include "EuropeanVanilla.h"

class EuropeanPut : public EuropeanVanilla{
public:
    EuropeanPut(double K, double T);
    ~EuropeanPut() override;
    double CalcDelta(double S0, double r, double v) override;
    double GetExpirationPayoff(double ST) const override;
    double GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const override;

};
#endif //OO_BS_OPTION_PRICER_V1_EUROPEANPUT_H
