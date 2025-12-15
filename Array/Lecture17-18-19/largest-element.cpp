//Find the largest element in an array
//Optimal Solution 
//Time Complexity: O(n)
//Space Complexity: O(1)

//Approach
//Traverse the array only once
//Keep updating the maximum value

#include <iostream>
using namespace std;

/*
    Program: Find the largest element in an array
    Approach:
    - Assume first element is the largest
    - Compare it with every other element
    - Update the largest value if a bigger element is found
*/

int main() {
    int n;

    // Taking size of array from user
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Taking array elements from user
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Assume first element is the largest
    int largest = arr[0];

    // Traverse array to find largest element
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];   // update largest
        }
    }

    // Output result
    cout << "Largest element in the array is: " << largest;

    return 0;
}


