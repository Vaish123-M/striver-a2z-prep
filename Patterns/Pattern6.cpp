//same as pattern 5 but with numbers
#include<iostream>
using namespace std;

void print1(int n){
    for(int i=0; i<n; i++) {
        for(int j = 1; j<n-i+1; j++) {
            cout << j  << " ";     
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        print1(n);
    }
}