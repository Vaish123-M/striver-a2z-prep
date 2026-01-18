/*
Problem: Majority Element (> n/2 occurrences in an array) — report element or -1 if none.
Approach: Brute force double loop; for each element, count its occurrences by scanning entire array.
Idea: Validate every candidate directly; stop when a count exceeds n/2.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) ++cnt;
        }
        if (cnt > n / 2) return nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 2, 3, 2, 2};
    cout << majorityElementBrute(nums) << "\n";
    return 0;
}
