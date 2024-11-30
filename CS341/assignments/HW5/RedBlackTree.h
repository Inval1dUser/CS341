#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : BinarySearchTree {
    public:
    TreeNode* root;
    RedBlackTree() : root(nullptr) {}
    virtual ~RedBlackTree() = default;
    virtual void insert(int data);

    private: 
    void rotateLeft(TreeNode *& root, TreeNode *& newNode); 
    void rotateRight(TreeNode *& root, TreeNode *& newNode); 

    void balanceColor(TreeNode *& root, TreeNode *& newNode); 
};

#endif // !REDBLACKTREE_H