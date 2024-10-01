//
// Created by Sarp Nalcin on 28/02/2024.
//

#include "RandNumGen.h"

const double PI = std::numbers::pi;

RandNumGen::RandNumGen() {};

double RandNumGen::BoxMuller()
{
    double x = static_cast<double>(rand()) / RAND_MAX;
    double y = static_cast<double>(rand()) / RAND_MAX;

    // Check for the condition since x cannot be zero!
    if (x==0){
        double temp = x;
        x = y;
        y = temp;
    }
    double z = sqrt(-2.0*log(x)) * cos(2*PI*y);
    return z;
};



