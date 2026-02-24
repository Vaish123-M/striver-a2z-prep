/*
Problem:
Given an array nums of size n representing a permutation, rearrange it into the lexicographically next greater permutation.
If such arrangement is not possible, rearrange it into the lowest possible order (sorted in ascending order).

Bruteforce Solution:
Generate all permutations, sort them lexicographically, find the current permutation, and return the next one.
If current is the last permutation, return the first permutation.

Idea:
- Generate every possible arrangement.
- Lexicographically order all permutations.
- Locate current permutation and pick the next one.

Approach:
1) Store original array.
2) Recursively generate all permutations using swapping.
3) Sort all generated permutations.
4) Remove duplicate permutations (safe guard for repeated numbers).
5) Find index of original permutation.
6) Print next permutation if exists, else print first permutation.

Time Complexity:
- Permutation generation: O(n! * n)
- Sorting permutations: O(n! * log(n!) * n)
Overall: O(n! * log(n!) * n)

Space Complexity:
- Storing permutations: O(n! * n)
- Recursion stack: O(n)
Overall: O(n! * n)
*/

#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<int>& arr, int idx, vector<vector<int>>& allPerms) {
    if (idx == (int)arr.size()) {
        allPerms.push_back(arr);
        return;
    }

    for (int i = idx; i < (int)arr.size(); i++) {
        swap(arr[idx], arr[i]);
        generatePermutations(arr, idx + 1, allPerms);
        swap(arr[idx], arr[i]);
    }
}

vector<int> nextPermutationBruteforce(vector<int> nums) {
    vector<int> original = nums;
    vector<vector<int>> allPerms;

    generatePermutations(nums, 0, allPerms);
    sort(allPerms.begin(), allPerms.end());
    allPerms.erase(unique(allPerms.begin(), allPerms.end()), allPerms.end());

    for (int i = 0; i < (int)allPerms.size(); i++) {
        if (allPerms[i] == original) {
            if (i + 1 < (int)allPerms.size()) return allPerms[i + 1];
            return allPerms[0];
        }
    }

    return original;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = nextPermutationBruteforce(nums);

    for (int x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}
