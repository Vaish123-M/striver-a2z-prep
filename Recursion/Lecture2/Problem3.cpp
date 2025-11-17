/*
3) Print from N to 1
------------------------------------------------------------
Logic:
- Function takes current number (i).
- Base case: if i < 1, stop recursion.
- Otherwise: print i, then call function with i-1.
*/

#include <iostream>
using namespace std;

/* Print numbers from N down to 1 using recursion */
void printNto1(int i) {
    if (i < 1) return;           // Stop when i goes below 1
    cout << i << " ";            // Print current number
    printNto1(i - 1);            // Recursive call → goes backward
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "\n3) Print from N to 1:\n";
    printNto1(N);

    return 0;
}