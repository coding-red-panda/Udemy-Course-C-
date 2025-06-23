#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    std::string answers;
};

int calculate_score(const std::string &answers) {
    int score =  0;

    if (answers[0] == 'A') score++;
    if (answers[1] == 'B') score++;
    if (answers[2] == 'C') score++;
    if (answers[3] == 'D') score++;
    if (answers[4] == 'E') score++;

    return score;
}

double average_score(const std::vector<Student> &students) {
    double average = 0;

    for (const Student &student : students) {
        average += calculate_score(student.answers);
    }

    return average / students.size();
}

void print_header() {
    std::cout << std::setw(14) << std::left << "Students";
    std::cout << std::setw(14) << std::right << "Score" << std::endl;
    std::cout << std::setw(28) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(const std::vector<Student> &students) {
    std::cout << std::setw(28) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(14) << std::left << "Average Score:";
    std::cout << std::setw(14) << std::right << average_score(students) << std::endl;
}

void process_file(std::ifstream &input, std::vector<Student> &students) {
    while (!input.eof()) {
        std::string name {};
        std::string answers {};

        std::getline(input, name);
        std::getline(input, answers);

        students.push_back({name, answers});
    }
}

int main() {
    std::ifstream input { "../responses.txt" };
    std::vector<Student> students;
    std::string answer_key {};

    // Verify the file is opened
    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    // Read out the answer key first
    std::getline(input, answer_key);

    process_file(input, students);
    input.close();
    print_header();

    for (const auto&[name, answers] : students) {
        std::cout << std::setw(14) << std::left << name;
        std::cout << std::setw(14) << std::right << calculate_score(answers) << std::endl;
    }

    print_footer(students);

    return 0;
}
