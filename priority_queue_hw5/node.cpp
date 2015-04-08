#include "node.h"
node::node(const value_type & init_data,
node * init_link)
{
data_field = init_data;
link_field = init_link;
}
node::value_type node::data() const
{
return data_field;
}
const node * node::link() const
{
return link_field;
}
node * node::link()
{
return link_field;
}
void node::set_data(const value_type & new_data)
{
data_field = new_data;
}
void node::set_link(node * new_link)
{
link_field = new_link;
}
std::ostream & operator <<(std::ostream & os, const node & n)
{
os << "(" << n.data() << ", " << n.link() << ")";
return os;

}
std::size_t list_length(const node * head_ptr)
{
std::size_t ans(0);

for (const node * cursor = head_ptr; cursor != NULL;
cursor = cursor->link())
ans++;

return ans;
}
void list_head_insert(node * & head_ptr,
const node::value_type & entry)
{
head_ptr = new node(entry, head_ptr);
}
void list_insert(node *previous_ptr,
const node::value_type &entry)
{
node *temp = new node(entry, previous_ptr->link());
previous_ptr->set_link(temp);
}
void list_head_remove(node * & head_ptr)
{
node *temp = head_ptr;
head_ptr = head_ptr->link();
delete temp;
}
void list_remove(node * previous_ptr)
{
node * temp = previous_ptr->link();
previous_ptr->set_link(temp->link());
delete temp;
}
void list_print(const node * head_ptr)
{
for (const node * cursor = head_ptr;
cursor != NULL;
cursor = cursor->link())
{
std::cout << cursor->data() << " ";
}
std::cout << std::endl;
}
void list_clear(node * & head_ptr)
{
while (head_ptr != NULL)
list_head_remove(head_ptr);

}
node * list_search(node *head_ptr,
const node::value_type & target)
{
node *cursor;
for (cursor = head_ptr;
cursor != NULL && cursor->data() != target;
cursor = cursor->link());

return cursor;

}
const node * list_search(const node *head_ptr,
const node::value_type & target)
{
const node *cursor;
for (cursor = head_ptr;
cursor != NULL && cursor->data() != target;
cursor = cursor->link());

return cursor;

}
node *list_locate(node *head_ptr, std::size_t position)
{
node *ans = head_ptr;

for (std::size_t i = 0;
i < position && ans != NULL; ++i)
ans = ans->link();

return ans;
}
const node *list_locate(const node *head_ptr,
std::size_t position)
{
const node *ans = head_ptr;

for (std::size_t i = 0;
i < position && ans != NULL; i++)
ans = ans->link();

return ans;
}
void list_copy(const node *source_ptr,
node *&head_ptr,
node *&tail_ptr)
{
head_ptr = tail_ptr = NULL;
if (source_ptr == NULL)
return;

list_head_insert(head_ptr, source_ptr->data());
tail_ptr = head_ptr;

for (source_ptr = source_ptr->link();
source_ptr != NULL;
source_ptr = source_ptr->link())
{
list_insert(tail_ptr, source_ptr->data());
tail_ptr = tail_ptr->link();
}
}
