//
// Created by Sarp Nalcin on 28/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_EUROPEANVANILLA_H
#define OO_BS_OPTION_PRICER_V2_EUROPEANVANILLA_H

#include "Option.h"

class EuropeanVanilla: public Option {
public:
    EuropeanVanilla(double K, double T);
    // Because Gamma of a put and a call are equal, we override here
    double CalcGamma(double S0, double r, double v)  override;
    // Because EuropeanVanilla does not override the virtual destructor from Option, EuropeanVanilla has virtual destructor too
};

#endif //OO_BS_OPTION_PRICER_V2_EUROPEANVANILLA_H
