// Section 8 Challenge
#include <iostream>

using namespace std;

/*
    For this program we will use US dollars and cents.

    Write a program that asks the user to enter the following:
    An integer representing the number of cents.

    You may assume that the number of cents entered is greater than or equal to zero.
    The program should the display how to provide that change to the user.

    In the US:
        1 dollar is 100 cents
        1 quarter is 25 cents
        1 dime is 10 cents
        1 nickel is 5 cents, and
        1 penny is 1 cent

    Here is a sample run:

    Enter an amount in cents : 92

    You can provide this change as follows:
    dollars: 0
    quarters: 3
    dimes: 1
    nickles: 1
    pennies: 2
 */
int main() {
    int number_of_cents {0};
    int remainder {0};

    cout << "Enter an amount in cents: ";
    cin >> number_of_cents;

    cout << endl << "You can provide this change as follows:" << endl;
    cout << "dollars: " << number_of_cents / 100 << endl;
    remainder = number_of_cents % 100;
    cout << "quarters: " << remainder / 25 << endl;
    remainder = remainder % 25;
    cout << "dimes: " << remainder / 10 << endl;
    remainder = remainder % 10;
    cout << "nickles: " << remainder / 5 << endl;
    remainder = remainder % 5;
    cout << "pennies: " << remainder << endl;

    return 0;
}
