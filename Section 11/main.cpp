#include <iostream>
#include <vector>

/*
Recall the challenge from Section 9.
Your challenge for section 11 is to modularize your solution to the Section 9
challenge by refactoring your solution so that it uses functions.

You decide how to modularize the program.

Here are a few hints:
    - Create functions for each major function
    - Keep the functions small
    - Remember the Boss/Worker analogy
    - Keep the vector declaration in the main function and pass the vector object
      to any function that requires it

DO NOT move the vector object outside main and make it a global variable.
*/

void print_selection_menu();
void ask_and_add_number(std::vector<int>& numbers);
void calculate_mean(const std::vector<int>& numbers);
void find_smallest_number(const std::vector<int>& numbers);
void find_largest_number(const std::vector<int>& numbers);
void print_list(const std::vector<int>& numbers);

int main() {
    char selection;
    bool quit {false};
    std::vector<int> numbers;

    do {
        print_selection_menu();
        std::cin >> selection;

        switch (selection) {
            case 'a':
            case 'A':
                ask_and_add_number(numbers);
                break;
            case 'm':
            case 'M':
                calculate_mean(numbers);
                break;
            case 's':
            case 'S':
                find_smallest_number(numbers);
                break;
            case 'l':
            case 'L':
                find_largest_number(numbers);
                break;
            case 'p':
            case 'P':
                print_list(numbers);
                break;
            case 'q':
            case 'Q':
                quit = true;
                break;
            default: std::cout << std::endl << "Unknown selection, please try again" << std::endl;
        }
    } while (!quit);
}

void print_selection_menu() {
    std::cout << "Enter your selection: " << std::endl;
    std::cout << "P - Print numbers" << std::endl;
    std::cout << "A - Add number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "Q - Quit" << std::endl;
    std::cout << std::endl << "Enter your choice: ";
}

void ask_and_add_number(std::vector<int>& numbers) {
    int input;

    std::cout << "Enter number: ";
    std::cin >> input;

    numbers.push_back(input);

    std::cout << std::endl << input << " added" << std::endl;
}

void calculate_mean(const std::vector<int>& numbers) {
    if (numbers.empty())
        std::cout << "Unable to calculate the mean - no data" << std::endl;
    else {
        int sum {0};

        for (auto const i : numbers) sum += i;

        std::cout << "Mean value: " << (sum / static_cast<double>(numbers.size())) << std::endl;
    }
}

void find_smallest_number(const std::vector<int> &numbers) {
    if (numbers.empty())
        std::cout << "Unable to calculate the smallest number" << std::endl;
    else {
        int smallest = numbers.at(0);

        for (auto const i : numbers)
            if (smallest > i) smallest = i;

        std::cout << "The smallest number is: " << smallest << std::endl;
    }
}

void find_largest_number(const std::vector<int> &numbers) {
    if (numbers.empty())
        std::cout << "Unable to calculate the smallest number" << std::endl;
    else {
        int largest = numbers.at(0);

        for (auto const i : numbers)
            if (largest < i) largest = i;

        std::cout << "The largest number is: " << largest << std::endl;
    }
}

void print_list(const std::vector<int> &numbers) {
    std::cout << "Numbers currently in the list: ";

    for (auto const x: numbers)
        std::cout << x << " ";

    std::cout << std::endl;
}
