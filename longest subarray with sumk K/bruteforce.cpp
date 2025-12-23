/*
Brute Force Solution
🔹 Idea
Generate all possible subarrays
Calculate sum for each
If sum == k, update maximum length

⏱ Time Complexity: O(n²)
🧠 Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/*
    Brute Force Solution
    - Generate all subarrays
    - Check their sum
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

    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    cout << "Longest subarray length: " << maxLen;
    return 0;
}
