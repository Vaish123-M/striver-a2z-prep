/*
5) Print from N to 1 (By Backtracking)
------------------------------------------------------------
Logic:
- Function takes current number (i).
- Base case: if i > N, stop recursion.
- First: recursive call goes all the way up to N.
- Then: while returning (backtracking), print i.
*/

#include <iostream>
using namespace std;

/* Print numbers from N down to 1 using backtracking */
void printNto1Backtrack(int i, int N) {
    if (i > N) return;           // Stop when i > N
    printNto1Backtrack(i + 1, N);// Go deeper first
    cout << i << " ";            // Print while coming back
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "\n5) Print from N to 1 (Backtrack):\n";
    printNto1Backtrack(1, N);

    return 0;
}