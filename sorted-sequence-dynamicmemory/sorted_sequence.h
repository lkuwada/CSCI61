#ifndef SORTED_SEQUENCE_H
#define SORTED_SEQUENCE_H
#include <cstdlib>
#include <cassert>

class sorted_sequence
{
public:
// TYPEDEFS and CONSTANTS
    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

// CONSTRUCTORS
    sorted_sequence(size_type initial_cap = DEFAULT_CAPACITY);
    // pre: none
    // post: the sequence has been created and allocated a memory block of the given size

    sorted_sequence(const sorted_sequence& source);
    // pre: none
    // post: a sorted sequence has been created, which is a copy of the sorted sequence source

// DESTRUCTOR
    ~sorted_sequence();
    // pre: none
    // post: this sorted sequence has been destroyed and its dynamic memory returned to the OS

// MEMBER METHODS
    void start();
    // pre: none
    // post: the first item in sequence becomes current item (if sequence is empty, no current item)

    void advance();
    // pre: is_item returns true
    // post: if current item was already last item in sequence, then there is no longer any current item; otherwise new item is
    //       item immediately after original current item

    void allocate(size_type new_capacity);
    // pre: new_capacity >= CAPACITY
    // post: the memory block's size has been changed to new_capacity

    void insert(const value_type& entry);
    // pre: none
    // post: entry has been inserted into this sequence so that it is in the correct order from smallest to largest

    void attach(const value_type& entry);
    // pre: none
    // post: new copy of entry has been inserted in the sequence before current item. if no current item, entry is inserted
    //       at the front. new item is now current item.

    void remove_current();
    // pre: is_item returns true
    // post: current item has been removed from sequence and item after this (if there is one) is now new current item

    size_type size() const;
    // pre: none
    // post: number of items in sequence is returned

    bool is_item() const;
    // pre: none
    // post: true is returned if there is a valid "current" item that may be retrieved by current() member function.
    //       false returned if there is no valid current item

    value_type current() const;
    // pre: is_item() returns true
    // post: the item returned is the current item in the sequence

    void operator = (const sorted_sequence& source);
    // pre: none
    // post: this sorted sequence has been made a copy of source

private:
    value_type* data;
    size_type used;
    size_type current_index;
    size_type CAPACITY;

    // Class Invariants
    // 1. the number of used items is stored in used
    // 2. data holds the address of the memory block allocated to this sequence. the items are stored from
    //    smallest to largest starting from data[0], data[1], ... data[used - 1]
    // 3. if there is a current item, then it is in data[current_index]; if no current item, current_index == used
    // 4. CAPACITY holds the size of the memory block allocated to this sorted sequence

};

#endif // SORTED_SEQUENCE_H
