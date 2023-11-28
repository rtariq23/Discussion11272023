//
// Created by Sharookan on 11/27/2023.
//


#ifndef DISCUSSION11272023_BINARYTREE_H
#define DISCUSSION11272023_BINARYTREE_H
class BinaryTree{
private:
    struct Node{
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* left_ = nullptr, Node* right_ = nullptr){
            val = aVal;
            left = left_;
            right = right_;
        }
    };

    Node* root;
private:
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();
};
#endif //DISCUSSION11272023_BINARYTREE_H


