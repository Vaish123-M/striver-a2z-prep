/*
Problem: Set Matrix Zeroes
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place.

Bruteforce Approach:
Use a separate data structure to mark which rows and columns should be zeroed.

Idea:
- Store row and column indices that contain 0 in separate sets.
- Traverse the matrix again and set elements to 0 if their row or column is marked.
- Modification is done in-place.

Approach:
1) Create two sets: one for rows and one for columns.
2) First pass: Iterate through matrix, whenever we find 0, add its row and column to respective sets.
3) Second pass: Iterate through matrix and set matrix[i][j] = 0 if i is in row set or j is in column set.

Time Complexity: O(m * n)
Space Complexity: O(m + n) for storing row and column indices
*/

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroesBruteforce(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();

    set<int> rows, cols;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows.count(i) || cols.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    setMatrixZeroesBruteforce(matrix);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
