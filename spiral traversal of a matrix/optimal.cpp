/*
Problem: Spiral Traversal of a Matrix
Given an m x n matrix, return its elements in spiral order.

Optimal Approach:
Use four boundaries and traverse layer by layer.

Idea:
- Maintain top, bottom, left, right boundaries.
- Traverse in order: left to right (top row), top to bottom (right column),
  right to left (bottom row), bottom to top (left column).
- Shrink boundaries after each pass.

Approach:
1) Initialize top = 0, bottom = m - 1, left = 0, right = n - 1.
2) While top <= bottom and left <= right:
   - Traverse top row from left to right, then increment top.
   - Traverse right column from top to bottom, then decrement right.
   - If top <= bottom, traverse bottom row from right to left, then decrement bottom.
   - If left <= right, traverse left column from bottom to top, then increment left.
3) Collect elements in a result vector and print them.

Time Complexity: O(m * n)
Space Complexity: O(1) extra (excluding output vector)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraversalOptimal(const vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    vector<int> result;
    result.reserve(m * n);

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
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

    vector<int> result = spiralTraversalOptimal(matrix);

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i + 1 < (int)result.size()) cout << " ";
    }
    cout << '\n';

    return 0;
}
