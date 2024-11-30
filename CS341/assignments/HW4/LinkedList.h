#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"
#include <iostream>

class LinkedList : LinkedNode {
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty(); 
        int getLength(); 
        void insert(int element); 
        void printList();

        friend class DoublyLinkedList;
    private:
        LinkedNode* head_;
        LinkedNode* tail_;
};

#endif // !LINKEDLIST_H
