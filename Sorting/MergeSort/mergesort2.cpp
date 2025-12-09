#include <iostream>
using namespace std;

// ------------------------------------------
// Function to merge two sorted halves
// ------------------------------------------
void merge(int arr[], int start, int mid, int end) {

    // Sizes of two temporary arrays
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Temporary arrays
    int left[n1], right[n2];

    // Copy data into left[] and right[] arrays
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];

    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0;         // indexes for left[] and right[]
    int k = start;            // index for original array

    // Merge both arrays into original arr[]
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// ------------------------------------------
// Recursive Merge Sort Function
// ------------------------------------------
void mergeSort(int arr[], int start, int end) {

    if(start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);      // Sort left half
        mergeSort(arr, mid + 1, end);    // Sort right half

        merge(arr, start, mid, end);     // Merge both sorted halves
    }
}

// ------------------------------------------
// Main Function
// ------------------------------------------
int main() {

    int arr[] = {9, 5, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
