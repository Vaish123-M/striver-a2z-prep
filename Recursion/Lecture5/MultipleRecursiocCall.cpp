// Fibonacci series using multiple recursion calls
#include<iostream>
using namespace std;

int f(int n) {
    // Base case
    if(n <= 1) {
        return n;
    }

    // Recursive calls
    int last = f(n - 1);
    int secondLast = f(n - 2);

    return last + secondLast;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th Fibonacci number is: " << f(n) << endl;

    return 0;
}
// Time complexity: O(2^n)
// Why O(2^n)?
// Each call to f(n) results in two further calls: f(n-1) and