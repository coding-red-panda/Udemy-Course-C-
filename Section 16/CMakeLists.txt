cmake_minimum_required(VERSION 3.31)
project(Section_16)

set(CMAKE_CXX_STANDARD 20)

add_executable(Section_16
        I_Printable.cpp
        I_Printable.h
        Account.h
        Account.cpp
        Account_Util.h
        Account_Util.cpp
        Checking_Account.h
        Checking_Account.cpp
        Savings_Account.h
        Savings_Account.cpp
        Trust_Account.h
        Trust_Account.cpp
        main.cpp)
