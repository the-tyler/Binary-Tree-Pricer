//
// Created by Sarp Nalcin on 05/03/2024.
//

#include "JRBinomialTree.h"

JRBinomialTree::JRBinomialTree(double S0, double rate, double vol, double expiry, int steps) :
    S0_(S0),
    rate_(rate),
    vol_(vol),
    expiry_(expiry),
    steps_(steps)
{};

double JRBinomialTree::Price(const Option &Option) {

    // Create the first node with S0 and a dummy option price
    double dummy_option_price = 0.0;
    Node node0 = {S0_, dummy_option_price};
    tree_.push_back(std::vector<Node>{node0});

    // Set a tolerance level for floating point precision of option prices
    const double tolerance = 1e-9;

    // Get the dt which is a way to discretize time
    double dt = expiry_/steps_;

    // create a set to keep track of the unique prices
    std::set<double> prev_prices;

    // insert the rounded S0 to the set
    prev_prices.insert(S0_);

    // Populate the tree with stock price - Forward Propagation
    // start the iteration horizontally
    for(int i=1; i < steps_ + 1; ++i) {
        vector<Node> vec;

        // start the iteration vertically
        for (int j = 0; j < i; ++j) {
            double S_up = tree_[i - 1][j].S * pow(M_E, ((rate_ - 0.5 * vol_ * vol_) * dt + vol_ * sqrt(dt)));
            double S_down = tree_[i - 1][j].S * pow(M_E, ((rate_ - 0.5 * vol_ * vol_) * dt - vol_ * sqrt(dt)));

            // Check if S_down is in prev_prices
            bool found_down = false;
            for (double price : prev_prices) {
                if (std::abs(S_down - price) < tolerance) {
                    found_down = true;
                    break;
                }
            }
            if (!found_down) {
                // Because we will price the options in backpropagation, we create dummy prices
                Node node_down = {S_down, dummy_option_price};
                vec.push_back(node_down);
                prev_prices.insert(S_down);
            }
            // Check if S_up is in prev_prices
            bool found_up = false;
            for (double price : prev_prices) {
                if (std::abs(S_up - price) < tolerance) {
                    found_up = true;
                    break;
                }
            }
            if (!found_up) {
                // Because we will price the options in backpropagation, we create dummy prices
                Node node_up = {S_up, dummy_option_price};
                vec.push_back(node_up);
                prev_prices.insert(S_up);
            }
        }
        tree_.push_back(vec);

    // Populate tree with option prices - Backward Propagation
    // start the iteration horizontally

    for (int m = tree_.size()-1; m>=0; --m){
        for(int n = 0; n <= m; ++n)
        {
            if (m==tree_.size() -1){
                double sT = tree_[m][n].S;
                double expiration_payoff = Option.GetExpirationPayoff(sT);
                tree_[m][n].C = expiration_payoff;
            }
            else{
            double disc_opt_prc1 = tree_[m+1][n].C;
            double disc_opt_prc2 = tree_[m+1][n+1].C;
            double option_payoff = Option.GetDiscountedExpectedPayoff(disc_opt_prc2, disc_opt_prc1, rate_, dt);
            tree_[m][n].C = option_payoff;
            }
        }
    }

    }
    return tree_[0][0].C;
};