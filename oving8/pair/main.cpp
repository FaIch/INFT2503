#include <iostream>
#include "Pair.hpp"

using namespace std;

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;

    return 0;
}

/*
 * Forutsetningene jeg gjør er:
 *
 * Operatorene + og > er definert for de respektive typene T1 og T2.
 * Det må være mulig å addere verdiene av T1 med verdiene av T1 og T2 med T2.
 * Det må være mulig å sammenligne summen av T1 og T2 med summen av et annet par T1 og T2.
 */