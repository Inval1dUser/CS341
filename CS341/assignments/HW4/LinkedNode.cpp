#include "LinkedNode.h"

LinkedNode::LinkedNode(int data, LinkedNode* nextLinkedNode, LinkedNode* prevLinkedNode)
    : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode) {}

LinkedNode::LinkedNode(int data)
    : Node(data), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr) {}

LinkedNode::~LinkedNode() {
    nextLinkedNode_ = nullptr;
    prevLinkedNode_ = nullptr;
}

bool LinkedNode::hasNextLinkedNode() {
    return nextLinkedNode_ != nullptr;
}

LinkedNode* LinkedNode::getNextLinkedNode() {
    return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode* node) {
    nextLinkedNode_ = node;
}

LinkedNode* LinkedNode::getPrevLinkedNode() {
    return prevLinkedNode_;
}

bool LinkedNode::hasPrevLinkedNode() {
    return prevLinkedNode_ != nullptr;
}

void LinkedNode::setPrevLinkedNode(LinkedNode* prevLinkedNode) {
    prevLinkedNode_ = prevLinkedNode;
}
