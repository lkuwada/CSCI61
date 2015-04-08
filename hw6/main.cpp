#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    binary_search_tree<int> ans;
    ans.insert(5);
    ans.insert(9);
    ans.insert(1);
    ans.insert(3);
    ans.insert(4);
    ans.insert(0);
    ans.insert(22);

    ans.insert(93);
    ans.insert(256);
    ans.insert(48);
    ans.insert(77);
    ans.insert(14);
    ans.insert(32);

    //ans.print();
    //cout << ans.longestPath() << endl;

//    node<int>* list;
//    list_head_insert(list, 1);
//    list_insert(list, 7);
//    list_insert(list, 6);
//    list_insert(list, 5);
//    list_insert(list, 4);
//    list_insert(list, 3);
//    list_insert(list, 2);

//    for (node<int>* cursor = list; cursor->link() != NULL; cursor = cursor->link())
//        cout << cursor->data() << endl;

//    ans.list2tree(list);
//    ans.print();

    return 0;
}

