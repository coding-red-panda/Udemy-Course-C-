#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> d;

    // We only care about the string alphanumeric characters.
    // To handle all cases, we will push each character to the back of the deque,
    // in upper-case
    for (char c : s)
        if (std::isalpha(c))
            d.push_back(std::toupper(c));

    // Two place-holders to check the chars to compare.
    // No need for init.
    char c1{};
    char c2{};

    // We're going to be taking a character from each side of the deque and compare them.
    // So this means we need to have more than 1 char left in the collection (account for unevent words).
    // If the chars do not match, we can immediately return false, otherwise keep going to the end.
    while (d.size() > 1) {
        c1 = d.front();
        c2 = d.back();

        d.pop_front();
        d.pop_back();

        if (c1 != c2)
            return false;
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}