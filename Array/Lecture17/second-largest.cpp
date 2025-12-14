//Second Largest element in an array
//Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(1)

//Approach
//Traverse the array only once
//Keep updating the largest and second largest values

#include <iostream>
#include <climits>   // For INT_MIN
using namespace std;

/*
    Program: Find the second largest element in an array
    Approach:
    - Initialize largest and secondLargest with INT_MIN
    - Traverse the array once
    - Update largest and secondLargest based on comparisons
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Edge case: If array has less than 2 elements
    if (n < 2) {
        cout << "Second largest element does not exist.";
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    // Traverse array
    for (int i = 0; i < n; i++) {

        // If current element is greater than largest
        if (arr[i] > largest) {
            secondLargest = largest;  // update second largest
            largest = arr[i];         // update largest
        }

        // If element is between largest and secondLargest
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    // If secondLargest was never updated
    if (secondLargest == INT_MIN) {
        cout << "Second largest element does not exist.";
    } else {
        cout << "Second largest element is: " << secondLargest;
    }

    return 0;
}
