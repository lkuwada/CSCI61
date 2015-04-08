#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>

class myString
{
public:
    // CONSTRUCTORS and DESTRUCTOR
    myString(const char str[] = "");
    myString(const myString& source);

    myString(const char c);
    // pre: none
    // post: a new string has been created containing the char c

    ~myString();

    // MEMBER METHODS
    void operator+=(const myString& addend);
    void operator+=(const char addend[]);
    void operator+=(char addend);
    void resize(size_t n);
    void operator=(const myString& source);
    size_t length() const;
    char operator[](size_t position) const;

    void insert(myString& s, int p);
    // pre: none
    // post: string s has been inserted at position p in this string

    void erase(int p1, int p2);
    // pre: p1 < p2
    // post: the portion from p1 to p2 of this string has been erased

    void replace_one(char a, char b);
    // pre:
    // post:

    void replace(int p, const myString& r);
    // pre: none
    // post: this string starting at position p has been replaced with string r

    void tokenize(const myString &s, const myString &delim, std::vector<myString> &container);


    // FRIEND METHODS
    friend std::ostream& operator<<(std::ostream& outs, const myString& source);
    friend bool operator==(const myString& s1, const myString& s2);
    friend bool operator!=(const myString& s1, const myString& s2);
    friend bool operator>=(const myString& s1, const myString& s2);
    friend bool operator<=(const myString& s1, const myString& s2);
    friend bool operator>(const myString& s1, const myString& s2);
    friend bool operator<(const myString& s1, const myString& s2);
private:
    char* sequence;
    size_t allocated;
    size_t current_length;
};


// NON-MEMBER FUNCTIONS
myString operator+(const myString& s1, const myString& s2);
std::istream& operator>>(std::istream& ins, myString& target);
void getline(std::istream& ins, myString& target);


#endif // MYSTRING_H
