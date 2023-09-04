#include <iostream>
#include <cstdlib>
#include <fstream>
#include "header.h"

using namespace std;

void b(double temperatures[], int length);

int main() {
    a();

    const int length = 5;
    double temperatures[length];

    int under_10 = 0;
    int between_10_and_20 = 0;
    int over_20 = 0;

    b(temperatures, length);

    for (double temperature : temperatures) {
        if (temperature < 10) {
            under_10++;
        } else if (temperature >= 10 && temperature <= 20) {
            between_10_and_20++;
        } else {
            over_20++;
        }
    }

    cout << "Number of days with temperature under 10: " << under_10 << endl;
    cout << "Number of days with temperature between 10 and 20: " << between_10_and_20 << endl;
    cout << "Number of days with temperature over 20: " << over_20 << endl;

    return 0;
}

void a() {
    int under_ten = 0;
    int between_ten_and_twenty = 0;
    int over_twenty = 0;

    cout << "Write 5 temperatures, separated by 'Enter'" << endl;

    while (under_ten + between_ten_and_twenty + over_twenty < 5){
        double number;
        cin >> number;
        if (number < 10){
            under_ten++;
        }
        else if (number >= 10 && number <= 20){
            between_ten_and_twenty++;
        }
        else if (number > 20){
            over_twenty++;
        }
    }

    cout << "Number under 10: " << under_ten << endl;
    cout << "Number between 10 and 20: " << between_ten_and_twenty << endl;
    cout << "Number over 20: " << over_twenty << endl << endl;
}

void b(double temperatures[], int length) {
    ifstream infile("tall.dat");

    if (!infile) {
        cerr << "Could not open the file." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; ++i) {
        if (!(infile >> temperatures[i])) {
            cerr << "Error reading temperature for entry " << i << endl;
            exit(EXIT_FAILURE);
        }
    }

    infile.close();
}