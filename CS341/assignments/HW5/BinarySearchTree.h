#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}  // Constructor initializes an empty tree
    virtual ~BinarySearchTree();         

    // Insert a new value into the BST
    void insert(int data);

    // Helper methods
    TreeNode* getRoot() const { return root; }     // Returns the root node
    int height(TreeNode* node) const;                // Returns height of the tree
    int getRootData() const;                         // Returns data in the root node
    TreeNode* deleteNode(TreeNode * root, int data);
    void remove(int num);

    TreeNode* setLeftChild(TreeNode* root, int data); //sets the left child of the root to a node with data
    TreeNode* setRightChild(TreeNode* root, int data); //sets the right child of the root to a node with data
    TreeNode* getLeftChild(TreeNode* root);
    TreeNode* getRightChild(TreeNode* root); 
private:
    void deleteTree(TreeNode* node); //recursive function for destructor
protected:
    TreeNode* root;  // Root node of the BST
};

#endif