//print a square pattern of stars of size 5x5

/*#include<iostream>
using namespace std;
void print1(){
    for(int i=0; i<5; i++) {
        for(int j =0; j<5; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    print1();

}
    */


//input is generally given so this is the expected way of writing code
#include<iostream>
using namespace std;
void print1(int n){
    for(int i=0; i<n; i++) {
        for(int j =0; j<n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    print1(n);

}