#include <vector>
#include <iostream>

class Set {
private:
    std::vector<int> elements;

public:
    Set();
    Set(const std::vector<int>& vec);

    Set operator+(const Set& other) const;
    Set& operator=(const Set& other);

    void addElement(int element);
    void print() const;
};
