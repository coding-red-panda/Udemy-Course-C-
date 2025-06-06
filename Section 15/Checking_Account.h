//
// Created by arned on 5/28/2025.
//

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class Checking_Account : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);

private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;

public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
};

#endif //CHECKINGACCOUNT_H
