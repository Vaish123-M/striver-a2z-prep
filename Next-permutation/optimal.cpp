/*
Problem:
Given an array nums of size n representing a permutation, rearrange it into the lexicographically next greater permutation.
If such arrangement is not possible, rearrange it into the lowest possible order (sorted in ascending order).

Optimal Solution:
Implement the classic in-place next permutation algorithm.

Idea:
To get the immediate next lexicographical permutation:
1) Find the first index from right where nums[i] < nums[i+1] (break point).
2) If no break point, array is highest permutation -> reverse whole array.
3) Otherwise, find smallest element greater than nums[i] from right side and swap.
4) Reverse suffix (i+1 to end) to make it minimum.

Approach:
1) Traverse from right to find pivot index i.
2) If i == -1, reverse entire array and return.
3) Traverse from right again to find j such that nums[j] > nums[i].
4) Swap nums[i] and nums[j].
5) Reverse range [i+1, n-1].

Time Complexity:
- O(n)

Space Complexity:
- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutationOptimal(vector<int>& nums) {
    int n = (int)nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    nextPermutationOptimal(nums);

    for (int x : nums) cout << x << " ";
    cout << '\n';

    return 0;
}
