#include "equal.hpp"

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    cout << "General template used.\n";
    return a == b;
}

template bool equal<int>(int a, int b);
template bool equal<char>(char a, char b);

bool equal(double a, double b) {
    cout << "Specialized template for double used.\n";
    return fabs(a - b) < 0.00001;
}
