//
// Created by Sarp Nalcin on 22/02/2024.
//

#include "Normal.h"

double Normal::cdf(double x)
{
    return 0.5 * (1 + erf(x / sqrt(2)));
};


double Normal::pdf(double x)
{
    return exp(-0.5 * pow(x,2)) / sqrt(2 * std::numbers::pi);
}
