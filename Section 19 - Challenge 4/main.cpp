#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ofstream output { "../romeo_and_juliet.txt" };
    std::ifstream input { "../romeoandjuliet" };

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening files" << std::endl;
    }

    int line_number = 0;

    while (!input.eof()) {
        std::string line;
        std::getline(input, line);

        // We only want to number the lines that actually have text.
        // Empty lines will be copies as is
        if (!line.empty()) {
            line_number++;
            output << std::setw(6) << std::left << line_number << " " << line << std::endl;
        } else {
            output << line << std::endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
