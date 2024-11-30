#include "RedBlackTree.h"

void RedBlackTree::insert(int data) {
    TreeNode* newNode = new TreeNode(data);
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = RED; // New nodes are initially RED

    TreeNode* parent = nullptr;
    TreeNode* current = root;

    if (root == nullptr) {  // If the tree is empty
        newNode->color = BLACK;; // The root is always BLACK
        root = newNode;
        return;
    }

    // Standard BST insertion
    while (current != nullptr) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Fix the red-black tree properties
    balanceColor(root, newNode);
}


void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode) {
    TreeNode* x = newNode;
    if(x->right == nullptr) {
        return;
    }

    TreeNode* y = newNode->right;
    x->right = y->left;
    if(y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nullptr) {
        root = y;
    } else if(x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode) {   
    TreeNode* y = newNode;
    if(y->left == nullptr) {
        return;
    }

    TreeNode* x = y->left;
    y->left = x->right;
    if(x->right != nullptr) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == nullptr) {
        root = x;
    }  else if(y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode) {
    while(newNode != getRoot() && newNode->parent->getColor() == RED) {
        TreeNode* parent = newNode->parent; //for easier reading
        TreeNode* grandparent = parent->parent;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(grandparent == nullptr) {
            break;
        }
        

        if(parent == grandparent->left) {
            TreeNode* uncle = grandparent->right;
            if(uncle != nullptr && uncle->color == RED) {
                //case 3
                parent->color = BLACK;;
                uncle->color = BLACK;;
                grandparent->color = RED;;
                newNode = grandparent;
            } else {
                //case 4 subcases
                if(newNode = parent->right) {
                    //case 4a
                    newNode = parent;
                    rotateLeft(root, newNode);
                }
                //case 4b
                parent->color = BLACK;;
                grandparent->color = RED;;
                rotateRight(root, grandparent);
            }
        } else {
            //Mirror cases
            TreeNode* uncle = grandparent->left;
            if(uncle != nullptr && uncle->color == RED) {
                //case 3
                parent->color = BLACK;;
                uncle->color = BLACK;;
                grandparent->color = RED;;
                newNode = grandparent;
            } else {
                if(parent->left == nullptr) break;
                if(parent->left != nullptr && newNode == parent->left) {
                    //case 4c
                    newNode = parent;
                    rotateRight(root, newNode);
                }
                parent->color = BLACK;;
                grandparent->color = RED;;
                rotateLeft(root, grandparent);
            }
        }
        root->color = BLACK;;
    }
}