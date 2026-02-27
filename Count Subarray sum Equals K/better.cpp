/*
Problem: Count Subarray Sum Equals K (Better)

Better Idea:
- Build prefix sum array where prefix[i] = sum of first i elements.
- Sum of subarray [i..j] = prefix[j + 1] - prefix[i].
- Check all (i, j) pairs in O(n^2).

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int countSubarraysBetter(const vector<int>& arr, int k) {
    int n = (int)arr.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long subarraySum = prefix[j + 1] - prefix[i];
            if (subarraySum == k) {
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

    cout << countSubarraysBetter(arr, k) << '\n';
    return 0;
}
