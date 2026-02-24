/*
Problem:
Given an array nums of size n representing a permutation, rearrange it into the lexicographically next greater permutation.
If such arrangement is not possible, rearrange it into the lowest possible order (sorted in ascending order).

Better Solution (Library Based):
Use C++ STL function next_permutation.

Idea:
- STL already implements the next permutation logic efficiently.
- If next permutation does not exist, it transforms array into smallest permutation.

Approach:
1) Read array.
2) Call next_permutation(nums.begin(), nums.end()).
3) Print resulting array.

Time Complexity:
- next_permutation runs in O(n)

Space Complexity:
- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutationBetter(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    nextPermutationBetter(nums);

    for (int x : nums) cout << x << " ";
    cout << '\n';

    return 0;
}
