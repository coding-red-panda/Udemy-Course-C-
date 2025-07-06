#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

// Function to check if a string is a palindrome
// Uses a stack to track string in reverse, thanks to the FILO Last In First Out (LIFO) nature.
// Uses a queue to track the string in the original order, thanks to the FIFO First In First Out nature.
// We basically use the stack to reverse the string and the queue to keep the original order,
// then we compare the two to see if they are the same.
bool is_palindrome(const std::string& s)
{
    std::stack<char> stack;
    std::queue<char> queue;

    for (char c : s) {
        if (std::isalnum(c)) {
            char upper_c = std::toupper(c);

            stack.push(upper_c);
            queue.push(upper_c);
        }
    }

    while (!stack.empty() && !queue.empty()) {
        if (stack.top() != queue.front()) {
            return false;
        }

        stack.pop();
        queue.pop();
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
