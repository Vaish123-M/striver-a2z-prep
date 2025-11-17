/*
------------------------------------------------------------
1) Print a name N number of times using recursion
------------------------------------------------------------
Logic:
- Function takes current count (i) and total N.
- Base case: if i > N, stop recursion.
- Otherwise: print name, then call function again with i+1.
*/
#include <iostream>
using namespace std;

void printName(int i, int N) {
    // First thing read: check base condition
    if (i > N) return; // recursion stops here
    
    cout << "Vaishnavi" << endl; // action at each step
    
    // Recursive call: goes deeper until i > N
    printName(i + 1, N);
}

int main() {
    int N;
    // Read number of times to print the name
    if (!(cin >> N)) return 0;

    // start recursion from 1
    printName(1, N);
    return 0;
}

