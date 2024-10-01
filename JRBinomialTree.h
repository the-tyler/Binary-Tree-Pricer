//
// Created by Sarp Nalcin on 05/03/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_JRBINOMIALTREE_H
#define OO_BS_OPTION_PRICER_V2_JRBINOMIALTREE_H

#include "Option.h"
#include <vector>
#include <set>

using namespace std;

struct Node {
    double S;
    double C;
};

class JRBinomialTree {
    public:
        JRBinomialTree(double S0, double rate, double vol, double expiry, int steps);
        double Price(const Option& Option);

    private:
    // Create a tree by using keyword
    using Tree = vector<vector<Node>>;
    Tree tree_;

    // Create the input arguments to build the tree
    double S0_;
    double rate_;
    double vol_;
    double expiry_;
    int steps_;
};


#endif //OO_BS_OPTION_PRICER_V2_JRBINOMIALTREE_H
