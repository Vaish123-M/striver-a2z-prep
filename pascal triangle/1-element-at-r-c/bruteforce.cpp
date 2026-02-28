/*
Problem 1: Given R and C, find element at (R, C) in Pascal's Triangle (Brute Force)

Assumption: R and C are 1-based indices.
Brute Force Idea:
- Build Pascal's Triangle up to row R.
- Return value at triangle[R - 1][C - 1].

Time Complexity: O(R^2)
Space Complexity: O(R^2)
*/

#include <bits/stdc++.h>
using namespace std;

long long elementAtRCBruteforce(int r, int c) {
    if (r <= 0 || c <= 0 || c > r) {
        return 0;
    }

    vector<vector<long long>> triangle;
    triangle.reserve(r);

    for (int i = 0; i < r; i++) {
        vector<long long> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle[r - 1][c - 1];
}

int main() {
    int r, c;
    cin >> r >> c;

    cout << elementAtRCBruteforce(r, c) << '\n';
    return 0;
}
