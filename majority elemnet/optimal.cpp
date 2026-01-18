/*
Problem: Majority Element (> n/2 occurrences in an array) — report element or -1 if none.
Approach: Optimal Moore's Voting; track candidate and counter (increment on same, decrement on different), then verify candidate count.
Idea: Pairwise cancellation removes non-majority elements; only a true majority can survive the pass.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElementMoore(const vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int x : nums) {
        if (count == 0) {
            candidate = x;
            count = 1;
        } else if (x == candidate) {
            ++count;
        } else {
            --count;
        }
    }
    // Verify candidate to handle no-majority cases.
    count = 0;
    for (int x : nums) if (x == candidate) ++count;
    return (count > static_cast<int>(nums.size()) / 2) ? candidate : -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 2, 3, 2, 2};
    cout << majorityElementMoore(nums) << "\n";
    return 0;
}
