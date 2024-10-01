cmake_minimum_required(VERSION 3.27)
project(oo_bs_option_pricer_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(oo_bs_option_pricer_v2 main.cpp
        Option.cpp
        Option.h
        Normal.cpp
        Normal.h
        EuropeanCall.cpp
        EuropeanCall.h
        EuropeanPut.cpp
        EuropeanPut.h
        EuropeanVanilla.cpp
        EuropeanVanilla.h
        MCPricer.cpp
        MCPricer.h
        BSPricer.cpp
        BSPricer.h
        EuropeanBinary.cpp
        EuropeanBinary.h
        RandNumGen.cpp
        RandNumGen.h
        EuropeanBinaryCall.cpp
        EuropeanBinaryCall.h
        EuropeanBinaryPut.cpp
        EuropeanBinaryPut.h
        JRBinomialTree.cpp
        JRBinomialTree.h
        AmericanVanilla.cpp
        AmericanVanilla.h
        AmericanCall.cpp
        AmericanCall.h
        AmericanPut.cpp
        AmericanPut.h
)
