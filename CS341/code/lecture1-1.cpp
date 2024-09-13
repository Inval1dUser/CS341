#include <iostream>
#include "Rectangle.h";

int main() {
    // Class Object
    Rectangle r;

    std::cout << r.getX() << std::endl;

    // End Stack Memory

    Rectangle * r1 = new Rectangle(7, 77);

    std::cout << r1->getX() << std::endl;

    delete r1;

    return 0;
}