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
    static const size_type CAPACITY = 30;

    // CONSTRUCTOR
    sorted_sequence();

    // MEMBER METHODS
    void start();
    void advance();

    void insert(const value_type& entry);
    // pre: the sequence is not full
    // post: entry has been inserted into this sequence so that it is in the correct order from smallest to largest

    void attach(const value_type& entry);
    void remove_current();
    size_type size() const;
    bool is_item() const;
    value_type current() const;

private:
    value_type data[CAPACITY];
    size_type used;
    size_type current_index;

    // Class Invariants
    // 1. the number of used items is stored in used
    // 2. the data is stored in sequence from smallest to largest starting from data[0], data[1], ... data[used - 1]
    // 3. if there is a current item, then it is in data[current_index]; if no current item, current_index == used

};

#endif // SORTED_SEQUENCE_H
