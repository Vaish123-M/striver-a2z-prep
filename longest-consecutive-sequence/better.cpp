/*
Problem: Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive sequence.
Example: [100, 4, 200, 1, 3, 2] -> Output: 4 (sequence: [1, 2, 3, 4])

Better Approach:
Use a set to store all array elements, then iterate through array and find consecutive sequences.

Idea:
- Insert all array elements into a set.
- For each element, check if it's the start of a sequence (previous element not in set).
- If start found, count consecutive elements using the set.

Approach:
1) Create a set and insert all array elements.
2) Traverse the array.
3) For each element, check if (element - 1) exists in the set.
4) If not, it's the start of a new sequence.
5) Count consecutive elements starting from current element.
6) Track maximum sequence length.

Time Complexity: O(n) - Each element is visited at most twice
Space Complexity: O(n) - For storing elements in set
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveBetter(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : nums) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLen = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLen++;
            }

            maxLen = max(maxLen, currentLen);
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = longestConsecutiveBetter(nums);
    cout << ans << '\n';

    return 0;
}
