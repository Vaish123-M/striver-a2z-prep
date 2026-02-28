/*
Problem 3: Given N, print entire Pascal's Triangle (Optimal)

Optimal Idea:
- Build each row in O(row) using previous value relation.
- Total complexity becomes O(N^2).

Time Complexity: O(N^2)
Space Complexity: O(1) extra
*/

#include <bits/stdc++.h>
using namespace std;

void printTriangleOptimal(int n) {
    for (int row = 1; row <= n; row++) {
        long long value = 1;
        cout << value << ' ';

        for (int col = 1; col < row; col++) {
            value = value * (row - col) / col;
            cout << value << ' ';
        }

        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    printTriangleOptimal(n);
    return 0;
}
