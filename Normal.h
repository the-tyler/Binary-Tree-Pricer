//
// Created by Sarp Nalcin on 22/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_NORMAL_H
#define OO_BS_OPTION_PRICER_V2_NORMAL_H

#include <cmath>
#include <numbers>

class Normal {
public:
    static double cdf(double x);
    static double pdf(double x);
};

#endif //OO_BS_OPTION_PRICER_V2_NORMAL_H
