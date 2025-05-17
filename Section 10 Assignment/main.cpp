/*
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.
Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:
It's much easier to understand the Letter Pyramid given examples.
If the user enters the string "ABC", then your program should display:

      A
     ABA
    ABCBA

If the user enters the string, "12345", then your program should display:

        1
       121
      12321
     1234321
    123454321

If the user enters 'ABCDEFG', then your program should display:

          A
         ABA
        ABCBA
       ABCDCBA
      ABCDEDCBA
     ABCDEFEDCBA
    ABCDEFGFEDCBA

If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:

                             A
                            ABA
                           ABCBA
                          ABCDCBA
                         ABCDEDCBA
                        ABCDEFEDCBA
                       ABCDEFGFEDCBA
                      ABCDEFGHGFEDCBA
                     ABCDEFGHIHGFEDCBA
                    ABCDEFGHIJIHGFEDCBA
                   ABCDEFGHIJKJIHGFEDCBA
                  ABCDEFGHIJKLKJIHGFEDCBA
                 ABCDEFGHIJKLMLKJIHGFEDCBA
                ABCDEFGHIJKLMNMLKJIHGFEDCBA
               ABCDEFGHIJKLMNONMLKJIHGFEDCBA
              ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
             ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
            ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
           ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA

If the user enters "C++isFun!", then your program should display:

            C
           C+C
          C+++C
         C++i++C
        C++isi++C
       C++isFsi++C
      C++isFuFsi++C
     C++isFunuFsi++C
    C++isFun!nuFsi++C


Think about the problem before you begin and break it down into steps.

This can be a very challenging problem to solve!

*****  Don't forget to paste your code solution when you submit.******
*****  Also, submit it so your peers can see it and possibly comment. ******

Have fun!
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
 string message;
 cout << "Enter a string: ";
 getline(cin, message);
 cout << endl;

 // The length of the message is the amount of rows we need to display,
 // as we start with one character up to the entire word,
 // incrementing one character at a time.
 for (size_t row = 0; row < message.length(); row++) {
  // The display is the entire line of whitespace, twice the word we want to display.
  string display (message.length() * 2, ' ');

  // The left half is the message entered, and the row representing how many characters to display.
  string left_half = message.substr(0, row + 1);

  // The right half is the same as the left half, just one character less as we already have the
  // starting character as the last character of the left half.
  string right_half {left_half, 0, left_half.length() - 1};

  // Reverse the right half, because we need to display it in reverse.
  reverse(right_half.begin(), right_half.end());

  // Copy the left half into the display string:
  // Start from the center (length / 2) and subtract the length of the left half to find the position.
  // Then just use the left-half length and value to copy it in.
  display.replace(display.length() / 2 - left_half.length(), left_half.length(), left_half);

  // Repeat the same for the right half, except we just start at the center and overwrite
  // the whitespace with the right-half value.
  display.replace(display.length() / 2, right_half.length(), right_half);

  // Display the value.
  cout << display << endl;
 }
}
