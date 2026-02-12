#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void createInorder(TreeNode<int>* root, vector<int>& in) {
    TreeNode<int>* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            in.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode<int>* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                in.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    // Inorder is always sorted
    vector<int> inorderVals;
    createInorder(root, inorderVals);
    int n = inorderVals.size();
    // delete root;

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVals[0]);
    TreeNode<int>* curr = newRoot;

    for (int i = 1;i < n;i++) {
        TreeNode<int>* temp = new TreeNode<int>(inorderVals[i]);

        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
