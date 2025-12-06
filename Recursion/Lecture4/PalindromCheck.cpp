//Check if a string is palindrome using recursion
//True-If is a palindrome
//False-If not a palindrome

//MADAM<---->MADAM
//Left side and right side has to be equivalent(same)

#include<iostream>
using namespace std;

// Recursive function to check palindrome
bool isPalindrome(string &s, int left, int right) {

    // Base case: if both pointers cross or meet → it's a palindrome
    if (left >= right)
        return true;

    // If characters don't match → not a palindrome
    if (s[left] != s[right])
        return false;

    // Move inward and continue checking
    return isPalindrome(s, left + 1, right - 1);
}

int main() {

    string s;
    cout << "Enter a string: ";
    cin >> s;   // manual input (single word)

    int n = s.length();

    if (isPalindrome(s, 0, n - 1))
        cout << "YES, it is a palindrome!";
    else
        cout << "NO, it is not a palindrome.";

    return 0;
}


//Time complexity: O(n) where n is the length of the string
//Why O(n)?

//For a string of length n:

//1st call: compare s[0] and s[n-1]
//2nd call: compare s[1] and s[n-2]
//3rd call: compare s[2] and s[n-3]
//~n/2 calls total
//So, total comparisons ≈ n/2 → O(n).

//Space complexity: O(n) due to recursion stack
//Each recursive call adds a new layer to the call stack.
//In the worst case, we make n/2 recursive calls before reaching the base case.
//Thus, the space used by the call stack is proportional to n.