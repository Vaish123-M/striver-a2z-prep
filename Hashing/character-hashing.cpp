/*
====================================================
CHARACTER HASHING (LOWERCASE LETTERS)
====================================================

Idea:
Store frequency of each character.

'a' -> index 0
'b' -> index 1
'c' -> index 2
...
'z' -> index 25

Formula:
index = character - 'a'

Example:
aabcc

Frequency:
a -> 2
b -> 1
c -> 2

Time:
Pre-computation : O(N)
Query Answering : O(1)

====================================================
*/

#include <iostream>
using namespace std;

int main()
{
    string str;

    cout << "Enter String: ";
    cin >> str;

    // Hash array stores frequency of 26 lowercase letters
    int freq[26] = {0};

    // Count frequency of each character
    for(int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        freq[index]++;
    }

    int q;

    cout << "Enter Number of Queries: ";
    cin >> q;

    while(q--)
    {
        char ch;

        cout << "Enter Character: ";
        cin >> ch;

        // Directly print frequency
        cout << "Frequency = "
             << freq[ch - 'a']
             << endl;
    }

    return 0;
}