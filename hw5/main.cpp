// FILE: pal.cxx
// Program to test whether an input line is a palindrome. Spaces,
// punctuation, and the difference between upper- and lowercase are ignored.

#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        string ans;
        cout << "What would you like to do? \n1.Check for a word-by-word palindrome \n2.Quit the program" << endl;
        cin >> ans;

        if (ans == "1")
        {
            queue<string> q;
            stack<string> s;
            string word;
            queue<string>::size_type mismatches = 0;

            cout << "Enter a line and I will see if it's a word-by-word palindrome: " << endl;
            getline(cin, word);

            while (cin.peek() != '\n')
            {
                cin >> word;
                string temp;
                for (queue<string>::size_type i = 0; i < word.length(); i++)
                {
                    if (isalpha(word[i]))
                        temp.push_back(toupper(word[i]));
                }
                q.push(temp);
                s.push(temp);
            }

            while ((!q.empty()) && (!s.empty()))
            {
                if (q.front() != s.top())
                {
                    ++mismatches;
                }
                q.pop();
                s.pop();
            }

            if (mismatches == 0)
                cout << "That is a word-by-word palindrome.\n" << endl;
            else
                cout << "That is NOT a word-by-word palindrome.\n" << endl;
        }
        else if (ans == "2")
            return EXIT_SUCCESS;
    }
}
