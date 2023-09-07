#include <iostream>

using namespace std;

int main()
{
    double number;
    double *pointer = &number;
    double &reference = number;

    number = 0.1;

    cout << number << endl;

    *pointer = 0.2;

    cout << number << endl;

    reference = 0.3;

    cout << number << endl;

    return 0;
}
