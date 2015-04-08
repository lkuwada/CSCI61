#ifndef KEYED_BAG_H
#define KEYED_BAG_H
#include <cstdlib>
#include <set>

class keyed_bag
{
public:

    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

//CONSTRUCTOR
    keyed_bag(size_type init_cap = DEFAULT_CAPACITY);
    // pre: none
    // post: an empty keyed_bag has been created

    keyed_bag(const keyed_bag& source);
    // pre: none
    // post: a bag has been created, which is a copy of bag source

// DESTRUCTOR
    ~keyed_bag();
    // pre: none
    // post: this bag has been destroyed and its dynamic memory returned to the OS

// CONSTANT MEMBER FUNCTIONS
    size_type size() const;
    // pre: none
    // post: return the number of items in this keyed bag

    bool has_key(int k) const;
    // pre: none
    // post: return value is true if key is in this bag; false if key is not in bag

    size_type get_data(int k) const;
    // pre: none
    // post: returns the data with the given key, k, in this bag.

// MEMBER FUNCTIONS
    void insert(const value_type& target, int k);
    // pre: this bag does not yet contain any item with the given key
    // post: a new copy of target has been added to the bag, with the given key

    bool erase(int k);
    // pre: none
    // post: if key is in this bag, it is removed and the return value is true; else (key is not in this
    //                 bag), nothing changes and return value is false

    void operator +=(const keyed_bag& b);
    // pre: none
    // post: a copy of the content of b has been added to this bag, keys that are already in b are left out of this bag

    void operator = (const keyed_bag& source);
    // pre: none
    // post: this bag has been made a copy of source

    void allocate(size_type new_capacity);
    // pre: new_capacity >= CAPACITY
    // post: the memory block's size has been changed to new_capacity

private:
    value_type* data;
    value_type* keys;
    size_type used;
    size_type CAPACITY;

    // class invariants:
    // 1. used is the number of items in this bag
    // 2. data holds the address of the memory block allocated to this bag.
    //    the items are stored in data[0], data[1], ..., data[used-1]
    // 3. keys holds the address of the memory block allocated to this bag's keys...
    //    the keys are stored in keys[0], keys[1], ..., keys[used -1]
    // 4. every item must be entered with a key and no keys can be repeated
    // 5. CAPACITY is the size of the memory block allocated to this bag

};

keyed_bag operator + (const keyed_bag& b1, const keyed_bag& b2);

#endif // KEYED_BAG_H
