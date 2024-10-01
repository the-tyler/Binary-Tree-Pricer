//
// Created by Sarp Nalcin on 28/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_RANDNUMGEN_H
#define OO_BS_OPTION_PRICER_V2_RANDNUMGEN_H

#include <cstdlib>
#include <numbers>
#include <cmath>
#include <ctime>

class RandNumGen {
public:
    RandNumGen();
    static double BoxMuller();
};

#endif //OO_BS_OPTION_PRICER_V2_RANDNUMGEN_H
