# Section 20
## Challenge 4 - Stack and Queue Challenge

A Palindrome is a string that reads the same backwards or forwards.
Simple examples are:
`madam`
`bob`
`toot`
`radar`

An entire phrase can also be a palindome, for example:
* A Toyota's a toyota
* A Santa at NASA
* A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

For the purposes of this assignment we will only consider alpha characters and omit all other characters.
We will also not be considering case.

So,
A Santa at Nasa, will be processed as:
`ASANTAATNASA`

A common method to solve this problem is to compare the string to its reverse and
if the are equal then it must be a palindrome. But we will use a deque.

I am providing the main driver for you which will automatically run several test cases.
You challenge is to write the following function:

`bool is_palindrome(const std::string &s) {`

This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not.

So,

`is_palindrome("A Santa at Nasa");`   will return true 
`is_palindrome("Hello");`   will return false

Please use a stack and a queue to solve the problem.

If you need a hint, please as in the Q/A.
Good luck and have fun!
