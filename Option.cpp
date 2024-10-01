//
// Created by Sarp Nalcin on 22/02/2024.
//

#include "Option.h"
#include "Normal.h"

Option::Option(double K, double T) :
        K_(K),
        T_(T)
{};

// Because this is a virtual destructor, there is no need for the line below

double Option::GetTimeToExpiration() const{

    return T_;
};

double Option::GetDiscountedExpectedPayoff(double St_up, double St_down, double r, double dt, double up_prob) const
{
    double disc_factor = pow(M_E, -r*dt);
    double discountedExpectedPayoff = ((up_prob * St_up * disc_factor) + ((1-up_prob)*(St_down * disc_factor)));
    return discountedExpectedPayoff;
};

double Option::GetStrike() const{
    return K_;
};

double Option::d1(double S0, double r, double v)
{
    return log(S0 * pow(M_E, r*T_)/K_)/(v * sqrt(T_)) + v * sqrt(T_)/2;
};

double Option::d2(double S0, double r, double v)
{
    return log(S0 * pow(M_E, r*T_)/K_)/(v * sqrt(T_)) - v * sqrt(T_)/2;

}




;


