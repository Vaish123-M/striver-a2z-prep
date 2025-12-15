//Left rotate an array by one position
//Time Complexity: O(n)
//Space Complexity: O(1)

//Approach
/*Store first element in a temp variable
Shift all elements to the left by one position
Place the temp variable at the end of the array
*/

#include <iostream>
using namespace std;
/*
    Program: Left rotate an array by one position
    Approach:
    - Store first element in a temp variable
    - Shift all elements to the left by one position
    - Place the temp variable at the end of the array
*/
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

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

    // Store first element
    int temp = arr[0];

    // Shift elements to the left
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    // Place first element at the end
    arr[n - 1] = temp;

    cout << "Array after left rotation by one position:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}