#include "mystring.h"
#include <cstring>
#include <string>
#include <cassert>


myString::myString(const char str[])
{
    size_t need = strlen(str) + 1; // Required length of array to hold str
    sequence = new char[need];
    strcpy(sequence, str);
    allocated = need;
    current_length = need - 1;
}

myString::myString(const myString& source)
{
    sequence = new char[source.allocated];
    strcpy(sequence, source.sequence);
    allocated = source.allocated;
    current_length = source.current_length;
}

//myString::myString(const char c)
//{
//    sequence = new char[2];
//    strcpy(sequence, c);
//    allocated = 2;
//    current_length = 1;
//}

myString::~myString()
{
    delete[] sequence;
    sequence = 0;
    allocated = 0;
    current_length = 0;
}

void myString::operator+=(const myString& addend)
{
    resize(current_length + addend.current_length);
    strcat(sequence, addend.sequence);
    current_length += addend.current_length;
}

void myString::operator+=(const char addend[])
{
    size_t addend_length = strlen(addend); // Length of the addend
    resize(current_length + addend_length);
    strcat(sequence, addend);
    current_length += addend_length;
}

void myString::operator+=(char addend)
{
    resize(current_length + 1);
    sequence[current_length] = addend;
    current_length++;
    sequence[current_length] = '\0';
}

void myString::resize(size_t n)
{
    char* new_sequence;
    if (allocated > n)
        return;
    new_sequence = new char[n + 1];
    strcpy(new_sequence, sequence);
    delete[] sequence;
    sequence = new_sequence;
    allocated = n + 1;
}

void myString::operator=(const myString& source)
{
    resize(source.current_length);
    strcpy(sequence, source.sequence);
    current_length = source.current_length;
}

size_t myString::length() const
{
    return current_length;
}

char myString::operator[](size_t position) const
{
    assert(position < current_length);
    return sequence[position];
}

void myString::insert(myString &s, int p)
{

}

void myString::erase(int p1, int p2)
{
    assert (p1 < p2);
    char* new_sequence = new char[current_length - (p2 - p1)];
}

void myString::tokenize(const myString& s, const myString& delim, std::vector<myString>& container)
{
    for(size_t i = 0; i < s.current_length; i++)
    {
        if(s.sequence == delim)
        {
            myString token;
            for (size_t j = 0; j < s.current_length; j++)
                token += s.sequence[j];
            container.push_back(token);
        }
    }
}

std::ostream& operator<<(std::ostream& outs, const myString& source)
{
    outs << source.sequence;
    return outs;
}

bool operator==(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) == 0;
}

bool operator!=(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) != 0;
}

bool operator>=(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) >= 0;
}

bool operator<=(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) <= 0;
}

bool operator>(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) > 0;
}

bool operator<(const myString& s1, const myString& s2)
{
    return strcmp(s1.sequence, s2.sequence) < 0;
}

myString operator+(const myString& s1, const myString& s2)
{
    myString answer(s1);
    answer += s2;
    return answer;
}

std::istream& operator>>(std::istream& ins, myString& target)
{
    char next; // Next character read from the input stream
    // Skip any whitespace
    while (!ins.eof() && isspace(ins.peek()))
        ins.ignore();
    // Set the new string
    target = "";
    while (!ins.eof() && !isspace(ins.peek())) {
        ins >> next;
        target += next;
    }
    // Discard the remaining characters
    while (!ins.eof() && (ins.peek() != '\n')) {
        ins.ignore();
    }
    // Read and discard the newline character
    if (!ins.eof())
        ins.ignore();
    return ins;
}

void getline(std::istream& ins, myString& target) {
    char next; // Next character read from the input stream
    // Set the string to the empty string and read the new string
    target = "";
    while (!ins.eof() && (ins.peek() != '\n')) {
        ins.get(next);
        target += next;
    }
    // Read and discard the newline character
    if (!ins.eof())
        ins.ignore();
}
