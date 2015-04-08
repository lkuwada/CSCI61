#include <iostream>
#include "set.h"

using namespace std;

int main()
{
    set a(10);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);

    set b(10);
    b.insert(1);
    b.insert(9);
    b.insert(8);
    b.insert(7);
    b.insert(4);

    a += b;

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;


    return 0;
}

