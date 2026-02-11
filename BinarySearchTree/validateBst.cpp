#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// Approach 1 = Inorder traversal of a BST is sorted

bool isBST(BinaryTreeNode<int>* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data); // Max range shrinks
        bool right = isBST(root->right, root->data, max); // Min range shrinks
        return left && right;
    }
    else {
        return false;
    }
}

bool validateBST(BinaryTreeNode<int>* root) {
    bool res = isBST(root, INT_MIN, INT_MAX);
    return res;
}