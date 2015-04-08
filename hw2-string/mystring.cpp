#include "mystring.h"
#include <algorithm>
#include <cstdlib>
#include <vector>

mystring::mystring(const char c[])                              //constructor for char array
{
    current_length = strlen(c);
    allocated = current_length + 1;
    character = new char[allocated];

    for(size_t i = 0; i != current_length; i++)
    {
        character[i] = c[i];
    }
}

mystring::mystring(const char c)                                //constructor for char
{
    current_length = 1;
    allocated = current_length + 1;
    character = new char[allocated];
    character[current_length - 1] = c;
}

size_t mystring::search_string(const char a[])
{
    size_t index = 0;                               //index for counting
    size_t i = 0;                                   //index for while loop

    while(i != current_length - strlen(a) + 1)      //while loop for checking
    {
        size_t insert = i;                          //index for starting new cursor
        char temp[strlen(a)];                       //new array for compare

        for(size_t j = 0; j != strlen(a); j++)      //for loop for putting char in new array
        {
            temp[j] = this->character[insert];
            insert++;
        }

        if(strcmp(temp, a) == 0)                    //compare 2 array
        {
            index++;
        }

        i++;
    }

    return index;
}

size_t mystring::search_char(const char a)
{
    size_t index = 0;

    for(size_t i = 0; i != current_length; i++)
    {
        if(this->character[i] == a)
        {
            index++;
        }
    }

    return index;
}

size_t mystring::locate_char(const char a)
{
    size_t i = 0;

    for(i; i != current_length; i++)
    {
        if(this->character[i] == a)
        {
            break;
        }
    }

    return i + 1;                                               //need to return i + 1 because
                                                                //pos is according to string
}

void mystring::replace_string(size_t pos1, size_t pos2, const char a[])
{
    this->erase(pos1, pos2);
    this->insert(a, pos1 - 1);
}

void mystring::replace(const char a, const char b)             //function for replace
{
    for(size_t i = 0; i != current_length; i++)
    {
        if(this->character[i] == a)
        {
            this->character[i] = b;
        }
    }
}

void mystring::erase(size_t pos1, size_t pos2)
{
    char newcharacter[allocated - (pos2 - pos1) + 1];           //create new array for storing temp

    for(size_t i = 0; i != pos1 - 1; i++)                       //for loop for putting everything
                                                                //before pos1 into new array
    {
        newcharacter[i] = this->character[i];
    }
    size_t newnumber = pos1 - 1;                                //index keeping trak of place in new array

    for(size_t i = pos2; i != current_length; i++)              //for loop for putting everthing
                                                                //after pos2 into new array
    {
        newcharacter[newnumber] = this->character[i];
        newnumber++;
    }                                                           //everthing in between pos1 and pos2
                                                                //is discarded
    allocated -=(pos2 - pos1) - 1;                              //define new allocated
    character = new char[allocated];                            //make old array into new size
    current_length = allocated;                                 //define new current length

    for(size_t i = 0; i != current_length; i++)                 //for loop for putting everything
                                                                //from new array into old array
    {
        this->character[i] = newcharacter[i];
    }
}

void mystring::insert(const char c[], size_t pos)
{
    size_t old_current_length = current_length;                 //variable for old current length
    current_length += strlen(c);                                //define new current length
    allocated = current_length + 1;                             //define new allocated
    char new_char[allocated];                                   //new array for storing temp
    char temp[old_current_length - pos];                        //new array for storing second part

    for(size_t i = 0; i != pos; i++)                            //for loop for putting everthing
                                                                //before pos into new array
    {
        new_char[i] = this->character[i];
    }
    size_t t1 = 0;                                              //index keeping track of pos in temp

    for(size_t i = pos; i != old_current_length; i++)           //for loop for putting everything
                                                                //after pos into temp
    {
        temp[t1] = this->character[i];
        t1++;
    }
    size_t cnumber = 0;                                         //index keeping track of pos in c

    for(size_t i = pos; i != current_length; i++)               //for loop for putting everything
                                                                //in c into new array
    {
        new_char[i] = c[cnumber];
        cnumber++;
    }
    size_t t2 = 0;                                              //second index keeping track of pos in temp

    for(size_t i = pos + strlen(c); i != current_length; i++)   //for loop for putting everything
                                                                //after pos into new array
    {
        new_char[i] = temp[t2];
        t2++;
    }
    character = new char[allocated];                            //make old array into new size

    for(size_t i = 0; i != current_length; i++)                 //for loop for putting everything
                                                                //from new array into old array
    {
        character[i] = new_char[i];
    }
}

std::ostream & operator << (std::ostream & os, const mystring & s)
{
    for(size_t i = 0; i != s.current_length; i++)   //for loop traversing character array
    {
        os << s.character[i];                       //os character array
    }

    return os;
}

void mystring::tokenize(const mystring& s, const mystring& delim, std::vector<mystring>& container)
{
    for(size_t i = 0; i < s.current_length; i++)
    {
        if(s.character == delim)
        {
            mystring token;
            for (size_t j = 0; j < s.current_length; j++)
                token += s.character[j];
            container.push_back(token);
        }
    }
}

//mystring::mystring mystring::tokenize(const mystring& s, const mystring& delim, mystring& container)
//{
//    size_t length(current_length);

//    for(size_t i = length; i >= 0; --i)
//    {
//        if(character[i] == delim)
//        {
//            for (size_t j = 0; j < i; j++)
//            {
//                container[i] = character[j];
//            }
//        }

//        if(i == 0)
//        {
//            container[i] = character[i];
//            //std::copy(character[i], current_length, container);
//        }
//        --current_length;
//    }
//    return container;
//}







