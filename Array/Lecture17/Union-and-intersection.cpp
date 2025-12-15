//Find the union and intersection of two sorted arrays
//Time Complexity: O(m + n)
//Space Complexity: O(m + n)

//Approach
/*Use two pointers to traverse both arrays
When elements are equal, add to both union and intersection
When one element is smaller, add it to union and move that pointer
*/
#include <iostream>
using namespace std;

/*
    Program: Find UNION and INTERSECTION of two sorted arrays
    Approach:
    - Use two pointers i and j
    - Compare elements from both arrays
    - Move pointers accordingly
*/

// -------------------- UNION FUNCTION --------------------
void findUnion(int a[], int n, int b[], int m) {
    int i = 0, j = 0;

    cout << "Union: ";

    while (i < n && j < m) {

        // Skip duplicate elements in array a
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }

        // Skip duplicate elements in array b
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }

        // If both elements are equal
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        }
        // If element in a is smaller
        else if (a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        }
        // If element in b is smaller
        else {
            cout << b[j] << " ";
            j++;
        }
    }

    // Print remaining elements of array a
    while (i < n) {
        if (i == 0 || a[i] != a[i - 1])
            cout << a[i] << " ";
        i++;
    }

    // Print remaining elements of array b
    while (j < m) {
        if (j == 0 || b[j] != b[j - 1])
            cout << b[j] << " ";
        j++;
    }

    cout << endl;
}

// -------------------- INTERSECTION FUNCTION --------------------
void findIntersection(int a[], int n, int b[], int m) {
    int i = 0, j = 0;

    cout << "Intersection: ";

    while (i < n && j < m) {

        // Skip duplicates in array a
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }

        // If elements are equal, it's intersection
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        }
        // Move pointer of smaller element
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << endl;
}

// -------------------- MAIN FUNCTION --------------------
int main() {

    int n, m;

    cout << "Enter size of first sorted array: ";
    cin >> n;
    int a[n];

    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter size of second sorted array: ";
    cin >> m;
    int b[m];

    cout << "Enter elements of second array:\n";
    for (int i = 0; i < m; i++)
        cin >> b[i];

    findUnion(a, n, b, m);
    findIntersection(a, n, b, m);

    return 0;
}
