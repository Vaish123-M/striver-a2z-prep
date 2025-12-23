/*
Sliding Window (ONLY for NON-NEGATIVE arrays)
⚠️ Not valid if negatives exist
🧠 Idea
Expand window
Shrink when sum > k
Count when sum == k
⏱ Time: O(n)
🧠 Space: O(1)
*/

#include <iostream>
using namespace std;

/*
    Sliding Window
    - Works only for non-negative arrays
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

    int left = 0, sum = 0, count = 0;

    for(int right = 0; right < n; right++) {
        sum += arr[right];

        while(sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            count++;
        }
    }

    cout << "Number of subarrays: " << count;
    return 0;
}