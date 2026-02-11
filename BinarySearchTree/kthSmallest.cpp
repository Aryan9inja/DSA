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

int solve(BinaryTreeNode<int>* root, int k, int& i) {
    if (root == NULL) return -1;

    // L
    int left = solve(root->left, k, i);

    if (left != -1) return left;

    // N
    i++;
    if (i == k) return root->data;

    // R
    return solve(root->right, k, i);
}

int solveOptimal(BinaryTreeNode<int>* root, int k, int& i) {
    BinaryTreeNode<int>* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {

            // If no left child, visit this node 
            // and go right
            i++;
            if (i == k) {
                return curr->data;
            }

            curr = curr->right;
        }
        else {

            // Find the inorder predecessor of curr
            BinaryTreeNode<int>* prev = curr->left;
            while (prev->right != nullptr &&
                prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
            else {

                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                i++;
                if (i == k) {
                    return curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solveOptimal(root, k, i);
}