//
// Created by arned on 5/26/2025.
//
#include <iostream>
#include <cstring>
#include "CustomString.h"

 // No-args constructor
CustomString::CustomString()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
CustomString::CustomString(const char *s)
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
CustomString::CustomString(const CustomString &source)
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
}

// Move constructor
CustomString::CustomString(CustomString &&source)
    :str(source.str) {
        source.str = nullptr;
}

// Destructor
CustomString::~CustomString() {
    delete [] str;
}

// Copy assignment
CustomString &CustomString::operator=(CustomString &rhs) {
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
CustomString &CustomString::operator=(CustomString &&rhs) {
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void CustomString::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int CustomString::get_length() const { return strlen(str); }
 const char *CustomString::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const CustomString &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, CustomString &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = CustomString {buff};
    delete [] buff;
    return in;
}


// Equality
bool CustomString::operator==(const CustomString &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Not equals
bool CustomString::operator!=(const CustomString &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

// Less than
bool CustomString::operator<(const CustomString &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

// Greater than
bool CustomString::operator>(const CustomString &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

// Make lowercase
CustomString CustomString::operator-() const {
    char *buff= new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    CustomString temp {buff};
    delete [] buff;
    return temp;
}

// Concatentate
CustomString CustomString::operator+(const CustomString &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    CustomString temp {buff};
    delete [] buff;
    return temp;
}

// Concat and assign
CustomString &CustomString::operator+=(const CustomString &rhs)  {
    *this = *this + rhs;
    return *this;
}

// repeat
CustomString CustomString::operator*(const int n) const {
    CustomString temp;
    for (int i=1; i<= n; i++)
        temp = temp + *this;
    return temp;
}

// repeat and assign
CustomString &CustomString::operator*=(int n) {
    *this = *this * n;
    return *this;
}

// Pre-increment - make the string upper-case
CustomString &CustomString::operator++()   {  // pre-increment
    for (size_t i=0; i<std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
   return *this;
}

//Post-increment - make the string upper-case
CustomString CustomString::operator++(int) { // post-increment
   CustomString temp (*this);       // make a copy
   operator++();                    // call pre-increment - make sure you call preincrement!
   return temp;                     // return the old value
}
