//Find the number that appears only once in an array where every other number appears twice
//Time Complexity: O(n)
//Space Complexity: O(1)

//Optimal Approach
/*Key XOR Properties
x ^ x = 0
x ^ 0 = x
XOR is commutative & associative

Idea
XOR all elements of the array
Duplicate elements cancel each other
Remaining value is the element that appears once
*/

#include <iostream>
using namespace std;

/*
    Optimal Solution:
    - Uses XOR operation
    - No extra space
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = 0;

    // XOR all elements
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }

    cout << "Element appearing once: " << result;

    return 0;
}


