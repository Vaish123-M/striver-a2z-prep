#include <bits/stdc++.h>
using namespace std;

/*
    QUICK SORT:
    -----------
    Quick Sort is a divide-and-conquer algorithm.
    Steps:
    1. Choose a pivot element.
    2. Partition the array such that:
         - Elements smaller than pivot come to the left
         - Elements greater than pivot come to the right
    3. Recursively apply Quick Sort on left and right subarrays.

    Time Complexity:
        Best Case: O(n log n)
        Average Case: O(n log n)
        Worst Case: O(n^2)   (when pivot selection is bad)
*/


// ----------------------------------------------------------
// FUNCTION: Partition
// Places the pivot at correct position and arranges elements
// smaller on left and greater on right
// ----------------------------------------------------------
int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];   // Choosing last element as pivot
    int i = low - 1;        // Pointer for smaller elements

    for (int j = low; j < high; j++) {
        // If element is smaller than pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Move smaller element to left
        }
    }

    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


// ----------------------------------------------------------
// FUNCTION: Quick Sort (recursive function)
// ----------------------------------------------------------
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high); // partition index

        // Recursively sort left and right partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// ----------------------------------------------------------
// MAIN FUNCTION: Taking user input and printing sorted output
// ----------------------------------------------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling Quick Sort
    quickSort(arr, 0, n - 1);

    // Display sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
