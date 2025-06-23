#include <algorithm>
#include <iostream>
#include <fstream>

void to_lower_case(std::string &s) {
    std::ranges::transform(s, s.begin(), ::tolower);
}

int main() {
    std::ifstream input { "../romeo_and_juliet.txt" };
    std::string substring {};
    std::string buffer;
    int word_counter = 0;
    int match_counter = 0;

    if (!input.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return -1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> substring;

    // Convert the substring to lowercase
    to_lower_case(substring);

    // Abuse the >> operator to read out a string from the file.
    // This should always read a single word.
    while (input >> buffer) {
        ++word_counter; // read a word

        // Cast the buffer to lowercase
        to_lower_case(buffer);

        // Check if the buffer contains our word.
        if (buffer.find(substring) != std::string::npos) {
            ++match_counter;
        }
    }

    std::cout << word_counter << " words were searched..." << std::endl;
    std::cout << "The substring " << substring << " was found " << match_counter << " times" << std::endl;

    input.close();
    return 0;
}
