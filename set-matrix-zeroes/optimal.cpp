/*
Problem: Set Matrix Zeroes
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place.

Optimal Approach:
Space-optimized version using first row and column as markers with a single variable for first column.

Idea:
- Use matrix[i][0] to mark if row i should be zeroed.
- Use matrix[0][j] to mark if column j should be zeroed.
- Use a single variable to track if first column needs zeroing.
- This avoids using O(m + n) extra space.

Approach:
1) Determine if first row and first column need to be zeroed.
2) Use matrix[i][0] and matrix[0][j] as row and column markers.
3) Iterate through matrix (skip first row/column) and mark accordingly.
4) Use markers to set elements to 0.
5) Apply special handling for first row and first column.

Time Complexity: O(m * n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroesOptimal(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    bool firstColZero = false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) firstColZero = true;

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }

        if (firstColZero) matrix[i][0] = 0;
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

    setMatrixZeroesOptimal(matrix);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
