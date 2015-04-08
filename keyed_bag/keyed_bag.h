#ifndef KEYED_BAG_H
#define KEYED_BAG_H
#include <cstdlib>
#include <set>

class keyed_bag
{
public:

    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;

    keyed_bag();
    // pre: none
    // post: an empty keyed_bag has been created

    size_type size() const;
    // pre: none
    // post: return the number of items in this keyed bag

    bool has_key(int k) const;
    // pre: none
    // post: return value is true if key is in this bag; false if key is not in bag

    size_type get_data(int k) const;
    // pre: none
    // post: returns the data with the given key, k, in this bag.

    void insert(const value_type& target, int k);
    // pre: size() < CAPACITY and the bag does not yet contain any item with the given key
    // post: a new copy of target has been added to the bag, with the given key

    bool erase(int k);
    // pre: none
    // post: if key is in this bag, it is removed and the return value is true; else (key is not in this
    //                 bag), nothing changes and return value is false

    void operator +=(const keyed_bag& b);
    // pre: size() + b.size() <= CAPACITY
    // post: a copy of the content of b has been added to this bag

private:
    value_type data[CAPACITY];
    value_type keys[CAPACITY];
    size_type used;

    // class invariants:
    // 1. used is the number of items in this bag
    // 2. data[0], data[1], ..., data[used-1] are the location where these items are stored.
    // 3. keys[0], keys[1], ..., keys[used -1] store the keys that are associated with the items in data
    // 4. every item must be entered with a key and no keys can be repeated

};

keyed_bag operator + (const keyed_bag& b1, const keyed_bag& b2);

#endif // KEYED_BAG_H
