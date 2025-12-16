//Find the number which appears only once in an array where every other number appears twice
//Time Complexity: O(n)
//Space Complexity: O(n) -->extra space
// Better Approach

#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Better Solution:
    - Use hashing (frequency count)
    - Extra space required
*/

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Find element that appears once
    for (auto it : freq) {
        if (it.second == 1) {
            cout << "Element appearing once: " << it.first;
            break;
        }
    }

    return 0;
}

