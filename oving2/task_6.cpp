#include <iostream>

using namespace std;

int find_sum(const int *table, int length);

int main() {
    int table[20];
    for (int i = 0; i < 20; i++){
        table[i] = i+1;
    }
    const int first_10 = find_sum(table, 10);
    const int next_5 = find_sum(&table[10], 5);
    const int last_5 = find_sum(&table[15], 5);


    cout << "First 10: " << first_10 << endl;
    cout << "Next 5: " << next_5 << endl;
    cout << "Last 5: " << last_5 << endl;
}

int find_sum(const int *table, int length){
    int sum = 0;

    for (int i = 0; i < length; i++){
        sum += *(table + i);
    }

    return sum;
}