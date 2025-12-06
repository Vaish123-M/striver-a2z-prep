#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n ;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //precompute hash values
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;

        //fetching the frequency from hash table
        cout << hash[number] << endl;
    }
}