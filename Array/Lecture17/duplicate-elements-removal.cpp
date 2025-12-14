//Remove duplicate elements from an array
//Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(n)

//Approach
/*Use two pointers:
i → tracks position of last unique element
j → scans the array
When arr[j] != arr[i], move unique element forward
*/

/*Remove Duplicates from Sorted Array (In-Place)
Important Condition
Array must be sorted
No extra array allowed (in-place)
*/

#include <iostream>
using namespace std;

/*
    Program: Remove duplicates from a sorted array (in-place)
    Approach:
    - Use two pointers
    - Pointer i keeps index of last unique element
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
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0; // index of last unique element

    // Traverse array from second element
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;              // move pointer forward
            arr[i] = arr[j];  // place next unique element
        }
    }

    int newLength = i + 1;

    cout << "Array after removing duplicates:\n";
    for (int k = 0; k < newLength; k++) {
        cout << arr[k] << " ";
    }

    cout << "\nNew length: " << newLength;

    return 0;
}
