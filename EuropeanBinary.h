//
// Created by Sarp Nalcin on 28/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_EUROPEANBINARY_H
#define OO_BS_OPTION_PRICER_V2_EUROPEANBINARY_H

#include "Option.h"

class EuropeanBinary : public Option {
public:
    EuropeanBinary(double K, double T);
    // Because EuropeanBinary does not override the virtual destructor from Option, EuropeanBinary has virtual destructor too

};


#endif //OO_BS_OPTION_PRICER_V2_EUROPEANBINARY_H
