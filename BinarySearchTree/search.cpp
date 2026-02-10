#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left, * right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right) : data(x), left(left), right(right) {}
};


bool searchInBST(BinaryTreeNode<int>* root, int x) {
    BinaryTreeNode<int>* temp = root;

    while (temp != NULL) {
        if (temp->data == x) {
            return true;
        }
        else if (temp->data > x) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}