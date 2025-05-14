#include <iostream>

using namespace std;

int main() {
    constexpr double price_for_small_room { 25.0 };
    constexpr double price_for_large_room { 35.0 };
    constexpr double tax_rate { 0.06 };
    constexpr int estimate_duration { 30 };

    unsigned short number_of_small_rooms {0};
    unsigned short number_of_large_rooms {0};

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl << endl;
    cout << "How many small rooms would like cleaned? ";
    cin >> number_of_small_rooms;
    cout << "How many large rooms would like cleaned? ";
    cin >> number_of_large_rooms;

    const double cost {(number_of_small_rooms * price_for_small_room) + (number_of_large_rooms * price_for_large_room)};
    const double tax {(cost * tax_rate)};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_for_small_room << endl;
    cout << "Price per large room: $" << price_for_large_room << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "====================================" << endl;
    cout << "Total estimate: $" << cost + tax << endl;
    cout << "This estimate is valid for " << estimate_duration << " days" << endl;

    return 0;
}
