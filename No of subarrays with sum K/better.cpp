/* Better / Optimal Solution – Prefix Sum + Hashing
🧠 Idea
Use prefix sum
If prefixSum - k exists before → valid subarray
Hashmap stores frequency of prefix sums

⏱ Time: O(n)
🧠 Space: O(n)
✅ Works with negative numbers

🔑 Key Formula
If prefixSum - k exists in map
→ add its frequency to count
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Prefix Sum + Hashing
    - Best solution
    - Handles negative numbers
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
    int prefixSum = 0, count = 0;

    mp[0] = 1;   // Important for subarrays starting from index 0

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(mp.find(prefixSum - k) != mp.end()) {
            count += mp[prefixSum - k];
        }

        mp[prefixSum]++;
    }

    cout << "Number of subarrays: " << count;
    return 0;
}
