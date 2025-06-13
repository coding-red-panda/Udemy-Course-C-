#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
    // test your code here
    Checking_Account *account = new Checking_Account { "John Doe", 10000 };

    account->print(cout);
    account->withdraw(100);
    account->deposit(100);

    try {
        account->print(cout);
        account->withdraw(100000);
    } catch (InsufficientFundsException &e) {
        cout << e.what() << endl;
    }

    delete account;


    try {
        new Savings_Account { "John Doe", -10 };
    } catch (IllegalBalanceException &ex) {
      cout << ex.what() << endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

