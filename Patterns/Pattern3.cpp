// 1 to row number
//row number = number of elements
#include<iostream>
using namespace std;
void print1(int n){
    for(int i=1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout << j <<" ";     
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