/*
Optimal Solution – Sliding Window (User Input)
⚠️ Works ONLY if array has NON-NEGATIVE elements
🧠 Idea
Expand window using right
Shrink window if sum > k
Update length when sum == k

⏱ Time: O(n)
🧠 Space: O(1) ✅
*/

#include <iostream>
using namespace std;

/*
    Optimal Solution
    - Sliding window technique
    - Only for non-negative arrays
*/

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter non-negative array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter value of k: ";
    cin >> k;

    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while(right < n) {
        sum += arr[right];

        while(sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    cout << "Longest subarray length: " << maxLen;
    return 0;
}
