# Section 20
## Challenge 3 - Using std::set and std::map

This challenge has 2 parts.
We will be reading words from a text file provided to you.
The text file is named 'words.txt' and contains the fist few
paragraphs from the book, "The Wonderful Wizard of Oz", by 
L. Frank Baum.

### Part 1:

For part 1 of this challenge, you are to display each unique word
in the file and immediately following each word display the number
of time it occurs in the text file.

The words should be displayed in ascending order.

Here is a sample listing of the first few words:

```
Word         Count
===================
Aunt              5
Dorothy           8
Dorothy's         1
Em                5
Even              1
From              1
```

Please use a map with <string, int> Key/ Value pairs

### Part 2:

For part 2 of this challenge, you are to display each unique word
in the file and immediately following each word display the line numbers
in which that word appears.

The words should be displayed in ascending order and the line numbers for
each word should also be displayed in ascending order.
If a word appears more than once on a line then the line number should
only appear once.

Here is a sample listing of the first few words:

```
Word             Occurrences
============================
Aunt            [ 2 7 25 29 48 ]
Dorothy         [ 1 7 15 29 39 43 47 51 ]
Dorothy's       [ 31 ]
Em              [ 2 7 25 30 48 ]
Even            [ 19 ]
From            [ 50 ]
```

Please use a map of <string,set<int>> Key/Value pairs

Hint: consider using `stringstream` to process words
once you read in a line from the file.

Note: I have provided the basic shell for your program.
I have also provided the functions that display the maps
as well as the function that cleans the words read.
You should call the `clean_string` function for every word 
you read from the file.

Good luck and have fun!!!
Don't over think this one -- use the STL!
