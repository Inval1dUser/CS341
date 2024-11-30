#include "Node.h"

Node::Node(int data) : data_(data) {}

Node::~Node() {}

int Node::getValue() {
    return data_;
}