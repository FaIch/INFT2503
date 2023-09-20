#include "set.hpp"

int main() {
    Set a;

    a.addElement(1);
    a.addElement(4);
    a.addElement(3);

    Set b({4, 7});

    std::cout << "Mengde a: ";
    a.print();
    std::cout << "Mengde b: ";
    b.print();

    Set c = a + b;

    std::cout << "Unionen av a og b: ";
    c.print();

    Set d;
    d = a;

    std::cout << "Mengde d (kopi av a): ";
    d.print();

    return 0;
}
