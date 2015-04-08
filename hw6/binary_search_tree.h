#include <iostream>
#include <iomanip>
#include "node.h"

using namespace std;

template<class Item>
class binary_tree_node
{
public:
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data_field = init_data;
        left_field = init_left;
        right_field = init_right;
    }
    // ACCESSOR & MUTATOR
    Item& data();
    binary_tree_node*& left();
    binary_tree_node*& right();
    void set_data(const Item& new_data);
    void set_left(binary_tree_node* new_left);
    void set_right(binary_tree_node* new_right);
    const Item& data() const;
    const binary_tree_node* left() const;
    const binary_tree_node* right() const;
    bool is_leaf() const;

private:
    Item data_field;
    binary_tree_node* left_field;
    binary_tree_node* right_field;
};

template<class Item>
Item& binary_tree_node<Item>::data()
{
    return data_field;
}

template<class Item>
binary_tree_node<Item>*& binary_tree_node<Item>::left()
{
    return left_field;
}

template<class Item>
binary_tree_node<Item>*& binary_tree_node<Item>::right()
{
    return right_field;
}

template<class Item>
void binary_tree_node<Item>::set_data(const Item& new_data)
{
    data_field = new_data;
}

template<class Item>
void binary_tree_node<Item>::set_left(binary_tree_node* new_left)
{
    left_field = new_left;
}

template<class Item>
void binary_tree_node<Item>::set_right(binary_tree_node* new_right)
{
    right_field = new_right;
}

template<class Item>
const Item& binary_tree_node<Item>::data() const
{
    return data_field;
}

template<class Item>
const binary_tree_node<Item>* binary_tree_node<Item>::left() const
{
    return left_field;
}

template<class Item>
const binary_tree_node<Item>* binary_tree_node<Item>::right() const
{
    return right_field;
}

template<class Item>
bool binary_tree_node<Item>::is_leaf() const
{
    return (left_field == NULL) && (right_field == NULL);
}


// BINARY_SEARCH_TREE CLASS
template<class Item>
class binary_search_tree
{
public:
    binary_search_tree();
    ~binary_search_tree();
    binary_search_tree(const binary_search_tree&);
    const binary_search_tree& operator=(const binary_search_tree&);
    void print();
    void insert(const Item&);
    void remove(const Item&);
    bool contains(const Item&);
    int size();
    int height();

    void list2tree(node<Item> *list1_ptr);
    // pre: the link list stored in list is sorted from least to greatest
    // post: source is a balanced BST with the values of list

    int longestPath();


private:
    binary_tree_node<Item>* root;
    void clear(binary_tree_node<Item>*&);
    binary_tree_node<Item>* copy(const binary_tree_node<Item>*);
    void print(binary_tree_node<Item>*, int);
    int size(const binary_tree_node<Item>*);
    int height(const binary_tree_node<Item>*);
    bool contains(const Item&, binary_tree_node<Item>*);
    void insert(const Item&, binary_tree_node<Item>*&);
    void remove(const Item&, binary_tree_node<Item>*&);
    binary_tree_node<Item>* findMin(binary_tree_node<Item>*);
    binary_tree_node<Item>* findMax(binary_tree_node<Item>*);

    int longestPath(binary_tree_node<Item>* node_ptr);
};



template<typename Item>
void binary_search_tree<Item>::clear(binary_tree_node<Item>*& node_ptr)
{
    binary_tree_node<Item>* child;
    if (node_ptr != NULL) {
        child = node_ptr->left();
        clear(child);
        child = node_ptr->right();
        clear(child);
        delete node_ptr;
        node_ptr = NULL;
    }
}

template<typename Item>
binary_tree_node<Item>* binary_search_tree<Item>::copy(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return NULL;
    else
        return new binary_tree_node<Item>(node_ptr->data(),
                                          copy(node_ptr->left()), copy(node_ptr->right()));
}

template<typename Item>
void binary_search_tree<Item>::print(binary_tree_node<Item>* node_ptr, int depth)
{
    if (node_ptr != NULL) {
        print(node_ptr->right(), depth + 1); // print right subtree
        cout << setw(4 * depth) << ""; // indent 4*depth spaces
        cout << node_ptr->data(); // print node's data
        //cout << "(" << node_ptr << ")"; // DEBUG: print node's address
        cout << endl;
        print(node_ptr->left(), depth + 1); // print left subtree
    }
}

template<typename Item>
int binary_search_tree<Item>::size(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return 0;
    else
        return 1 + size(node_ptr->left()) + size(node_ptr->right());
}

template<typename Item>
int binary_search_tree<Item>::height(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return 0;
    else
    {
        int l = height(node_ptr->left());
        int r = height(node_ptr->right());
        return (l > r) ? l + 1 : r + 1;
    }
}

template<typename Item>
bool binary_search_tree<Item>::contains(const Item& x, binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return false;
    else if (x < node_ptr->data())
        return contains(x, node_ptr->left());
    else if (x > node_ptr->data())
        return contains(x, node_ptr->right());
    else
        return true;
}

template<typename Item>
void binary_search_tree<Item>::insert(const Item& x, binary_tree_node<Item>*& node_ptr)
{
    if (node_ptr == NULL)
        node_ptr = new binary_tree_node<Item>(x);
    else if (x < node_ptr->data())
        insert(x, node_ptr->left());
    else if (x > node_ptr->data())
        insert(x, node_ptr->right());
    return;
}

template<typename Item>
void binary_search_tree<Item>::remove(const Item& x, binary_tree_node<Item>*& node_ptr)
{
    if (node_ptr == NULL)
        return;
    if (x < node_ptr->data())
        remove(x, node_ptr->left());
    else if (x > node_ptr->data())
        remove(x, node_ptr->right());
    else if (node_ptr->left() != NULL && node_ptr->right() != NULL)
    {
        node_ptr->data() = findMin(node_ptr->right())->data();
        remove(node_ptr->data(), node_ptr->right());
    }
    else
    {
        binary_tree_node<Item>* old_ptr = node_ptr;
        node_ptr = (node_ptr->left() != NULL) ?
                    node_ptr->left() : node_ptr->right();
        delete old_ptr;
    }
    return;
}

template<typename Item>
binary_tree_node<Item>* binary_search_tree<Item>::findMin(binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return NULL;
    if (node_ptr->left() == NULL)
        return node_ptr;
    return findMin(node_ptr->left());
}

template<typename Item>
binary_tree_node<Item>* binary_search_tree<Item>::findMax(binary_tree_node<Item>* node_ptr)
{
    if (node_ptr != NULL)
        while (node_ptr->right() != NULL)
            node_ptr = node_ptr->right();
    return node_ptr;
}

template<typename Item>
binary_search_tree<Item>::binary_search_tree()
{
    root = NULL;
}

template<typename Item>
binary_search_tree<Item>::~binary_search_tree()
{
    clear(root);
}

template<typename Item>
binary_search_tree<Item>::binary_search_tree(const binary_search_tree& rhs)
{
    root = NULL;
    *this = rhs;
}

template<typename Item>
const binary_search_tree<Item>& binary_search_tree<Item>::operator=(const binary_search_tree& rhs)
{
    if (this == &rhs)
        return *this; // check for self-assignment
    clear(root); // clear current tree
    root = copy(rhs.root); // copy rhs's tree
    return *this;
}

template<typename Item>
void binary_search_tree<Item>::print()
{
    print(root, 1);
}

template<typename Item>
void binary_search_tree<Item>::insert(const Item& x)
{
    insert(x, root);
}

template<typename Item>
void binary_search_tree<Item>::remove(const Item& x)
{
    remove(x, root);
}

template<typename Item>
bool binary_search_tree<Item>::contains(const Item& x)
{
    return contains(x, root);
}

template<typename Item>
int binary_search_tree<Item>::size()
{
    return size(root);
}

template<typename Item>
int binary_search_tree<Item>::height()
{
    return height(root);
}

template<typename Item>
void binary_search_tree<Item>::list2tree(node<Item>* list1_ptr)
{
    cout << "in" << endl;
    std::size_t median(list_length(list1_ptr)/2);
    node<Item>* list2_ptr;

    node<Item>* cursor = list1_ptr;
    for (std::size_t i = 0; i < list_length(list1_ptr); i++)
    {
        if (i == median - 1)
            cursor->set_link(NULL);
        if (i == median)
            insert(cursor->data());
        if (i == median + 1)
            list2_ptr = cursor;
        cursor = cursor->link();
    }


    if (list1_ptr->link() == NULL)
    {
        new binary_tree_node<Item>(list1_ptr->data());
        return;
    }
    else
    {
        list2tree(list1_ptr);
        list2tree(list2_ptr);
    }

    //    if (node_ptr == NULL)
    //        node_ptr = new binary_tree_node<Item>(x);
    //    else if (x < node_ptr->data())
    //        insert(x, node_ptr->left());
    //    else if (x > node_ptr->data())
    //        insert(x, node_ptr->right());
    //    return;

}



// Midterm #2, 1)

//template <class Item>
//void binary_search_tree<Item>::remove(const Item& a)
//{
//    remove(root, a);
//}

//template <class Item>
//void binary_search_tree<Item>::remove(binary_tree_node<Item>* ptr, const Item& a)
//{
//    if (ptr == NULL)
//        return;

//    if (a > ptr->data())
//        remove(ptr->right(), a);
//    else if (a < ptr->data())
//        remove(ptr->left(), a);
//    else if (ptr->left() != NULL && ptr->right() != NULL)
//    {
//        ptr->data() = findMin(ptr->right())->data();
//        remove(ptr->right(), ptr->data());
//    }
//    else
//    {
//        binary_tree_node<Item>* prev_ptr = ptr;
//        if (ptr->left() != NULL)
//            ptr = ptr->left();
//        else
//            ptr = ptr->right();
//        delete prev_ptr;
//    }

//}

//template <class Item>
//binary_tree_node<Item>* binary_search_tree<Item>::findMin(binary_tree_node<Item>* a)
//{
//    if (a == NULL)
//        return;
//    if (a->left() == NULL)
//        return a;
//    return findMin(a->left());
//}


template<typename Item>
int binary_search_tree<Item>::longestPath()
{
    return longestPath(root);
}

template<typename Item>
int binary_search_tree<Item>::longestPath(binary_tree_node<Item>* node_ptr)
{
    if (node_ptr == NULL)
        return 0;
    // The longest path is either
    //   1) the one going through the node (tLP)
    //   2) in the node’s left subtree     (lLP)
    //   3) in the node’s right subtree    (rLP)
    int lpath = height(node_ptr->left());
    int rpath = height(node_ptr->right());
    int tLP = lpath + rpath + 1;
    int lLP = longestPath(node_ptr->left());
    int rLP = longestPath(node_ptr->right());

    cout << "lpath " << lpath << ". " << "rpath " << rpath << ". " << "tLP " << tLP << ". " << "lLP " << lLP << ". " << "rLP " << rLP << ". " << endl;

    if (lLP > rLP)
    {
        if (tLP > lLP)
            return tLP;
        else
            return lLP;
    }
    else
    {
        if (tLP > rLP)
            return tLP;
        else
            return rLP;
    }

}







