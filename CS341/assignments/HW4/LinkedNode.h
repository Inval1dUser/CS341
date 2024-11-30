#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node {
    public:
        LinkedNode(int data = -1);
        LinkedNode(int data, LinkedNode* nextLinkedNode, LinkedNode* prevLinkedNode);
        ~LinkedNode();

        LinkedNode* getNextLinkedNode();
        void setNextLinkedNode(LinkedNode* node);
        bool hasNextLinkedNode();

        LinkedNode* getPrevLinkedNode(); 
        void setPrevLinkedNode(LinkedNode* prevLinkedNode); 
        bool hasPrevLinkedNode(); 

    private:
        LinkedNode* nextLinkedNode_;
        LinkedNode* prevLinkedNode_;
};

#endif // !LINKEDNODE_H
