#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account final : public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual ~Checking_Account() = default;

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream &os) const override;
};

#endif // _CHECKING_ACCOUNT_H_
