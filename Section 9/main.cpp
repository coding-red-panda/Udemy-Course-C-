#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    char selection;
    bool quit {false};
    vector<int> numbers;
    int input;

    do {
        cout << "Enter your selection: " << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> selection;

        switch (selection) {
            case 'a':
            case 'A':
                cout << "Enter number: ";
                cin >> input;
                numbers.push_back(input);
                cout << endl << input << " added" << endl;
                break;
            case 'm':
            case 'M':
                if (numbers.empty()) cout << "Unable to calculate the mean - no data" << endl;
                else {
                    int sum {0};
                    for (auto const i : numbers) sum += i;
                    cout << "Mean value: " << (sum / static_cast<double>(numbers.size())) << endl;
                }
                break;
            case 's':
            case 'S':
                if (numbers.empty()) cout << "Unable to calculate the smallest number" << endl;
                else {
                    int smallest = numbers.at(0);
                    for (auto const i : numbers)
                        if (smallest > i) smallest = i;
                    cout << "The smallest number is: " << smallest << endl;
                }
                break;
            case 'l':
            case 'L':
                if (numbers.empty()) cout << "Unable to calculate the smallest number" << endl;
                else {
                    int largest = numbers.at(0);
                    for (auto const i : numbers)
                        if (largest < i) largest = i;
                    cout << "The largest number is: " << largest << endl;
                }
                break;
            case 'p':
            case 'P':
                cout << "Numbers currently in the list: ";
                for (auto const x: numbers) cout << x << " ";
                cout << endl;
                break;
            case 'q':
            case 'Q':
                quit = true;
                break;
            default: cout << endl << "Unknown selection, please try again" << endl;
        }
    } while (!quit);
}
