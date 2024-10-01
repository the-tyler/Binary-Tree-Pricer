//
// Created by Sarp Nalcin on 28/02/2024.
//

#ifndef OO_BS_OPTION_PRICER_V2_MCPRICER_H
#define OO_BS_OPTION_PRICER_V2_MCPRICER_H

#include "Option.h"
#include "RandNumGen.h"
#include <vector>

class MCPricer {
    public:
        static double GenStockPrice(const Option& option, double stockPrice, double vol, double rate);
        double Price(const Option& option, double stockPrice, double vol, double rate, unsigned long paths);

    private:
        std::vector<double> prc_container;

};

#endif //OO_BS_OPTION_PRICER_V2_MCPRICER_H
