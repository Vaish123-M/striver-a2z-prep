#include <iostream>
using namespace std;

// --------------------------
// MERGE FUNCTION
// --------------------------
void merge(int arr[], int start, int mid, int end) {

    int n1 = mid - start + 1;  // size of left part
    int n2 = end - mid;        // size of right part

    int left[n1], right[n2];   // temp arrays

    // Copy elements to left[] and right[]
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];

    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;

    // Merge two sorted halves
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

    // Copy remaining elements
    while(i < n1) {
        arr[k] = left[i];
        i++; k++;
    }

    while(j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
}

// --------------------------
// MERGE SORT FUNCTION
// --------------------------
void mergeSort(int arr[], int start, int end) {

    if(start < end) {

        int mid = (start + end) / 2;

        // Sort left half
        mergeSort(arr, start, mid);

        // Sort right half
        mergeSort(arr, mid + 1, end);

        // Merge both halves
        merge(arr, start, mid, end);
    }
}

// --------------------------
// MAIN FUNCTION WITH USER INPUT
// --------------------------
int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Call merge sort
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
