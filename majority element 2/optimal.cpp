/*
Problem: Majority Element II (> n/3 occurrences in an array) — report all such elements.
Approach: Optimal extended Moore's Voting; keep two candidates and two counters, then verify.
Idea: At most two elements can appear more than n/3 times, so track only two possibilities.
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding answer)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementOptimal(const vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int candidate1 = 0, candidate2 = 0;

    for (int x : nums) {
        if (cnt1 > 0 && x == candidate1) {
            ++cnt1;
        } else if (cnt2 > 0 && x == candidate2) {
            ++cnt2;
        } else if (cnt1 == 0) {
            candidate1 = x;
            cnt1 = 1;
        } else if (cnt2 == 0) {
            candidate2 = x;
            cnt2 = 1;
        } else {
            --cnt1;
            --cnt2;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int x : nums) {
        if (x == candidate1) ++cnt1;
        else if (x == candidate2) ++cnt2;
    }

    vector<int> ans;
    int threshold = static_cast<int>(nums.size()) / 3;
    if (cnt1 > threshold) ans.push_back(candidate1);
    if (cnt2 > threshold) ans.push_back(candidate2);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 2, 2};
    vector<int> ans = majorityElementOptimal(nums);

    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
