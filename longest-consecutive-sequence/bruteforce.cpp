/*
Problem: Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive sequence.
Example: [100, 4, 200, 1, 3, 2] -> Output: 4 (sequence: [1, 2, 3, 4])

Bruteforce Approach:
Sort the array and then traverse to find consecutive sequences.

Idea:
- Sort the entire array.
- Iterate through sorted array to find longest consecutive sequence.
- Track current sequence length and maximum length.

Approach:
1) Sort the array in ascending order.
2) Traverse the sorted array.
3) For each element, check if it forms a consecutive sequence with the next element.
4) If arr[i+1] == arr[i] + 1, increment sequence length.
5) Update max length if current sequence is longer.
6) Reset sequence length if gap is found (handle duplicates with == check).

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) if we ignore sorting space, otherwise O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveBruteforce(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int maxLen = 1, currentLen = 1;

    for (int i = 0; i < (int)nums.size() - 1; i++) {
        if (nums[i + 1] == nums[i] + 1) {
            currentLen++;
        } else if (nums[i + 1] != nums[i]) {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
        }
    }

    maxLen = max(maxLen, currentLen);
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = longestConsecutiveBruteforce(nums);
    cout << ans << '\n';

    return 0;
}
