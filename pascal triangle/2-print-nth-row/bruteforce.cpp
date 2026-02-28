/*
Problem 2: Print any N-th row of Pascal's Triangle (Brute Force)

Assumption: N is 1-based row number.
Brute Force Idea:
- Build full Pascal's Triangle up to row N.
- Print row N.

Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> nthRowBruteforce(int n) {
    if (n <= 0) {
        return {};
    }

    vector<vector<long long>> triangle;
    triangle.reserve(n);

    for (int i = 0; i < n; i++) {
        vector<long long> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle[n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<long long> row = nthRowBruteforce(n);
    for (long long value : row) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
