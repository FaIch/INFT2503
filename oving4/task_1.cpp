#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> myVector = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << "First element: " << myVector.front() << endl;
    cout << "Last element: " << myVector.back() << endl;

    myVector.emplace(myVector.begin() + 1, 1.5);

    cout << "New first element after emplace: " << myVector.front() << endl;

    auto it = find(myVector.begin(), myVector.end(), 3.3);

    if (it != myVector.end()) {
        cout << "Value " << *it << " was found." << endl;
    } else {
        cout << "Value not found in vector." << endl;
    }

    return 0;
}

