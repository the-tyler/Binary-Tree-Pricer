//
// Created by Sarp Nalcin on 29/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_EUROPEANBINARYPUT_H
#define OO_BS_OPTION_PRICER_V2_EUROPEANBINARYPUT_H

#include "EuropeanBinary.h"

class EuropeanBinaryPut : public EuropeanBinary{
    public:
        EuropeanBinaryPut(double K, double T);
        ~EuropeanBinaryPut() override;
        double CalcDelta(double S0, double r, double v) override;
        double CalcGamma(double S0, double r, double v) override;
        double GetExpirationPayoff(double ST) const override;
};

#endif //OO_BS_OPTION_PRICER_V2_EUROPEANBINARYPUT_H
