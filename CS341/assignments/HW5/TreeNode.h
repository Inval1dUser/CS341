#ifndef TREENODE_H
#define TREENODE_H

enum Color { RED, BLACK };  // Enum for node color

class TreeNode {
public:
    TreeNode* parent;
    int data;                  
    Color color;               
    TreeNode* left;            
    TreeNode* right;                

    TreeNode(int value, Color nodeColor = RED)
        : data(value), color(nodeColor), left(nullptr), right(nullptr), parent(nullptr) {}

    // Destructor (virtual to support inheritance if needed)
    virtual ~TreeNode() = default;

    Color getColor() const { return color; }
    void setColor(Color c) { color = c; }
};

#endif
