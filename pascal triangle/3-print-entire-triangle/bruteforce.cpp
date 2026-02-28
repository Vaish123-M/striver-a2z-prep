/*
Problem 3: Given N, print entire Pascal's Triangle (Brute Force)

Brute Force Idea:
- For every element, compute nCr using factorial.
- This repeats many calculations.

Time Complexity: ~O(N^3)
Space Complexity: O(1) extra
*/

#include <bits/stdc++.h>
using namespace std;

long long factorial(int x) {
    long long result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}

long long nCrFactorial(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }

    long long num = factorial(n);
    long long den = factorial(r) * factorial(n - r);
    return num / den;
}

void printTriangleBruteforce(int n) {
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            cout << nCrFactorial(row - 1, col - 1) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    printTriangleBruteforce(n);
    return 0;
}
