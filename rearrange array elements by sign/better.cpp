#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
PROBLEM STATEMENT:
================================================================================
Rearrange array elements by sign such that positive and negative numbers
alternate, starting with a positive number.

Example:
Input:  arr[] = [3, 1, -2, -5, 2, -4]
Output: arr[] = [3, -2, 1, -5, 2, -4]

Pattern: positive, negative, positive, negative, ...

================================================================================
APPROACH - OPTIMIZED / BETTER:
================================================================================
1. Create a result array of the same size.
2. Use two pointers:
   - Even index pointer (0, 2, 4, ...): for placing positive numbers
   - Odd index pointer (1, 3, 5, ...): for placing negative numbers
3. Iterate through the original array once:
   - If element is positive, place it at even index and increment even pointer
   - If element is negative, place it at odd index and increment odd pointer
4. No need for extra segregation step!

IDEA:
- Use position-based logic instead of separation
- Even positions are reserved for positive numbers
- Odd positions are reserved for negative numbers
- Single pass through the array after setup
- More direct and efficient approach

================================================================================
TIME COMPLEXITY: O(n)
================================================================================
- Single iteration through the array: O(n)
- Each element is processed exactly once
- Total: O(n)

================================================================================
SPACE COMPLEXITY: O(n)
================================================================================
- Result array requiring O(n) space for output
- Two pointers using O(1) additional space
- Total: O(n) due to result array

================================================================================
*/

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    int n = arr.size();
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    // Create result array
    vector<int> result(n);
    
    // Initialize pointers for even and odd positions
    int evenIdx = 0;   // For positive numbers (0, 2, 4, ...)
    int oddIdx = 1;    // For negative numbers (1, 3, 5, ...)
    
    cout << "Placing elements:\n";
    
    // Iterate through original array
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            // Positive number - place at even index
            result[evenIdx] = arr[i];
            cout << arr[i] << " placed at index " << evenIdx << " (positive)\n";
            evenIdx += 2;  // Move to next even position
        } else {
            // Negative number - place at odd index
            result[oddIdx] = arr[i];
            cout << arr[i] << " placed at index " << oddIdx << " (negative)\n";
            oddIdx += 2;   // Move to next odd position
        }
    }
    
    cout << "\nRearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
OUTPUT:
Original Array: 3 1 -2 -5 2 -4

Placing elements:
3 placed at index 0 (positive)
1 placed at index 2 (positive)
-2 placed at index 1 (negative)
-5 placed at index 3 (negative)
2 placed at index 4 (positive)
-4 placed at index 5 (negative)

Rearranged Array: 3 -2 1 -5 2 -4
*/
