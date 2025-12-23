/*Better Solution – Prefix Sum + Hashing (User Input)
🧠 Idea
Maintain prefix sum
Store first occurrence of prefix sum in hashmap
If (prefixSum - k) exists → valid subarray
⏱ Time: O(n)
🧠 Space: O(n) ❌
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Better Solution
    - Prefix sum + hashing
    - Works for negative numbers also
*/

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter value of k: ";
    cin >> k;

    unordered_map<int, int> mp;
    int prefixSum = 0, maxLen = 0;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == k)
            maxLen = i + 1;

        if(mp.find(prefixSum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[prefixSum - k]);
        }

        if(mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    cout << "Longest subarray length: " << maxLen;
    return 0;
}
