#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
void print () {
    if(cnt == 3) return;
    cnt++;
    cout << 1 << endl;
    print();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    print(); //is calling cout << 1 << endl
    return 0;
}