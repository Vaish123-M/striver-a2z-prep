/*
Problem 3: Given N, print entire Pascal's Triangle (Better)

Better Idea:
- For every row and column, compute nCr with iterative multiplication.
- Better than factorial approach, but still repeated work per element.

Time Complexity: ~O(N^3)
Space Complexity: O(1) extra
*/

#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }

    r = min(r, n - r);
    long long result = 1;

    for (int i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }

    return result;
}

void printTriangleBetter(int n) {
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            cout << nCr(row - 1, col - 1) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    printTriangleBetter(n);
    return 0;
}
