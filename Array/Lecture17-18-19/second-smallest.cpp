//Find second smallest element in an array
//Optimal Solution
//Time Complexity: O(n)
//Space Complexity: O(1)
//Approach
//Traverse the array only once
//Keep updating the smallest and second smallest values

#include <iostream>
#include <climits>   // For INT_MAX
using namespace std;

/*
    Program: Find the second smallest element in an array
    Approach:
    - Initialize smallest and secondSmallest with INT_MAX
    - Traverse the array once
    - Update smallest and secondSmallest accordingly
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Edge case: If array has less than 2 elements
    if (n < 2) {
        cout << "Second smallest element does not exist.";
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    // Traverse array
    for (int i = 0; i < n; i++) {

        // If current element is smaller than smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest; // update second smallest
            smallest = arr[i];         // update smallest
        }

        // If element is between smallest and secondSmallest
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    // If secondSmallest was never updated
    if (secondSmallest == INT_MAX) {
        cout << "Second smallest element does not exist.";
    } else {
        cout << "Second smallest element is: " << secondSmallest;
    }

    return 0;
}
