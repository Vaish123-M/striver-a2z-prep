/*
Problem: Majority Element II (> n/3 occurrences in an array) — report all such elements.
Approach: Brute force double loop; for each distinct element, count frequency by scanning full array.
Idea: Validate each candidate directly and collect values with count > n/3.
Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding answer)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementBrute(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        bool alreadyTaken = false;
        for (int x : ans) {
            if (x == nums[i]) {
                alreadyTaken = true;
                break;
            }
        }
        if (alreadyTaken) continue;

        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) ++cnt;
        }

        if (cnt > n / 3) ans.push_back(nums[i]);
        if (ans.size() == 2) break;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 2, 2};
    vector<int> ans = majorityElementBrute(nums);

    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
