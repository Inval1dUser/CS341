#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include <iostream>

class DoublyLinkedList : LinkedList {

void printList();
void insertLinkedNode(LinkedNode * node, int data);
void insertAfterLinkedNode(LinkedNode * node, int data);
void insertBeforeLinkedNode(LinkedNode * node, int data);

};

#endif // DOUBLYLINKEDLIST_H