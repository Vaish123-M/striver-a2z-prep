//Move all zeroes to the end of the array
//Time Complexity: O(n)
//Space Complexity: O(1)

//Approach
/*Use two pointers:
i → tracks position to place non-zero element
j → scans the array
When arr[j] is non-zero, place it at arr[i] and increment i
*/
#include <iostream>
using namespace std;
/*
    Program: Move all zeroes to the end of the array
    Approach:
    - Use two pointers
    - Pointer i keeps index to place next non-zero element
    - Pointer j traverses the array
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

    int i = 0; // index to place next non-zero element

    // Traverse the array
    for (int j = 0; j < n; j++) {
        if (arr[j] != 0) {
            arr[i] = arr[j]; // place non-zero element at index i
            i++;             // increment i
        }
    }

    // Fill remaining positions with zeroes
    for (int k = i; k < n; k++) {
        arr[k] = 0;
    }

    cout << "Array after moving all zeroes to the end:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}