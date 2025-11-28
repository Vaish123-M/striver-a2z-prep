#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0)      // base case
        return 1;
    return n * factorial(n - 1);   // recursive call
}

int main() {
    cout << factorial(5);   // Output: 120
    return 0;
}
