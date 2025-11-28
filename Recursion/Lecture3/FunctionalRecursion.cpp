//Functional Recursion

#include <iostream>
using namespace std;

// Functional recursion to calculate sum of first N numbers
int sum(int n) {

    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return 0;

    // Recursive case:
    // sum(n) = n + sum(n-1)
    // Function returns n PLUS the sum of previous numbers
    return n + sum(n - 1);
}

int main() {
    int n = 5;
    cout << "Sum of first " << n << " numbers = " << sum(n);
    return 0;
}
