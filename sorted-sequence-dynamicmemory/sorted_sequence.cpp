#include <cstdlib>
#include <algorithm>
#include "sorted_sequence.h"

sorted_sequence::sorted_sequence(size_type initial_cap)
{
    used = 0;
    data = new value_type[initial_cap];
    current_index = 0;
    CAPACITY = initial_cap;
}

sorted_sequence::sorted_sequence(const sorted_sequence &source)
{
    data = new value_type[source.CAPACITY];
    used = source.used;
    current_index = source.current_index;
    CAPACITY = source.CAPACITY;

    std::copy(source.data, source.data + source.used, data);
}

sorted_sequence::~sorted_sequence()
{
    if (data != NULL)
        delete [] data;
}

void sorted_sequence::start()
{
    current_index = 0;
}

void sorted_sequence::advance()
{
    assert(is_item());
    current_index++;
}

void sorted_sequence::allocate(size_type new_capacity)
{
    assert(new_capacity >= CAPACITY);

    value_type *new_data = new value_type[new_capacity];
    std::copy(data, data+used, new_data);
    delete [] data;
    data = new_data;
    CAPACITY = new_capacity;
}

void sorted_sequence::insert(const value_type& entry)
{
    if(used == CAPACITY)
        allocate(2*CAPACITY);

    current_index = 0;

    for (size_type i = 0; i < used; i++)
    {
        if (entry > data[i])
            current_index++;
    }

    // Shift other items over, and insert the new entry at current_index
    for (size_type index = used; index > current_index; index--)
        data[index] = data[index - 1];

    data[current_index] = entry;
    used++;
}

void sorted_sequence::attach(const value_type& entry)
{
    if (size() == CAPACITY)
        allocate(2*CAPACITY);

    if (!is_item()) // There is no current item, so insert at end
        data[current_index] = entry;
    else // There is a current item, so move items over to make room
    {
        for (size_type index = used; index > current_index + 1; index--)
            data[index] = data[index - 1];
        data[current_index + 1] = entry;
        current_index++;
    }
    used++;
}

void sorted_sequence::remove_current()
{
    assert(is_item());
    for (size_type index = current_index + 1; index < used; index++)
        data[index - 1] = data[index];

    used--;
}

sorted_sequence::size_type sorted_sequence::size() const
{
    return used;
}

bool sorted_sequence::is_item() const
{
    return (current_index < used);
}

sorted_sequence::value_type sorted_sequence::current() const
{
    assert(is_item());
    return data[current_index];
}

void sorted_sequence::operator = (const sorted_sequence& source)
{
    if (&source == this)
        return;

    if (data != NULL)
        delete [] data;

    used = source.used;
    CAPACITY = source.CAPACITY;
    current_index = source.current_index;
    data = new value_type [source.CAPACITY];
    std::copy(source.data, source.data + source.used, data);
}
