#include <iostream>

using namespace std;

int main()
{
// #1 Black Box Test
    bag a, b, c, d;

    b.insert(8);

    c.insert(2);
    c.insert(9);
    c.insert(54);
    c.insert(7);
    c.insert(7);
    c.insert(20);
    c.insert(7);
    c.insert(83);
    c.insert(5);
    c.insert(7);

    d.insert(4);
    d.insert(76);

    cout << "The number of objects in a is: " << a.size() << endl;
    cout << "The number of objects in b is: " << b.size() << endl;
    cout << "The number of objects in c is: " << c.size() << endl;
    cout << "The number of objects in d is: " << d.size() << endl;

    cout << "The number of times 7 occurs in bag c is: " << c.count(7) << endl;
    c.erase_one(7);
    cout << "The number of times 7 occurs in bag c is now: " << c.count(7) << endl;
    c.erase(7);
    cout << "The number of times 7 occurs in bag c is now: " << c.count(7) << endl;

    b += d;
    cout << "After d has been added to bag b, the size of b is now: " << b.size() << endl;

    cout << "The number of objects in c is: " << c.size() << endl;
    bag e(c + d);
    cout << "The number of objects in bag e, which is c + d, is: " << e.size() << endl;

    return 0;
}

// #2 Subtraction
    void bag::operator -=(const bag & b)
    {
        for (bag::size_type i = 0; i < b.used; ++i)
        {
            for (bag::size_type j = 0; j < used; ++j)
            {
                if (b.data[i] == data[j])
                {
                    this->erase_one(b.data[i]);
                    break;
                }
            }
        }
    }

    bag operator - (bag & b1, const bag & b2)
    {
        bag ans;
        ans += b1;
        ans -= b2;
        return ans;
    }

// #4 Subscript Operator
    value_type sequence::operator [] (size_type index) const
    {
        assert (index < used);
        return data[index];
    }

// #5 Set
// In the project called set

// #6 Sorted Sequence
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>

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
#endif // SEQUENCE_H

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

// #8 Keyed Bag
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


#include "keyed_bag.h"
#include <cassert>

keyed_bag::keyed_bag()
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





// #14 Biguint
#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>


class biguint
{
public:

    typedef std::size_t size_type;
    static const size_type CAPACITY = 10;

// CONSTRUCTORS
    biguint (unsigned int = 0);
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value

    biguint (const std::string & s);
    // pre-condition: s has at most CAPACITY characters, which must all be decimal digits
    // post-condition: this biguint has been initialized to given value represented by given string

    biguint (const char[]);
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value represented by given c-string


    size_type operator[] (size_type pos) const;
    // pre-condition: pos < bigugint::CAPACITY
    // post-condition: the digit at position pos is returned (the least significant digit is at postition 0)

    void operator += (const biguint &);
    // pre-condition: none
    // post-condition: the value of this biguint has been incremented by n. the overflow digit is discarded if there is one

    void operator *= (size_type d);
    // pre-condition: d <= 9
    // post-condition: the value of this biguing has been multiplied by the digit d; the overfow digit discarded if there is one

    int compare (const biguint & n) const;
    // pre-condition: none
    // post-condition: returns 0 if n == this biguint, -1 if n > this biguint, 1 if < this biguint

    void rshift ();
    // pre-condition: none
    // post-condition: the digits of this biguint have been shifted right by one position; the new leftmost digit is 0, and the
    //                 old rightmost digit is discarded


    void operator -= (const biguint &);
    // pre-condition: none
    // post-condition: if this biguint >= n, then n is subtracted from this biguint; else set this biguint to zero



    void lshift();
    // pre-condition: none
    // post-condition: the digits of this biguint have been shifted left by one position; the new rightmost digit is 0, and the old
    //                 leftmost digit is discarded

    void operator *= (const biguint & n);
    // pre-condition: none
    // post-condition: the value of this biguint has been multiplied by n; any overflow digits are discarded

    void operator /= (const biguint & n);
    // pre-condition: n != 0
    // post-condition: the new value of this biguint is the old value divided by n and truncated


private:
    size_type data[CAPACITY];
    // invariants:
    //      1. The digits of this biguint are stored in data[0], data[1], ... , data[CAPACITY-1]
    //      2. Least significant digit it at 0
    //         Most significant digit is at CAPACITY-1
    //      3. Unused digits are filled with 0

};


std::ostream & operator << (std::ostream &, const biguint &);
std::istream & operator >> (std::istream &, biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);
biguint operator * (const biguint &, const biguint &);
biguint operator / (const biguint &, const biguint &);

#endif // BIGUINT_H


#include "biguint.h"
#include <cassert>
#include <cctype>


biguint::biguint (unsigned int initial)
{
    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    size_type k = 0;
    while (initial != 0)
    {
        data[k++] = initial % 10;
        initial /= 10;
    }
}

biguint::biguint (const std::string & s)
{
    size_type l = s.length();

    assert (l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert (isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';
}

biguint::biguint (const char s[])
{
    size_type l = strlen(s);

    assert (l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert (isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';
}



biguint::size_type biguint::operator [] (size_type p) const
{
    assert (p < CAPACITY);
    return data[p];
}

int biguint::compare (const biguint & n) const
{
    for (size_type i = 0; i < CAPACITY; ++i)
    {
        if (data[CAPACITY-1 - i] < n.data[CAPACITY - 1 - i])
            return -1;
        else if (data[CAPACITY - 1 - i] > n.data[CAPACITY - 1 - i])
            return 1;
    }
    return 0;
}

void biguint::rshift()
{

    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        data [i] = data [i + 1];
    }
    data[CAPACITY - 1] = 0;

}

void biguint::operator += (const biguint & b)
{
    int carry(0), sum;
    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        sum = carry + data[i] + b.data[i];
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

void biguint::operator -= (const biguint & n)
{
    if (*this < n)
    {
        *this = biguint();
        return;
    }

    size_type borrow = 0;
    for (size_type i = 0; i < CAPACITY; ++i)
    {
        if (data[i] >= n.data[i] + borrow)
        {
            data[i] -= (n.data[i] + borrow);
            borrow = 0;
        }
        else
        {
            data[i] = data[i] + 10 - n.data[i] - borrow;
            borrow = 1;
        }
    }
}

void biguint::operator *= (size_type d)
{
    assert(d <= 9);

    int carry(0), sum;
    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        sum = carry + data[i] * d;
        data[i] = sum % 10;
        carry = sum / 10;
    }
}



void biguint::lshift()
{
    for (size_type i = CAPACITY - 1; i > 0; --i)
    {
        data [i] = data [i - 1];
    }
    data [0] = 0;
}

void biguint::operator *= (const biguint & n)
{
    size_type zero = 0;
    biguint ans(zero);

    for (int i = CAPACITY - 1; i >= 0; --i)
    {
        biguint temp(n);
        temp *= data[i];
        ans.lshift();
        ans += temp;
    }
    std::copy(ans.data, ans.data + CAPACITY, data);
}

void biguint::operator /= (const biguint & n)
{
    size_type z = 0;
    biguint zero(z);
    assert(n.compare(zero) != 0);

    biguint lo, hi(*this), mid;

    while (lo <= hi)
    {
        mid = lo + hi;
        mid *= 5;
        mid.rshift();
        int result = (*this).compare(mid * n);

        if (result == 0)
        {
            std::copy(mid.data, mid.data + CAPACITY, data);
            return;
        }
        if (result > 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    std::copy(hi.data, hi.data + CAPACITY, data);
}



std::ostream & operator << (std::ostream & os, const biguint & b)
{
    bool padding = true;

    for (biguint::size_type i = 0; i < biguint::CAPACITY; ++i)
    {
        biguint::size_type p = biguint::CAPACITY - 1 -i;
        if (b[p] != 0)
            padding = false;
        if (!padding)
            os << b[biguint::CAPACITY - 1 - i];
    }

    if (padding)
        os << "0";

    return os;
}

std::istream & operator >> (std::istream & is, biguint & b)
{
    std::string s;
    is >> s;
    b = biguint(s);
    return is;
}


bool operator < (const biguint & a, const biguint & b)
{
    return (a.compare(b) == -1);
}

bool operator <= (const biguint & a, const biguint & b)
{
    return (a.compare(b) != 1);
}

bool operator == (const biguint & a, const biguint & b)
{
    return (a.compare(b) == 0);
}

bool operator != (const biguint & a, const biguint & b)
{
    return (a.compare(b) != 0);
}

bool operator > (const biguint & a, const biguint & b)
{
    return (a.compare(b) == 1);
}

bool operator >= (const biguint & a, const biguint & b)
{
    return (a.compare(b) != -1);
}


biguint operator + (const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans += b;
    return ans;
}

biguint operator - (const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans -= b;
    return ans;
}

biguint operator * (const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans *= b;
    return ans;
}

biguint operator / (const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans /= b;
    return ans;
}






