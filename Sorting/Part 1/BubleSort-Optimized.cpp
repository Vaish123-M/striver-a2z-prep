#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = n-1; i >= 1; i--) {
        int disSwap = 0;
        // After ith iteration, the last i elements are sorted
        for(int j = 0; j <= i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                disSwap = 1;
            }
        }
        if(disSwap == 0) {
            break;
        }
        cout << "runs\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}