#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

class mystring
{
public:
    mystring(const char c[] = "");
    //pre: none
    //post: construct char array

    mystring(const char c);
    //pre: none
    //post: construct char

    size_t length() const;
    //pre: none
    //post: returns length of string

    void insert(const char c[], size_t pos);            //pos is defined by looking at string not array
    //pre: none
    //post: string is inserted at position pos

    void erase(size_t pos1, size_t pos2);               //pos is defined by looking at string not array
    //pre: pos1 is smaller than pos2
    //post: string between pos1 and pos2 is erased

    void replace(const char a, const char b);
    //pre: none
    //post: all occurences of a will be replaced by b

    void replace_string(size_t pos1, size_t pos2, const char a[]);
    //pre: none
    //post: string a will be replaced with string b

    size_t locate_char(const char a);                    //position of character is according to string
                                                         //not array
    //pre: none
    //post: location of char will be returned

    size_t search_char(const char a);
    //pre: none
    //post: number of char will be returned

    size_t search_string(const char a[]);
    //pre: none
    //post: number of string will be returned

    void tokenize(const mystring& s, const mystring& delim, std::vector<mystring> &container);


    friend std::ostream & operator << (std::ostream & os, const mystring & s);

private:
    char* character;
    size_t allocated;
    size_t current_length;
};

#endif // MYSTRING_H
