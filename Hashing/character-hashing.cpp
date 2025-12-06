#include<bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;

   //pre compute
   int hash[26] = {0};
    for(int i = 0; i < s.length(); i++) {
         hash[s[i] - 'a'] ++;
    }
    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;

        //fetching the frequency from hash table
        cout << hash[ch - 'a'] << endl;
    }
}