#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
#include <iostream>


//TODO: fix the copy constructors

int main() {
    char word[4] = {'t', 'e', 's', 'i'};
    int size = sizeof(word)*BIT_IN_BYTE;
    BitArray myBit(size);
    myBit.initialize(word, size);

    Dictionary myDict;
    myDict.initialize(word, size);

    myBit.print();
    
    std::cout << myDict.select(5, 1) << "\n";
    std::cout << myDict.select_range(15, 31, 7, 1) << "\n";
    std::cout << myDict.rank(31, 1) << "\n";
    std::cout << myDict.rank_range(15, 31, 1) << "\n";

    myDict.printLookupTable(std::cout);


    return 0;
}