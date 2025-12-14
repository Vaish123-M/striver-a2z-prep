//Chcek if the array is sorted or not
//Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(1)
//Approach
//Traverse the array only once
//Compare every element with the next element
//If any pair is out of order → array is not sorted
//Otherwise → array is sorted

#include <iostream>
using namespace std;

/*
    Program: Check if array is sorted in ascending order
    Approach:
    - Traverse array from index 0 to n-2
    - Compare arr[i] with arr[i+1]
    - If arr[i] > arr[i+1], array is NOT sorted
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Edge case: An array with 0 or 1 element is always sorted
    if (n <= 1) {
        cout << "Array is sorted.";
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isSorted = true;

    // Check sorted condition
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted)
        cout << "Array is sorted in ascending order.";
    else
        cout << "Array is NOT sorted.";

    return 0;
}
