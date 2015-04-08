#include "keyed_bag.h"
#include <cassert>

keyed_bag::keyed_bag(keyed_bag::size_type init_cap)
{
    used = 0;
    CAPACITY = init_cap;
    data = new value_type[CAPACITY];
    keys = new value_type[CAPACITY];
}

keyed_bag::keyed_bag(const keyed_bag &source)
{
    data = new value_type[source.CAPACITY];
    keys = new value_type[source.CAPACITY];
    CAPACITY = source.CAPACITY;
    used = source.used;
    std::copy(source.data, source.data + source.used, data);
    std::copy(source.keys, source.keys + source.used, keys);
}

keyed_bag::~keyed_bag()
{
    if (data != NULL && keys != NULL)
    {
        delete [] data;
        delete [] keys;
    }
}

keyed_bag::size_type keyed_bag::size() const
{
    return used;
}

bool keyed_bag::has_key(int k) const
{
    for (size_type i = 0; i < used; i++)
    {
        if (k == keys[i])
            return true;
    }
    return false;
}

keyed_bag::size_type keyed_bag::get_data(int k) const
{
    return data[k];
}

void keyed_bag::insert(const value_type &target, int k)
{
    if (used == target.used)
        allocate(2 * CAPACITY);

    for (size_type i = 0; i < used; i++)
    {
        assert (k != keys[i]);
    }

    data[used] = target;
    keys[used] = k;
    used++;
}

bool keyed_bag::erase(int k)
{
    for (size_type i = 0; i < used; i++)
    {
        if (keys[i] == k)
        {
            used--;
            keys[i] = keys[used];
            data[i] = data[used];
            return true;
        }
    }
    return false;
}

//void keyed_bag::operator += (const keyed_bag& b)
//{
//    assert (size() + b.size() <= CAPACITY);
//    std::copy(b.data, b.data + b.used, data + used);
//    used += b.used;
//}

//keyed_bag::keyed_bag operator + (const keyed_bag& b1, const keyed_bag& b2)
//{
//    assert (b1.size() + b2.size() <= bag::CAPACITY);
//    bag ans;
//    ans += b1;
//    ans += b2;
//    return ans;
//}

void keyed_bag::operator = (const keyed_bag& source)
{
    if (&source == this)
        return;

    if (data != NULL && keys != NULL)
    {
        delete [] data;
        delete [] keys;
    }

    data = new value_type[source.CAPACITY];
    keys = new value_type[source.CAPACITY];
    CAPACITY = source.CAPACITY;
    used = source.used;
    std::copy(source.data, source.data + source.used, data);
    std::copy(source.keys, source.keys + source.used, keys);
}

void keyed_bag::allocate(size_type new_capacity)
{
    assert(new_capacity >= CAPACITY);

    value_type *new_data = new value_type[new_capacity];
    value_type *new_keys = new value_type[new_capacity];
    std::copy(data, data + used, new_data);
    std::copy(keys, keys + used, new_keys);
    delete [] data;
    delete [] keys;
    data = new_data;
    keys = new_keys;
    CAPACITY = new_capacity;
}


