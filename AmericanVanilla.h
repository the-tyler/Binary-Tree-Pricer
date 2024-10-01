//
// Created by Sarp Nalcin on 06/03/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_AMERICANVANILLA_H
#define OO_BS_OPTION_PRICER_V2_AMERICANVANILLA_H

#include "Option.h"
class AmericanVanilla : public Option{

    public:
        AmericanVanilla(double K, double T);
        double CalcGamma(double S0, double r, double v)  override;
};


#endif //OO_BS_OPTION_PRICER_V2_AMERICANVANILLA_H
