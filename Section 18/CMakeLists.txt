cmake_minimum_required(VERSION 3.31)
project(Section_18)

set(CMAKE_CXX_STANDARD 20)

add_executable(Section_18
        InsufficientFundsException.h
        IllegalBalanceException.h
        I_Printable.h
        I_Printable.cpp
        Account.h
        Account.cpp
        Checking_Account.h
        Checking_Account.cpp
        Savings_Account.h
        Savings_Account.cpp
        Trust_Account.h
        Trust_Account.cpp
        Account_Util.h
        Account_Util.cpp
        main.cpp)
