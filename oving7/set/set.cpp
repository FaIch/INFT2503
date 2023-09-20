#include "set.hpp"
#include <algorithm>

Set::Set() {}

Set::Set(const std::vector<int>& vec) : elements(vec) {}

Set Set::operator+(const Set& other) const {
    Set result = *this;
    for (const int& elem : other.elements) {
        if (std::find(result.elements.begin(), result.elements.end(), elem) == result.elements.end()) {
            result.elements.push_back(elem);
        }
    }
    return result;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

void Set::addElement(int element) {
    if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
        elements.push_back(element);
    }
}

void Set::print() const {
    std::cout << "{ ";
    for (const int& elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}
