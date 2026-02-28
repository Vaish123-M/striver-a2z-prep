/*
Problem 2: Print any N-th row of Pascal's Triangle (Better)

Assumption: N is 1-based row number.
Better Idea:
- For each position c in row n, compute C(n-1, c-1) independently.

Time Complexity: O(N^2)
Space Complexity: O(1) extra (excluding output row)
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

vector<long long> nthRowBetter(int n) {
    if (n <= 0) {
        return {};
    }

    vector<long long> row;
    row.reserve(n);

    for (int c = 1; c <= n; c++) {
        row.push_back(nCr(n - 1, c - 1));
    }

    return row;
}

int main() {
    int n;
    cin >> n;

    vector<long long> row = nthRowBetter(n);
    for (long long value : row) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
