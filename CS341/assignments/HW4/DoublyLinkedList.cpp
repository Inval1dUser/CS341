#include "DoublyLinkedList.h"


//check if done correctly
void DoublyLinkedList::printList() {
    LinkedNode* tempNode = new LinkedNode();
    while(tempNode->hasNextLinkedNode()) {
        std::cout << tempNode->getValue() << "\n";
        tempNode = tempNode->getNextLinkedNode();
    }
    std::cout << tempNode->getValue() << "\n";
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data) {
     if (node == nullptr) {
        // Insert at the tail of the list
        LinkedNode* newNode = new LinkedNode(data);
        if (tail_ == nullptr) {
            // List is empty
            head_ = tail_ = newNode;
        } else {
            tail_->setNextLinkedNode(newNode);
            newNode->setPrevLinkedNode(tail_);
            tail_ = newNode;
        }
    } else {
        // Insert after the specified node
        insertAfterLinkedNode(node, data);
    }
}


void DoublyLinkedList::insertAfterLinkedNode(LinkedNode* node, int data) {
    if (node == nullptr) {
        std::cerr << "Error: Cannot insert after a null node." << std::endl;
        return;
    }

    LinkedNode* newNode = new LinkedNode(data);
    newNode->setPrevLinkedNode(node);
    newNode->setNextLinkedNode(node->getNextLinkedNode());

    if (node->getNextLinkedNode() != nullptr) {
        node->getNextLinkedNode()->setPrevLinkedNode(newNode);
    } else {
        // Update tail if we're at the end
        tail_ = newNode;
    }

    node->setNextLinkedNode(newNode);
}
void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode* node, int data) {
    if (node == nullptr) {
        std::cerr << "Error: Cannot insert before a null node." << std::endl;
        return;
    }

    LinkedNode* newNode = new LinkedNode(data);
    newNode->setNextLinkedNode(node);
    newNode->setPrevLinkedNode(node->getPrevLinkedNode());

    if (node->getPrevLinkedNode() != nullptr) {
        node->getPrevLinkedNode()->setNextLinkedNode(newNode);
    } else {
        // Update head if we're at the beginning
        head_ = newNode;
    }

    node->setPrevLinkedNode(newNode);
}