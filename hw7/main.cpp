//// FILE: search.cxx
//// Demonstration program for the binary search function

#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <iostream>   // Provides cin, cout
using namespace std;

//template <class Item>
//void search(const Item a[ ], size_t first, size_t size, Item& target, bool& found, size_t& location);
//// Precondition: The array segment starting at a[first] and containing size
////                  elements is sorted from smallest to largest.
//// Postcondition: The array segment starting at a[first] and containing size
////                  elements has been searched for the target. If the target was present, then
////                  found is true, and location is set so that target == a[location];
////                  Otherwise, found is set to false.
//// Library facilities used: stdlib.h (provides size_t).

//int main( )
//{
//    const size_t MANY = 10;
//    int fibonacci[MANY] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
//    int target;
//    bool found;
//    size_t location;

//    do
//    {
//        cout << "Please type an integer from 0 to 100: ";
//        cin >> target;
//    }
//    while ((target < 0) || (target > 100));
//    search(fibonacci, 0, MANY, target, found, location);

//    if (found)
//        cout << target << " is a Fibonacci number at ["
//             << location << "] in my array." << endl;
//    else
//        cout << target << " is not a Fibonacci number." << endl;

//    return EXIT_SUCCESS;
//}

////void search(const int a[ ], size_t first, size_t size, int target, bool& found, size_t& location)
////{
////    size_t middle;

////    if (size == 0)
////        found = false;
////    else
////    {
////        middle = first + size/2;
////        if (target == a[middle])
////        {
////            location = middle;
////            found = true;
////        }
////        else if (target < a[middle])
////            // The target is less than a[middle], so search before the middle
////            search(a, first, size/2, target, found, location);
////        else
////            // The target must be greater than a[middle], so search after the middle
////            search(a, middle+1, (size-1)/2, target, found, location);
////    }
////}

//template <class Item>
//void search(const Item a[ ], size_t first, size_t size, Item& target, bool& found, size_t& location)
//{
//    size_t middle;

//    if (size == 0)
//    {
//        found = false;
//        return;
//    }

//    while (size > 0)
//    {
//        middle = first + size/2;
//        if (target == a[middle])
//        {
//            location = middle;
//            found = true;
//            return;
//        }
//        else if (target < a[middle])
//        {
//            size = size/2;
//        }
//        else
//        {
//            first = middle + 1;
//            size = (size - 1)/2;
//        }

//    } //while

//    found = false;
//    return;
//}
// FILE: guess.cxx
// Demostrates a guessing game function that's used as a time analysis example.

//#include <cassert>         // Provides assert
//#include <iostream>        // Provides cout and cin
//#include <cstdlib>         // Provides EXIT_SUCCESS
//using namespace std;       // Allows all Standard Library items to be used

//// Prototype for the function used in this demonstration program
//void guess_game(int n);
//// Precondition: n > 0.
//// Postcondition: The user has been asked to think of a number between 1 and n.
//// The function asks a series of questions, until the number is found.


//int main( )
//{
//    guess_game(100);
//    return EXIT_SUCCESS;
//}

//void guess_game(int n)
//// Library facilities used: cassert, iostream
//{
//    int guess;
//    char answer;

//    assert(n >= 1);

//    cout << "Think of a whole number from 1 to " << n << "." << endl;
//    answer = 'N';
//    for (guess = n; (guess > 0) && (answer != 'Y') && (answer != 'y'); --guess)
//    {
//        cout << "Is your number " << guess << "?" << endl;
//        cout << "Please answer Y or N, and press return: ";
//        cin >> answer;
//    }

//    if ((answer == 'Y') || (answer == 'y'))
//        cout << "I knew it all along." << endl;
//    else
//        cout << "I think you are cheating!" << endl;
//}


void binary_search_game(const int a[ ], size_t first, size_t size, int guess, bool& found, size_t& location);

int main( )
{
    const size_t size = 100;
    int guess[size];
//    for (size_t i = 0; i < size; i++)
//        guess[i] = i;

    int target;
    bool found;
    size_t location;

//    cout << "Enter the number you want the computer to guess: " << endl;
//    cin >> target;

    binary_search_game(guess, 0, size, target, found, location);
}

void binary_search_game(const int a[ ], size_t first, size_t size, int guess, bool& found, size_t& location)
{
    char answer = 'N';
    size_t middle;

    if(size == 0)
        found = false;
    else
    {
        middle = first + size/2;
        if(guess == a[middle]) // The target
        {
            cout << "Is your number " << a[middle] << "? ";
            cin >> answer;
            if((answer == 'y') || (answer == 'Y'))
            {
                location = middle;
                found = true;
                cout << "I knew it all along!" << endl;
            }
        }
        else
        {
            cout << "Is your number higher than " << a[middle] << "? ";
            cin >> answer;
            if((answer == 'y') || (answer == 'Y'))
                binary_search_game(a, middle+1, (size-1)/2, guess,found, location);
            else if ((answer == 'n') || (answer == 'N'))
                binary_search_game(a, first, size/2, guess,found, location);
        }
    }
//}

//void binary_search_game(const int a[ ], size_t first, size_t size, int guess, bool& found, size_t& location)
//{
//    first = 0;
//    size = 100;
//    char answer = 'N';
//    size_t middle;

//    cout << "Enter a number: " << endl;
//    cin >> guess;

//    if(size == 0)
//        found = false;
//    else
//    {
//        middle = first + size/2;
//        if(guess == a[middle]) // The target
//        {
//            cout << "Is this your number?";
//            cin >> answer;
//            if((answer == 'y') || (answer == 'Y'))
//            location = middle;
//            found = true;
//        }
//        else if (guess < a[middle]) // The target is less than a[middle], so search before the middle
//        {
//            cout << "Is your number lower than this?";
//            cin >> answer;
//            if((answer == 'y') || (answer == 'Y'))
//            binary_search_game(a, first, size/2, guess,found, location);
//        }
//        else // The target must be greater than a[middle], so search after the middle
//        {
//            cout << "Is your number higher than this?";
//            cin >> answer;
//            if((answer == 'y') || (answer == 'Y'))
//            binary_search_game(a, middle+1, (size-1)/2, guess,found, location);
//        }
//    }
//}

