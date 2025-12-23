/*1️⃣ Brute Force Solution
🧠 Idea
Generate all subarrays
Calculate sum for each
If sum == k, increase count
⏱ Time: O(n²)
🧠 Space: O(1)
*/

#include <iostream>
using namespace std;

/*
    Brute Force Approach
    - Check all subarrays
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

    int count = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == k) {
                count++;
            }
        }
    }

    cout << "Number of subarrays: " << count;
    return 0;
}
