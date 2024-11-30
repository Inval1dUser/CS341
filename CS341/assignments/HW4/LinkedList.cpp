#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr) {}

LinkedList::~LinkedList() {
    LinkedNode* current = head_;
    while (current != nullptr) {
        LinkedNode* next = current->getNextLinkedNode();
        delete current;
        current = next;
    }
}

bool LinkedList::isEmpty() {
    return head_ == nullptr;
}

int LinkedList::getLength() {
    int count = 0;
    LinkedNode* current = head_;
    while (current != nullptr) {
        current = current->getNextLinkedNode();
        count++;
    }
    return count;
}

void LinkedList::insert(int element) {
    LinkedNode* newNode = new LinkedNode(element, nullptr, nullptr);
    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } else {
        tail_->setNextLinkedNode(newNode);
        newNode->setPrevLinkedNode(tail_);
        tail_ = newNode;
    }
}

void LinkedList::printList() {
    LinkedNode* current = head_;
    while (current != nullptr) {
        std::cout << current->getValue() << std::endl;
        current = current->getNextLinkedNode();
    }
}


/* earth from the moon                                            
     *   .                  .              .        .   *          .
  .         .                     .       .           .      .        .
         .                             .                   .
                        .                  .           .
                .                    
                 .          .       |         ,                ,    ,
 .                     .          - * -             .
      .          ,                  |
   .                .                                    .            .
     .        *                   ,             .                .
                           .                              .        .
                  .                      .                        .
   .                                            .                      ,
        .          .                     .                 .
      .      .                    .                           ,       .
          .                 .                    .             .          ,
                                 .    
   *         _____
          .-'.  ':'-.        .                       .            .       
        .''::: .:    '.
       /   :::::'      \        .        .                .            .
      ;.    ':' `       ;        *
      |       '..       |     .                .        *              .    .
____^/\___^--____/\____O______________/\/\---/\_____________________________
   /\^   ^  ^    ^                  ^^ ^  '\ ^           ---
         --         -           --  -      -         ---  __       ^
   --  __                         ___--  ^  ^                         --  __
            ~neil wuz here~
 
*/
