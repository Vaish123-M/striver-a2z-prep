//Find the missing number in an array
/*Optimal Solution (Using SUM Formula)
Sum of first n natural numbers = n * (n + 1) / 2
Subtract the sum of array elements from this total
The result is the missing number

⏱ Time Complexity: O(n)
🧠 Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/*
    Program: Find the missing number in an array
    Given:
    - Array of size (n-1)
    - Contains numbers from 1 to n (one missing)

    Optimal Approach:
    - Use sum formula
*/

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n - 1];

    cout << "Enter " << n - 1 << " elements:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    // Sum of first n natural numbers
    int totalSum = n * (n + 1) / 2;

    // Sum of array elements
    int arraySum = 0;
    for (int i = 0; i < n - 1; i++) {
        arraySum += arr[i];
    }

    // Missing number
    int missing = totalSum - arraySum;

    cout << "Missing number is: " << missing;

    return 0;
}
