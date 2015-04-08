// FILE: stack4.h (part of the namespace main_savitch_7B)
// TEMPLATE CLASS PROVIDED: stack<T> (a stack of Ts)
//   The template parameter, T, is the data type of the Ts in the stack,
//   also defined as stack<T>::value_type.
//   It may be any of the C++ built-in types (int, char, etc.), or a class
//   with a default constructor, a copy constructor, and an assignment
//   operator. The definition stack<T>::size_type is the data type of
//   any variable that keeps track of how many Ts are in a stack.
//
// CONSTRUCTOR for the stack<T> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<T> class:
//   void push(const T& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   T pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top T of the stack has been removed.
//
//   T& top( )
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a reference to the top T of
//     the stack (but the stack is unchanged).
//
// CONSTANT MEMBER FUNCTIONS for the stack<T> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of Ts in the stack.
//
//   const T& top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a const reference to the top T of
//     the stack (but the stack is unchanged).
//
// VALUE SEMANTICS for the stack<T> class:
//   Assignments and the copy constructor may be used with stack<T>
//   objects.
//
// DYNAMIC MEMORY USAGE by the stack<T> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   the copy constructor, push, and the assignment operator.

#ifndef MAIN_SAVITCH_STACK4_H
#define MAIN_SAVITCH_STACK4_H
#include <cstdlib>   // Provides NULL and size_t
#include "node.h"   // Node template class from Figure 6.5 on page 308


    template <class T>
    class stack
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef T value_type;
        // CONSTRUCTORS and DESTRUCTOR
        stack( ) { top_ptr = NULL; }
        stack(const stack& source);
        ~stack( ) { list_clear(top_ptr); }
        // MODIFICATION MEMBER FUNCTIONS
        void push(const T& entry);
        void pop( );
        void operator =(const stack& source);
        T& top( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const
        { return list_length(top_ptr); }
        bool empty( ) const { return (top_ptr == NULL); }
        const T& top( ) const;

        T seek(size_type n = 1);

    private:
        node *top_ptr;  // Points to top of stack
    };


//#include "stack4.template" // Include the implementation
#endif

    // FILE: stack4.template
    // TEMPLATE CLASS IMPLEMENTED: stack<T> (see stack4.h for documentation)
    // This file is included in the header file, and not compiled separately.
    // INVARIANT for the stack class:
    //   1. The Ts in the stack are stored in a linked list, with the top of the
    //      stack stored at the head node, down to the bottom of the stack at the
    //      final node.
    //   2. The member variable top_ptr is the head pointer of the linked list.

    #include <cassert>  // Provides assert
    #include "node.h"  // Node template class


        template <class T>
        stack<T>::stack(const stack<T>& source)
        // Library facilities used: node2.h
        {
            node *tail_ptr; // Needed for argument of list_copy

            list_copy(source.top_ptr, top_ptr, tail_ptr);
        }

        template <class T>
        void stack<T>::push(const T& entry)
        // Library facilities used: node2.h
        {
            list_head_insert(top_ptr, entry);
        }

        template <class T>
        void stack<T>::pop( )
        // Library facilities used: cassert, node2.h
        {
            assert(!empty( ));
            list_head_remove(top_ptr);
        }

        template <class T>
        void stack<T>::operator =(const stack<T>& source)
        // Library facilities used: node2.h
        {
            node *tail_ptr; // Needed for argument of list_copy

            if (this == &source) // Handle self-assignment
                return;

            list_clear(top_ptr);
            list_copy(source.top_ptr, top_ptr, tail_ptr);
        }

        template <class T>
        T& stack<T>::top( )
        // Library facilities used: cassert
        {
            assert(!empty( ));
            return top_ptr->data( );
        }

        template <class T>
        const T& stack<T>::top( ) const
        // Library facilities used: cassert
        {
            assert(!empty( ));
            return top_ptr->data( );
        }

        template <class T>
        T stack<T>::seek(size_type n)
        {
            assert (n < size());

            size_type counter(0);
            for (node* cursor = top_ptr; cursor != NULL; cursor = cursor->link())
            {
                if (counter == n)
                {
                    return cursor->data();
                }
                counter++;
            }
        }

