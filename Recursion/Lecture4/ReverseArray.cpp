//Reverse ann Array using Recursuin USING SINGLE POINTER APPROACH

#include <iostream>
using namespace std;

// Reverse array using recursion (single pointer method)
void reverseArray(int arr[], int i, int n) {

    // Base case: stop when i reaches or crosses the middle
    if (i >= n / 2)
        return;

    // Swap element at i with its mirror element at (n - i - 1)
    swap(arr[i], arr[n - i - 1]);

    // Recursive call for the next index
    reverseArray(arr, i + 1, n);
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // Manual input
    }

    // Call recursion starting at index 0
    reverseArray(arr, 0, n);

    // Print reversed array
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
