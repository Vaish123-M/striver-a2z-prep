/*
Problem: Rotate Matrix/Image by 90 Degrees (Clockwise)
Given an n x n matrix, rotate it by 90 degrees clockwise.

Bruteforce Approach:
Use an extra matrix to place each element at its rotated position.

Idea:
- For clockwise rotation, element at (i, j) moves to (j, n - 1 - i).
- Create a temporary matrix and fill rotated positions.
- Copy back the temporary matrix to original matrix.

Approach:
1) Create temp matrix of size n x n.
2) Traverse original matrix and place each element using:
   temp[j][n - 1 - i] = matrix[i][j]
3) Assign temp back to matrix.

Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/

#include <bits/stdc++.h>
using namespace std;

void rotateMatrixBruteforce(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    vector<vector<int>> temp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = temp;
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

    rotateMatrixBruteforce(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
