#include "sorted_sequence.h"

sorted_sequence::sorted_sequence()
{
    used = 0;
    current_index = 0;
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

void sorted_sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

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
    assert(size() < CAPACITY);
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

void sorted_sequence::remove_current() {
    assert(is_item());
    for (size_type index = current_index + 1; index < used; index++)
        data[index - 1] = data[index];

    used--;
}

sorted_sequence::size_type sorted_sequence::size() const {
    return used;
}

bool sorted_sequence::is_item() const {
    return (current_index < used);
}

sorted_sequence::value_type sorted_sequence::current() const {
    assert(is_item());
    return data[current_index];
}
