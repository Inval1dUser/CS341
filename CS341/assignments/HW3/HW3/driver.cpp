#include "bitarray.h"
#include <iostream>

int main() {
    int size = 12;
    char word[12] = {'H', 'E', 'L', 'L', 'O', '_', 'W', 'O', 'R', 'L', 'D'};
    BitArray myBit(size);
    myBit.initialize(word, 4);

    std::cout << "Bits in array: " << myBit.length() * BIT_IN_BYTE << std::endl;
    myBit.print();
    myBit.~BitArray();



    return 0;
}