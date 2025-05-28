cmake_minimum_required(VERSION 3.31)
project(Section_15)

set(CMAKE_CXX_STANDARD 20)

add_executable(Section_15
        Account.h
        Account.cpp
        Account_Util.h
        Account_Util.cpp
        Savings_Account.h
        Savings_Account.cpp
        Checking_Account.cpp
        Checking_Account.h
        main.cpp
        Trust_Account.cpp
        Trust_Account.h)
