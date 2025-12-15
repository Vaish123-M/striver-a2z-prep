//Left rotate an array by d positions
//Time Complexity: O(n)
//Space Complexity: O(d)

//Approach
/*Use a temporary array to store first d elements       
Shift the remaining elements to the left by d positions
Copy the d elements from the temporary array to the end of the original array
*/

#include <iostream>
using namespace std;
/*
    Program: Left rotate an array by d positions
    Approach:
    - Use a temporary array to store first d elements
    - Shift the remaining elements to the left by d positions
    - Copy the d elements from the temporary array to the end of the original array
*/
int main() {
    int n, d;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter number of positions to rotate (d): ";
    cin >> d;

    // Edge case
    if (n == 0) {
        cout << "Array is empty.";
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Handle cases where d >= n
    d = d % n;

    // Temporary array to store first d elements
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift remaining elements to the left by d positions
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Copy d elements from temp array to the end of original array
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }

    cout << "Array after left rotation by " << d << " positions:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}