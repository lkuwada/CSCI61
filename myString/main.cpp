#include <iostream>
#include <mystring.h>
#include <vector>

using namespace std;

int main()
{
    myString a("Hello World");
    vector<myString> container;

    a.tokenize(a, " ", container);

    for(vector<myString>::iterator i = container.begin(); i != container.end(); ++i)
        cout << *i << endl;

    return 0;
}

