/*
Problem: Leaders in Array
Given an array of integers, print all leader elements.
An element is called a leader if it is greater than all elements to its right.
The rightmost element is always a leader.

Bruteforce Approach:
For each element, check all elements on its right.
If no greater element is found on the right, it is a leader.

Time Complexity: O(n^2)
Space Complexity: O(n) (for storing leaders)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> leadersBruteforce(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> leaders;

    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) leaders.push_back(arr[i]);
    }

    return leaders;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = leadersBruteforce(arr);

    for (int x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}
