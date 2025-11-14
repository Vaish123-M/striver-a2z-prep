// we are printig (n-row-1)on each line
#include<iostream>
using namespace std;

void print1(int n){
    for(int i=0; i<n; i++) {
        for(int j = 0; j<n-i+1; j++) {
            cout << "*";     
        }
        cout << endl;
    }
}

int main(){
    int t;
    if (!(cin >> t)) {
        // No input provided (likely double-clicked exe or no stdin). Use a sample test.
        int sample_n = 5;
        cout << "No input detected. Using sample: t=1, n=5\n\n";
        print1(sample_n);
        return 0;
    }

    for (int i = 0; i < t; i++) {
        int n;
        if (!(cin >> n)) {
            cerr << "Expected " << t << " values for n but got fewer.\n";
            return 1;
        }
        print1(n);
    }
    return 0;
}