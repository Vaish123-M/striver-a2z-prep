//Maximum consecutive ones in an array
//Time Complexity: O(n)
//Space Complexity: O(1)
//Approach
/*Traverse the array once
Keep a counter for current consecutive 1s
Reset counter when 0 appears
Track the maximum count*/

#include <iostream>
using namespace std;

/*
    Program: Find maximum consecutive 1s in a binary array
    Approach:
    - Traverse the array
    - Count consecutive 1s
    - Reset count when 0 appears
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter binary array elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxCount = 0;     // stores maximum consecutive 1s
    int currentCount = 0; // stores current consecutive 1s

    // Traverse array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;                 // increase count
            maxCount = max(maxCount, currentCount); // update max
        } else {
            currentCount = 0;               // reset when 0 found
        }
    }

    cout << "Maximum consecutive 1s: " << maxCount;

    return 0;
}
