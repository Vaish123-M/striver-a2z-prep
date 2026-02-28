/*
Problem 1: Given R and C, find element at (R, C) in Pascal's Triangle (Optimal)

Assumption: R and C are 1-based indices.
Optimal Idea:
- Directly use combination formula:
  element = C(r - 1, c - 1)
- Compute nCr iteratively to avoid factorial overflow as much as possible.

Time Complexity: O(min(c, r - c))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) {
        return 0;
    }

    r = min(r, n - r);
    long long result = 1;

    for (long long i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }

    return result;
}

long long elementAtRCOptimal(int r, int c) {
    if (r <= 0 || c <= 0 || c > r) {
        return 0;
    }

    return nCr(r - 1, c - 1);
}

int main() {
    int r, c;
    cin >> r >> c;

    cout << elementAtRCOptimal(r, c) << '\n';
    return 0;
}
