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
APPROACH - BRUTE FORCE:
================================================================================
1. Create two separate arrays/vectors: one for positive numbers and one for 
   negative numbers.
2. Iterate through the original array and segregate elements into positive and
   negative lists while maintaining their original order.
3. Merge them alternately: pick one positive, then one negative, and repeat.
4. Store the result in the original array.

IDEA:
- By separating elements, we can easily alternate them without complex logic
- The separation maintains the relative order of positives and negatives
- Simple and easy to understand approach

================================================================================
TIME COMPLEXITY: O(n)
================================================================================
- Iteration 1: Segregating elements into two arrays: O(n)
- Iteration 2: Merging two arrays alternately: O(n)
- Total: O(n)

================================================================================
SPACE COMPLEXITY: O(n)
================================================================================
- Two extra vectors for storing positive and negative numbers: O(n)
- No additional data structures beyond input size

================================================================================
*/

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    // Step 1: Separate positive and negative numbers
    vector<int> positive, negative;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }
    
    cout << "Positive Numbers: ";
    for (int num : positive) {
        cout << num << " ";
    }
    cout << "\n";
    
    cout << "Negative Numbers: ";
    for (int num : negative) {
        cout << num << " ";
    }
    cout << "\n\n";
    
    // Step 2: Merge alternately (positive first, then negative)
    int idx = 0;
    int posIdx = 0, negIdx = 0;
    
    while (posIdx < positive.size() && negIdx < negative.size()) {
        arr[idx++] = positive[posIdx++];   // Add positive
        arr[idx++] = negative[negIdx++];   // Add negative
    }
    
    // If any positives are left
    while (posIdx < positive.size()) {
        arr[idx++] = positive[posIdx++];
    }
    
    // If any negatives are left
    while (negIdx < negative.size()) {
        arr[idx++] = negative[negIdx++];
    }
    
    // Step 3: Display result
    cout << "Rearranged Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
OUTPUT:
Original Array: 3 1 -2 -5 2 -4

Positive Numbers: 3 1 2
Negative Numbers: -2 -5 -4

Rearranged Array: 3 -2 1 -5 2 -4
*/
