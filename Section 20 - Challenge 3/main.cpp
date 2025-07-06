#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>
void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (const auto& pair: words)
        std::cout << std::setw(12) << std::left << pair.first 
                  << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurrences from the
// std::map<std::string, std::set<int>>
void display_words(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"<< "Occurrences" << std::endl;
    std::cout << "=====================================================================" << std::endl;

    for (const auto& pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                  << std::left << "[ ";

        for (auto i: pair.second)
            std::cout << i << " ";

        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;

    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        result += c;
    }

    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file
void part1() {
    if (std::ifstream in_file {"../words.txt"}) {
        std::map<std::string, int> words;
        std::string word;
        std::string line;

        // Read each line from the file, getline will keep reading a line
        // until we reach the end of the file.
        while (std::getline(in_file, line)) {
            // Initialize a string stream with the line
            std::stringstream ss(line);

            // Loop over each word in the line.
            // Clean in, and add it to the map so we can count it.
            while (ss >> word) {
                word = clean_string(word);

                // This works because of the initialization logic for the map.
                // If the word is not in the map, it will be added with a count of 0,
                // since 0 is the default value for int in a map.
                words[word]++;
            }
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;

    if (std::ifstream in_file {"../words.txt"}) {
        std::string word;
        std::string line;
        int line_number = 0;

        while (std::getline(in_file, line)) {
            ++line_number;
            std::stringstream ss(line);

            while (ss >> word) {
                word = clean_string(word);

                // Again, this works because of the initialization logic for the map.
                // If the word is not in the map, it will be added with an empty set.
                words[word].insert(line_number);
            }
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();

    return 0;
}
