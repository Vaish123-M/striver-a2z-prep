/*
Problem: Count Subarray Sum Equals K (Brute Force)

Given an array and an integer k, count the number of contiguous subarrays
whose sum equals k.

Brute Force Idea:
- Generate all subarrays using two loops.
- Keep a running sum from i to j.
- If running sum equals k, increase count.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int countSubarraysBruteforce(const vector<int>& arr, int k) {
    int n = (int)arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << countSubarraysBruteforce(arr, k) << '\n';
    return 0;
}
