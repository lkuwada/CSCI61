#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

///// VECTOR ////////////
//template <class Object>
//void merge(vector<Object>& a, vector<Object>& b, int lp, int rp, int re);
//template <class Object>
//void mergeSort(vector<Object>& a, vector<Object>& b, int left, int right);
//template <class Object>
//void mergeSort(vector<Object>& a);
/////////////////////////

template <class Item>
void merge(node<Item>*& a, node<Item>*& b, node<Item>*& lp, node<Item>*& le, node<Item>*& rp, node<Item>*& re);

template <class Item>
void mergeSort(node<Item>*& a, node<Item>*& b, node<Item>*& left, node<Item>*& right);

template <class Item>
void mergeSort(node<Item>*& a);

int main()
{
    node<int>* a;
    list_head_insert(a, 88);
    list_head_insert(a, 19);
    list_head_insert(a, 56);
    list_head_insert(a, 307);
    list_head_insert(a, 2);
    list_head_insert(a, 35);
    //list_head_insert(a, 40);

    for(node<int>* cursor = a; cursor !=NULL; cursor = cursor->link())
        cout << cursor->data() << endl;

    mergeSort(a);

    for(node<int>* cursor = a; cursor !=NULL; cursor = cursor->link())
        cout << cursor->data() << endl;

    //    vector<int> a;
    //    a.push_back(88);
    //    a.push_back(19);
    //    a.push_back(56);
    //    a.push_back(307);
    //    a.push_back(2);
    //    a.push_back(35);

    //    for (int i = 0; i < a.size(); i++)
    //        cout << a[i] << endl;

    //    mergeSort(a);

    //    cout << "\n" << endl;

    //    for (int i = 0; i < a.size(); i++)
    //        cout << a[i] << endl;

    return 0;
}

//template <class Item>
//void merge(node<Item>*& a, node<Item>*& b, node<Item>*& lp, node<Item>*& rp, node<Item>*& re)
//{
//    cout << "merge" << endl;
//    // a is the head ptr to the list data
//    // b is a temporary head ptr
//    // lp is the ptr to the left sub-list
//    // le is the ptr to the end of the left sub-list
//    // rp is the ptr to the right sub-list
//    // re is the ptr to the end of the right sub-list
//    size_t numElements = list_length(a);
//    node<Item>* b_lp = lp; node<Item>* b_re = re;
//    // main loop
//    while (lp != le && rp != re)
//    {
//        if (lp->data() <= rp->data())
//        {
//            list_insert(b_lp, lp->data());
//            lp = lp->link();
//        }
//        else
//        {
//            list_insert(b_lp, rp->data());
//            rp = rp->link();
//        }
//    }
//    // copy rest of first half
//    while (lp != le)
//    {
//        list_insert(b_lp, lp->data());
//        lp = lp->link();
//    }
//    cout << "mid merge" << endl;
//    // copy rest of right half
//    while (rp != re)
//    {
//        list_insert(b_lp, rp->data());
//        rp = rp->link();
//    }
//    // copy b back
//    list_copy(a, b_lp, b_re);
//    list_clear(b_lp);
//    cout << "end merge" << endl;
//}

template <class Item>
//void merge(node<Item>*& a, node<Item>*& b, node<Item>*& l_ptr, node<Item>*& le_ptr, node<Item>*& r_ptr, node<Item>*& re_ptr, int lp, int rp, int re)
void merge(node<Item>* a, node<Itme>* b, node<Item>* left, node<Item>* l_end, node<Item>* right, node<Item>* r_end)
{
    //cout << "merge" << endl;
    // a is the head ptr to the list data
    // b is a temporary head ptr
    // lp is the ptr to the left sub-list
    // rp is the ptr to the right sub-list
    // re is the ptr to the end of the right sub-list
    size_t le = rp - 1;
    size_t tp = lp;
    size_t numElements = re - lp + 1;
    // main loop
    while (lp <= le && rp <= re)
    {
        if (l_ptr->data() <= r_ptr->data())
        {
            list_head_insert(b, l_ptr->data());
            tp++; lp++;
        }
        else
        {
            list_head_insert(b, r_ptr->data());
            tp++; rp++;
        }
    }

    // copy rest of first half
    while (lp <= le)
    {
        list_head_insert(b, l_ptr->data());
        tp++; lp++;
    }

    // copy rest of right half
    while (rp <= re)
    {
        list_head_insert(b, r_ptr->data());
        tp++; rp++;
    }

    // copy b back
    list_copy(a, b, re_ptr);

    //list_clear(b);
}

template <class Item>
void mergeSort(node<Item>*& a, node<Item>*& b, node<Item>*& left, node<Item>*& right)
{
    //cout << "mS" << endl;
    // a is the head ptr to the list of data
    // b is a temporary ptr
    // left is the ptr to the front of list 'a'
    // right is the ptr to the end of list 'a'

    if (list_length(left) > 0 && list_length(right) > 0)
    {
        //node<Item>* middle;
        //node<Item>* l_begin = a;
        node<Item>* l_end;
        node<Item>* r_begin;
        //node<Item>* r_end = right;
        size_t counter(0);
        for (node<Item>* cursor = a; cursor != NULL; cursor = cursor->link())
        {
            //cout << counter << ", " << middle << endl;
            if (counter == (list_length(a)/2) - 1)
                l_end = cursor;
            if (counter == (list_length(a)/2))
            {
                r_begin = cursor->link();
                center = cursor;
            }
            counter++;
        }
        mergeSort(a, b, left, l_end);
        //cout << "mS 1" << endl;
        mergeSort(a, b, r_begin, right);
        //cout << "mS 2" << endl;
        merge(a, b, left, l_end, r_begin, right);
        cout << "merged" << endl;
    }
}

template <class Item>
void mergeSort(node<Item>*& a)
{
    cout << "kickstart" << endl;
    if ((a == NULL) || (list_length(a) == 1))
        return;

    node<Item>* temp;
    node<Item>* left = a;
    node<Item>* right;
    for (node<Item>* cursor = a; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->link() == NULL)
            right = cursor;
    }

    mergeSort (a, temp, left, right);
    cout << "end kickstart" << endl;
}

//template <class Item>
//void mergeSort(node<Item>*& a)
//{
//    cout << "kickstart" << endl;
//    if ((a == NULL) || (list_length(a) == 1))
//        return;
//    node<Item>* tmp;
//    size_t left(0);
//    size_t right = list_length(a) - 1;
//    //    node<Item>* left = a;
//    //    node<Item>* right;
//    //    size_t counter(0);
//    //    for(node<Item>* cursor = a; cursor != NULL; cursor = cursor->link())
//    //    {
//    //        if(list_length(a) - 1 == counter)
//    //            right = cursor;
//    //        counter++;
//    //    }
//    mergeSort(a, tmp, left, right);
//    cout << "end kickstart" << endl;
//}

/*
 * MergeSort.html
 */
///////////////////////////////////////////////////////////////////////////
// M E R G E    S O R T ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//template <class Object>
//void merge(vector<Object>& a, vector<Object>& b, int lp, int rp, int re) {
//    // a is the list data
//    // b is a temporary vector
//    // lp is the first index of the left sub-list (last index of the left sub-list is rp-1)
//    // rp is the first index of the right sub-list
//    // re is the last index of the right sub-list
//    int le = rp - 1;
//    int tp = lp;
//    int numElements = re - lp + 1;
//    // main loop
//    while (lp <= le && rp <= re)
//        if (a[lp] <= a[rp]) b[tp++] = a[lp++];
//        else b[tp++] = a[rp++];
//    // copy rest of first half
//    while (lp <= le) b[tp++] = a[lp++];
//    // copy rest of right half
//    while (rp <= re) b[tp++] = a[rp++];
//    // copy b back
//    for (int i = 0; i < numElements; i++, re--) a[re] = b[re];
//}
//template <class Object>
//void mergeSort(vector<Object>& a, vector<Object>& b, int left, int right) {
//    // a is the list of data
//    // b is a temporary vector
//    // left is the first index of the list 'a'
//    // right is the last index of the list 'a'
//    if (left < right) {
//        int center = (left + right) / 2;
//        mergeSort(a, b, left, center);
//        mergeSort(a, b, center + 1, right);
//        merge(a, b, left, center + 1, right);
//    }
//}
//template <class Object>
//void mergeSort(vector<Object>& a) {
//    if (a.size() == 1) return;
//    vector<Object> tmp(a.size()); // temporary vector
//    mergeSort(a, tmp, 0, a.size()-1);
//}
///////////////////////////////////////////////////////////////////////////

