#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings
    vector<Savings_Account> savings_accounts;
    savings_accounts.push_back(Savings_Account {});
    savings_accounts.push_back(Savings_Account {"Superman"});
    savings_accounts.push_back(Savings_Account {"Batman", 2000});
    savings_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});

    display(savings_accounts);
    deposit(savings_accounts, 1000);
    withdraw(savings_accounts, 2000);

    // Checking
    vector<Checking_Account> checkings_accounts;
    checkings_accounts.push_back(Checking_Account {});
    checkings_accounts.push_back(Checking_Account {"Kirk"});
    checkings_accounts.push_back(Checking_Account {"Spock", 2000});
    checkings_accounts.push_back(Checking_Account {"Scotty", 5000});

    display(checkings_accounts);
    deposit(checkings_accounts, 1000);
    withdraw(checkings_accounts, 2000);

    // Trust Accounts
    vector<Trust_Account> trusts_accounts;
    trusts_accounts.push_back(Trust_Account {});
    trusts_accounts.push_back(Trust_Account {"Athos", 10000, 5.0});
    trusts_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0});
    trusts_accounts.push_back(Trust_Account {"Aramis", 30000, 5.0});

    display(trusts_accounts);
    deposit(trusts_accounts, 1000);
    withdraw(trusts_accounts, 2000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawal is > 20% of the balance
    for (int i = 1; i <= 5; i++) {
        withdraw(trusts_accounts, 1000);
    }

    return 0;
}
