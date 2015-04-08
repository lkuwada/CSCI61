#include "set.h"
#include <algorithm>
#include <cassert>
#include <iostream>

set::set(size_type initial_cap)
{
    used = 0;
    data = new value_type[initial_cap];
    CAPACITY = initial_cap;
}

set::set(const set &source)
{
    data = new value_type[source.CAPACITY];
    CAPACITY = source.CAPACITY;
    used = source.used;
    std::copy(source.data, source.data + source.used, data);
}

set::~set()
{
    if (data != NULL)
        delete [] data;
}

set::size_type set::size() const
{
    return used;
}

bool set::contains(const value_type & target) const
{
    for (size_type i = 0; i < used; i++)
    {
        if (data[i] == target)
            return true;
    }
    return false;

}

set::size_type set::count(const value_type & target) const
{
    size_type ans(0);

    for (size_type i = 0; i < used; ++i)
        if (data[i] == target)
            ++ans;

    return ans;
}

void set::insert(const value_type &target)
{
    if (used == CAPACITY)
        allocate(2*CAPACITY);

    for (size_type i = 0; i < used; i++)
    {
        assert (data[i] != target);
    }
    data[used] = target;
    used++;
}

bool set::remove(const value_type &target)
{
    for (size_type i = 0; i < used; i++)
    {
        if (data[i] == target)
        {
            data[i] = data[used - 1];
            used--;
            return true;
        }
    }
    return false;

}

void set::allocate(size_type new_capacity)
{
    assert(new_capacity >= CAPACITY);

    value_type *new_data = new value_type[new_capacity];
    std::copy(data, data+used, new_data);
    delete [] data;
    data = new_data;
    CAPACITY = new_capacity;
}

void set::operator = (const set& source)
{
    if (&source == this)
        return;

    if (data != NULL)
        delete [] data;

    CAPACITY = source.CAPACITY;
    used = source.used;
    data = new int[source.CAPACITY];
    std::copy(source.data, source.data + source.used, data);
}

void set::operator += (const set& source)
{
    if (used + source.used > CAPACITY)
        allocate((used + source.used)*2);

    std::copy(source.data, source.data + source.used, data+used);
    used += source.used;

    size_type i(0);

    while (i < used) // for-loops do not have to have all 3 parameter specifications.
    {
        if (count(data[i]) > 1)
            remove(data[i]);
        else
            i++;
    }

}

set::size_type set::operator [](size_type i)
{
    return data[i];
}



