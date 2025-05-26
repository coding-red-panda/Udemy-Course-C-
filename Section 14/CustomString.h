//
// Created by arned on 5/26/2025.
//

#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>

class CustomString {
public:
    friend std::ostream &operator<<(std::ostream &os, const CustomString &rhs);
    friend std::istream &operator>>(std::istream &in, CustomString &rhs);

private:
    char *str;

public:
    CustomString();
    CustomString(const char *s);
    CustomString(const CustomString &source);
    CustomString(CustomString &&source);
    ~CustomString();
    
    CustomString &operator=(CustomString &rhs);
    CustomString &operator=(CustomString &&rhs);
    
    void display() const;
    
    int get_length() const;
    const char *get_str() const;

    // Operator overloading
    CustomString operator-() const;
    CustomString operator+(const CustomString &rhs) const;
    bool operator==(const CustomString &rhs) const;
    bool operator!=(const CustomString &rhs) const;
    bool operator<(const CustomString &rhs) const;
    bool operator>(const CustomString &rhs) const;
    CustomString &operator+=(const CustomString &rhs);
    CustomString operator*(int n) const;
    CustomString &operator*=(int n);
    CustomString &operator++();
    CustomString operator++(int);
};

#endif //CUSTOMSTRING_H
