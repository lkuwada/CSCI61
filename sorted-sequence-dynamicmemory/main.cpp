#include <iostream>
#include "sorted_sequence.h"

using namespace std;

int main()
{
    sorted_sequence a(10);
    a.insert(7);
    a.insert(5);
    a.insert(53);
    a.insert(29);
    a.insert(0);
    a.insert(2);
    a.insert(200);

    for(a.start(); a.is_item(); a.advance())
        cout << a.current() << endl;


    return 0;
}

