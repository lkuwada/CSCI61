#ifndef SET_H
#define SET_H
#include <cstdlib>

class set
{
public:

    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 10;

// CONSTRUCTORS
    set(size_type initial_cap = DEFAULT_CAPACITY);
    // pre: none
    // post: this set has been allocated a memory block of given size

    set(const set & source);
    // pre: none
    // post: a set has been created, which is a copy of the set source

// DESTRUCTOR
    ~set();
    // pre: none
    // post: this set has been destroyed and its dynamic memory returned to the OS

// CONSTANT MEMBER FUNCTIONS
    size_type size() const;
    // pre: none
    // post: return the number of items in this set

    bool contains(const value_type & target) const;
    // pre: none
    // post-condition: the return value is true if target is in the set; otherwise the return value is false

    size_type count(const value_type & target) const;
    // pre: none
    // post: returns the number of times target appears in this set

// NON-CONSTANT MEMBER FUNCTIONS
    void insert(const value_type & target);
    // pre: set is not full and target is not already in this set
    // post: a new instance of target has been added to this set

    bool remove(const value_type & target);
    // pre: none
    // post: if target is in this set it is removed and the return value is true; else (target is not in this
    //       set), nothing changes and return value is false

    void allocate(size_type new_capacity);
    // pre: new_capacity >= CAPACITY
    // post: the memory block's size has been changed to new_capacity

    void operator = (const set& source);
    // pre: none
    // post: this set has been made a copy of source

    void operator += (const set & source);
    // pre-condition: none
    // post-condition: a copy of the content of source has been added to this bag; if there are duplicate values in source, they
    //                  are not added to this set

    size_type operator[] (size_type i);


private:
    value_type *data;
    size_type used;
    size_type CAPACITY;

    // class invariants:
    // 1. used is the number of items in this set
    // 2. CAPACITY is the size of the memory block allocated to this bag
    // 3. data holds the address of the memory block allocated to this set
    //    the items are stored in data[0], data[1], ..., dad[used-1]
    //    don't care about content of remaining locations
    // 4. there can be no dupicalte values stored in data

};


#endif // SET_H
