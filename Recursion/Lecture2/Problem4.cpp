/*
------------------------------------------------------------
4) Print linearly from 1 to N (By Backtracking)
------------------------------------------------------------
Logic:
- Function takes current number (i).
- Base case: if i < 1, stop recursion.
- First: recursive call goes all the way down to 1.
- Then: while returning (backtracking), print i.
*/

#include <iostream>
using namespace std;

/* Print numbers from 1 to N using backtracking */
void print1toNBacktrack(int i) {
    if (i < 1) return;           // Stop when i < 1
    print1toNBacktrack(i - 1);   // Go deeper first
    cout << i << " ";            // Print while coming back
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "\n4) Print linearly from 1 to N (Backtrack):\n";
    print1toNBacktrack(N);

    return 0;
}