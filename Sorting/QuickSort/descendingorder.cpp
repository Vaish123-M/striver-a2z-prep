#include <iostream>
using namespace std;

/*
    QUICK SORT (DESCENDING ORDER)
    ----------------------------------
    Logic change:
    For ascending we use: arr[i] < pivot
    For descending we use: arr[i] > pivot

    So just reverse the comparison operator.
*/

// Function to partition the array for descending order
int partitionDesc(int arr[], int low, int high) {
    int pivot = arr[high];      // pivot element
    int i = low - 1;            // index for larger elements

    for (int j = low; j < high; j++) {
        // Change condition for descending
        if (arr[j] > pivot) {   // larger elements come first
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort function (recursive)
void quickSortDesc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDesc(arr, low, high);  // partition index

        // Recursively sort left and right parts
        quickSortDesc(arr, low, pi - 1);
        quickSortDesc(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call quicksort for descending order
    quickSortDesc(arr, 0, n - 1);

    cout << "\nSorted array in DESCENDING ORDER:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
