//
// Created by Sarp Nalcin on 28/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_BSPRICER_H
#define OO_BS_OPTION_PRICER_V2_BSPRICER_H

#include "Option.h"

class BSPricer {
    public:
        double Price(Option& option, double S0, double r, double v);
};

#endif //OO_BS_OPTION_PRICER_V2_BSPRICER_H
