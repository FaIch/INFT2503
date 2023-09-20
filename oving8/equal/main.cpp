#include <iostream>
#include <iomanip>
#include "equal.hpp"

using namespace std;

int main() {
    int a = 5, b = 5;
    if (equal(a, b)) {
        cout << "Integers are equal.\n";
    } else {
        cout << "Integers are not equal.\n";
    }

    double x = 3.14159, y = 3.14158;
    if (equal(x, y)) {
        cout << setprecision(10) << "Doubles are equal.\n";
    } else {
        cout << setprecision(10) << "Doubles are not equal.\n";
    }

    char c1 = 'A', c2 = 'A';
    if (equal(c1, c2)) {
        cout << "Characters are equal.\n";
    } else {
        cout << "Characters are not equal.\n";
    }

    return 0;
}
