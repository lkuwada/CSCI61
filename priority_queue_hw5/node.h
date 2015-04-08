#ifndef __node__node__
#define __node__node__
#include <iostream>
#include <cstdlib>
class node
{
public:
typedef int value_type;

node(const value_type & init_data = value_type() , node * init_link = NULL);
// pre: none
// post: a new node has been created with given field values default to value_type(), NULL

value_type data() const;
// pre: none
// post: returns a COPY of the data field

const node* link() const; // changing pointee is forbidden
// pre: none
// post: returns the link field
node * link(); // okay to change pointee

void set_data(const value_type &);
// pre: none
// post: set data field to new value

void set_link(node*);
// pre: none
// post: set link field to new value

private:
value_type data_field;
node * link_field;

};
std::ostream & operator << (std::ostream &, const node &);
//linked list toolkit
std::size_t list_length(const node *);
// pre: none
// post: returns the number of items in the list whos first node's address is provided
void list_head_insert(node * & head_ptr, const node::value_type & entry);
// pre: none
// post: allocates a new node with data set to entry and link_field set to the old head_ptr, head_ptr is updated to point to the new node
void list_insert(node * previous_ptr, const node::value_type &entry);
// pre: none
// post: allocate a new node with data_field set to entry and link_field set to the address of the node// following previous node// update the previous node to point to the new node
void list_head_remove(node * & head_ptr);
// pre: none
// post: remove the first node in the list whose head pointer is provided, update head_ptr to point to the next node
void list_remove(node* previous_ptr);
// pre: none
// post: remove the node following the previous node, update the previous node to point to the removed node's successor
node * list_search(node * head_ptr, const node::value_type & target);
const node * list_search(const node * head_ptr, const node::value_type & target);
// pre: none
// post: returns a pointer to the first node with target as data_field; if there is none, then returns NULL
node * list_locate(node * head_ptr, std::size_t position);
const node * list_locate(const node * head_ptr, std::size_t position);
// pre: none
// post: returns a pointer to the node at the given position in the list whose head pointer is given// the fist node is at position 0
void list_clear(node * &head_ptr);
// pre: none
// post: every node in the given list has been returned to the os head_ptr is set to NULL
void list_copy(const node* source_ptr, node* & head_ptr, node* & tail_ptr);
// pre: none
// post: a copy of the list given by source_ptr has been made pointers to the first and the last nodes of the copy are returned
void list_print(const node * head_ptr);
// pre: none
// post: output entries in the given list in order
#endif /* defined(__node__node__) */
