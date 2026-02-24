/*
Problem: Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive sequence.
Example: [100, 4, 200, 1, 3, 2] -> Output: 4 (sequence: [1, 2, 3, 4])

Optimal Approach:
Same as better approach - use unordered_set for O(n) average case with optimized logic.

Idea:
- Store all numbers in an unordered_set for O(1) average lookup.
- Only start counting from sequence starts (when num-1 doesn't exist).
- Maximize efficiency by skipping non-start elements.

Approach:
1) Create unordered_set and insert all elements.
2) For each element in original array:
   - Skip if (element - 1) exists (not a sequence start).
   - If not, it's a sequence start.
3) Count consecutive elements from this start.
4) Track and return maximum length.

Time Complexity: O(n) average case - Each element is visited at most twice
Space Complexity: O(n) - For unordered_set storage
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveOptimal(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : numSet) {
        if (numSet.count(num - 1) == 0) {
            int currentNum = num;
            int currentLen = 1;

            while (numSet.count(currentNum + 1)) {
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

    int ans = longestConsecutiveOptimal(nums);
    cout << ans << '\n';

    return 0;
}
