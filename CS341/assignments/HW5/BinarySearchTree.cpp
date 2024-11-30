#include "BinarySearchTree.h"
#include <algorithm>

// Destructor to free up the tree nodes (simple delete recursive function)
BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(TreeNode* node) {
    if(node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Insert a new node with `data` into the BST
void BinarySearchTree::insert(int data) {
    TreeNode* newNode = new TreeNode(data);
    newNode->setColor(RED);  // New nodes are inserted as RED
    if (!root) {
        root = newNode;
        root->setColor(BLACK);  // Root is always BLACK
        return;
    }
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (current) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return;  // Duplicate data not allowed
    }
    newNode->parent = parent;
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

}


// Returns the data stored in the root node (if it exists)
int BinarySearchTree::getRootData() const {
    if(!root) return -1; // Return -1 if the root is null
    return root->data;
}

// Returns the height of the tree from the specified node
int BinarySearchTree::height(TreeNode* node) const {
    if (!node) return 0;
    return (std::max(height(node->left), height(node->right))) + 1;
}

void BinarySearchTree::remove(int num) {
    root = deleteNode(root, num);
}

TreeNode * BinarySearchTree::deleteNode(TreeNode * root, int data) {

    if(!root) {
        return nullptr;
    } else {
        if(data < root->data) {
            //left subtree
            root->left = deleteNode(root->left, data);
        } else if(data > root->data) {
            //right subtree
            root->right = deleteNode(root->right, data);
        } else {
            if(!(root->left) && !(root->right)) {
                delete root;
                return nullptr;
            } else if (!(root->left)) {
                TreeNode* node = root->right;
                delete root;
                return node;
            } else if(!(root->right)) {
                TreeNode * node = root->left;
                delete root;
                return node;
            } else {
                //Two Children Case
                TreeNode * node = root->right;
                while(node != nullptr && node->left != nullptr) {
                    node = node->left;
                }
                root->data = node->data;
                root->right = deleteNode(root->right, node->data);
            }
        }
    }

    return root;
}

TreeNode* BinarySearchTree::setLeftChild(TreeNode* root, int data) {
    TreeNode* newNode = new TreeNode(data);
    if(!(root->left)) {
        root->left = newNode;
        return newNode;
    }
}

TreeNode* BinarySearchTree::setRightChild(TreeNode* root, int data) {
    TreeNode* newNode = new TreeNode(data);
    if(!(root->right)) {
        root->right = newNode;
        return newNode;
    }
}

TreeNode* BinarySearchTree::getLeftChild(TreeNode* root) {
    if(root->left) return root->left;
    else if(!(root->left)) return nullptr;
}
TreeNode* BinarySearchTree::getRightChild(TreeNode* root) {
    if(root->right) return root->right;
    if(!(root->right)) return nullptr;

}