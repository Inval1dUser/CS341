#ifndef NODE_H
#define NODE_H

class Node {
    public:
        Node(int data = -1);
        ~Node();
        int getValue();
    private:
        int data_;
};

#endif // !NODE_H