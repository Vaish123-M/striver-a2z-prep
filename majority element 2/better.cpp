/*
Problem: Majority Element II (> n/3 occurrences in an array) — report all such elements.
Approach: Better via hashmap; count frequencies, then collect keys with count > n/3.
Idea: Frequency map gives linear counting with extra memory.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementBetter(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];

    vector<int> ans;
    int n = static_cast<int>(nums.size());

    for (const auto& entry : freq) {
        if (entry.second > n / 3) ans.push_back(entry.first);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 2, 2};
    vector<int> ans = majorityElementBetter(nums);

    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
