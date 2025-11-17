/*
-------------------------------------------------------
2) Print linearly from 1 to N
------------------------------------------------------------
Logic:
- Function takes current number (i).
- Base case: if i > N, stop recursion.
- Otherwise: print i, then call function with i+1.
*/
#include <iostream>
using namespace std;

/* Print numbers from 1 to N using recursion */
void print1toN(int i, int N) {
    if (i > N) return;           // Stop when i exceeds N
    cout << i << " ";            // Print current number
    print1toN(i + 1, N);         // Recursive call → goes forward
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "\n2) Print linearly from 1 to N:\n";
    print1toN(1, N);

    return 0;
}