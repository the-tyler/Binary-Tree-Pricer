//
// Created by Sarp Nalcin on 22/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V1_EUROPEANCALL_H
#define OO_BS_OPTION_PRICER_V1_EUROPEANCALL_H

#include "EuropeanVanilla.h"

class EuropeanCall : public EuropeanVanilla{
    public:
        EuropeanCall(double K, double T);
        ~EuropeanCall() override;
        double CalcDelta(double S0, double r, double v) override;
        double GetExpirationPayoff(double ST) const override;
        double GetIntermediatePayoff(double ST, double discountedExpectedPayoff) const override;

};
#endif //OO_BS_OPTION_PRICER_V1_EUROPEANCALL_H
