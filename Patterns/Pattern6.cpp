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
    if (!(cin >> t)) {
        // No stdin provided — run with a sample input so users see output when double-clicking.
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