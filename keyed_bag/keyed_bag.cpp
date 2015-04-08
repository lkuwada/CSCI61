#include "keyed_bag.h"
#include <cassert>

keyed_bag::keyed_bag(keyed_bag::size_type init_cap)
{
    used = 0;
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
    assert (size() < CAPACITY);
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

void keyed_bag::operator += (const keyed_bag& b)
{
    assert (size() + b.size() <= CAPACITY);
    std::copy(b.data, b.data + b.used, data + used);
    used += b.used;
}

keyed_bag::keyed_bag operator + (const keyed_bag& b1, const keyed_bag& b2)
{
    assert (b1.size() + b2.size() <= bag::CAPACITY);
    bag ans;
    ans += b1;
    ans += b2;
    return ans;
}


