#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Address i: " << &i << " | Content: " << i << endl;
    cout << "Address j: " << &j << " | Content: " << j << endl;
    cout << "Address p: " << p << " | Content: " << *p << endl;
    cout << "Address q: " << q << " | Content: " << *q << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << endl << "Content p: " << *p << " | Content q: " << *q << endl; //the print will be 8 for both variables
}
