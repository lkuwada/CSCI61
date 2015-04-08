#include "chores.h"
#include "string.h"
#include "node.h"
#include <set>
#include <list>

chores::chores(std::list<std::string> data, node* pointer)
{
    data = NULL;
    pointer = NULL;
}

std::list<std::string> chores::add(std::list<string>& list, string s1)
{
    s1.list_head_insert(list);
}

std::list<string> chores::remove_chores(std::list<string>& list, string s1)
{
    pointer->set_data(pointer->link()->data());
    node * temp = pointer->link();
    pointer->set_link(pointer->link()->link());
    delete temp;
}

std::list<string> chores::print_list(std::list<string>& list)
{
    list.list__print;
}

std::list<string> chores::print_index(std::list<string>& list)
{
    int index;
    for (int i = 0; i <= list.length; i ++)
    index++;
    std::cout << index;
}

std::list<std::string> chores::get_data()
{
    return data;
}

node* chores::get_link()
{
    return pointer;
}
