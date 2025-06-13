//
// Created by arned on 6/13/2025.
//

#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H
#include <exception>

class InsufficientFundsException : public std::exception {
public:
    InsufficientFundsException() {};
    ~InsufficientFundsException() {};

    virtual const char* what() noexcept { return "Insufficient funds to perfom operation."; }
};

#endif //INSUFFICIENTFUNDSEXCEPTION_H
