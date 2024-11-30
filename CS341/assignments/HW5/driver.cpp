#include <iostream>
#include <fstream>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main() {

    std::fstream data("data.txt");
    std::string dataStr;
    BinarySearchTree* newTree = new BinarySearchTree();
    RedBlackTree RBT;

    while(data) {
        getline(data, dataStr);
        RBT.insert(stoi(dataStr));
    }
    

    std::cout << RBT.root->data << std::endl;
    

    
     
    
    return 0;
}