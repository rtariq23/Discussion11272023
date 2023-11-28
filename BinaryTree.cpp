//
// Created by Sharookan on 11/27/2023.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;
void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr){
    if(nullptr == aNodePtr){
        aNodePtr = aNewNodePtr;
    } else if(aNewNodePtr->val < aNodePtr->val){
        insert(aNodePtr->left, aNewNodePtr);
    } else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}
void BinaryTree::deleteNode(int aVal, Node* &aNodePtr){
    if(aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    } else if(aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    } else {
        makeDeletion(aNodePtr);
    }
}
void BinaryTree::makeDeletion(Node* &aNodePtr){
    Node* tempNodePtr = nullptr;
    if(nullptr == aNodePtr){
        cout << "Can not remove empty Node" << endl;
    } else if(nullptr == aNodePtr->right){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    } else if(nullptr == aNodePtr->left){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    } else {
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}
BinaryTree::BinaryTree(){
    root = nullptr;
}
void BinaryTree::insertNode(int aVal){
    Node *newNode = new Node(aVal);
    insert(root, newNode);
}
bool BinaryTree::searchNode(int aVal){
    Node* currentNodePtr = root;
    while(currentNodePtr){
        if(aVal == currentNodePtr->val){
            return true;
        } else if(aVal < currentNodePtr->val){
            currentNodePtr = currentNodePtr->left;
        } else {
            currentNodePtr = currentNodePtr->right;
        }
    }
    return false;
};
void BinaryTree::remove(int aVal){
    deleteNode(aVal, root);
};
void BinaryTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        std::cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinaryTree::printTree(){
    displayInOrder(root);
    std::cout << std::endl;
};