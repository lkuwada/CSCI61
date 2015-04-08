#include <iostream>
#include "stack.h"
#include <cstdlib>

using namespace std;

int main()
{
    stack<int> s1;
    s1.push(7);
    s1.push(5);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    int size = s1.size();
    cout << size << endl;

    int ans = s1.seek(1);
    cout << ans << endl;

    return 0;
}

