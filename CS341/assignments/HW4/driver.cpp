#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    LinkedList* newList = new LinkedList();
    newList->insert(23);
    newList->insert(12);
    newList->insert(15);
    newList->insert(18);

    std::cout << "List contents:" << std::endl;
    newList->printList();

    std::cout << "List length: " << newList->getLength() << std::endl;
 
    delete newList;
   
    return 0;
}
