/*
Problem 1: Given R and C, find element at (R, C) in Pascal's Triangle (Better)

Assumption: R and C are 1-based indices.
Better Idea:
- Generate only the R-th row using iterative relation.
- Return the C-th element from that row.

Time Complexity: O(R)
Space Complexity: O(R)
*/

#include <bits/stdc++.h>
using namespace std;

long long elementAtRCBetter(int r, int c) {
    if (r <= 0 || c <= 0 || c > r) {
        return 0;
    }

    vector<long long> row;
    row.reserve(r);

    long long value = 1;
    row.push_back(value);

    for (int col = 1; col < r; col++) {
        value = value * (r - col) / col;
        row.push_back(value);
    }

    return row[c - 1];
}

int main() {
    int r, c;
    cin >> r >> c;

    cout << elementAtRCBetter(r, c) << '\n';
    return 0;
}
