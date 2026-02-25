/*
Problem: Rotate Matrix/Image by 90 Degrees (Clockwise)
Given an n x n matrix, rotate it by 90 degrees clockwise.

Optimal Approach:
Rotate the matrix in-place using transpose + reverse each row.

Idea:
- Transpose converts rows to columns.
- Reversing every row after transpose gives 90 degree clockwise rotation.
- No extra matrix is needed.

Approach:
1) Transpose matrix (swap matrix[i][j] with matrix[j][i] for j > i).
2) Reverse each row.

Time Complexity: O(n * n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void rotateMatrixOptimal(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrixOptimal(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
