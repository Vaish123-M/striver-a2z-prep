/*
Problem: Count Subarray Sum Equals K (Optimal)

Optimal Idea: Prefix Sum + Hash Map
- Let current prefix sum be pref.
- If (pref - k) has appeared before, then each occurrence gives one valid subarray.
- Store frequency of each prefix sum in unordered_map.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int countSubarraysOptimal(const vector<int>& arr, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;

    long long prefixSum = 0;
    int count = 0;

    for (int value : arr) {
        prefixSum += value;

        long long need = prefixSum - k;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }

        freq[prefixSum]++;
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

    cout << countSubarraysOptimal(arr, k) << '\n';
    return 0;
}
