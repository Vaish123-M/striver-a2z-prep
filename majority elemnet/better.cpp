/*
Problem: Majority Element (> n/2 occurrences in an array) — report element or -1 if none.
Approach: Better via hashmap; single pass to count frequencies, then find any key with count > n/2.
Idea: Trade O(n) extra space to get linear time counting.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElementBetter(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    int n = static_cast<int>(nums.size());
    for (const auto& entry : freq) {
        int val = entry.first;
        int count = entry.second;
        if (count > n / 2) return val;
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 2, 3, 2, 2};
    cout << majorityElementBetter(nums) << "\n";
    return 0;
}
