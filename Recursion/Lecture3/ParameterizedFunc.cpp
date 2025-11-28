#include <iostream>
using namespace std;

void greet(string name) {   // parameterized function
    cout << "Hello " << name << "!" << endl;
}

int main() {
    greet("Vaishnavi");   // passing parameter
    greet("ATS");
    return 0;
}
