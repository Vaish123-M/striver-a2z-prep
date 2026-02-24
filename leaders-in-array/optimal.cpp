/*
Problem: Leaders in Array
Given an array of integers, print all leader elements.
An element is called a leader if it is greater than all elements to its right.
The rightmost element is always a leader.

Optimal Approach:
Traverse from right to left while maintaining the maximum element seen so far.
If current element is greater than maxSoFar, it is a leader.
Reverse collected leaders at the end to preserve original left-to-right order.

Time Complexity: O(n)
Space Complexity: O(n) (for storing leaders)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> leadersOptimal(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> leaders;

    int maxSoFar = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > maxSoFar) {
            leaders.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = leadersOptimal(arr);

    for (int x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}
