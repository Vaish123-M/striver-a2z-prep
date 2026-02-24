/*
Problem: Set Matrix Zeroes
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place.

Better Approach:
Use first row and first column as markers instead of separate sets.

Idea:
- Use matrix[i][0] and matrix[0][j] as markers.
- Set them to 0 if row i or column j should be zeroed.
- Handle first row and first column separately as they are markers.

Approach:
1) Use two flags: firstRowZero and firstColZero to track if first row/column should be zeroed.
2) First pass: Check if first row/column need to be zeroed, then mark using matrix[i][0] and matrix[0][j].
3) Second pass: Use markers to set elements to 0 (skip first row and column).
4) Third pass: Zero out first row and column based on flags.

Time Complexity: O(m * n)
Space Complexity: O(1) - only two flags used
*/

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroesBetter(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) firstColZero = true;
    }

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) firstRowZero = true;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }

    if (firstColZero) {
        for (int i = 0; i < m; i++) matrix[i][0] = 0;
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

    setMatrixZeroesBetter(matrix);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
