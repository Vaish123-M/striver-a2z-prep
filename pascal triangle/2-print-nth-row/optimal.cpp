/*
Problem 2: Print any N-th row of Pascal's Triangle (Optimal)

Assumption: N is 1-based row number.
Optimal Idea:
- Start with first value = 1.
- Use relation to get next value from previous value:
  next = prev * (n - col) / col

Time Complexity: O(N)
Space Complexity: O(1) extra (excluding output row)
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> nthRowOptimal(int n) {
    if (n <= 0) {
        return {};
    }

    vector<long long> row;
    row.reserve(n);

    long long value = 1;
    row.push_back(value);

    for (int col = 1; col < n; col++) {
        value = value * (n - col) / col;
        row.push_back(value);
    }

    return row;
}

int main() {
    int n;
    cin >> n;

    vector<long long> row = nthRowOptimal(n);
    for (long long value : row) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
