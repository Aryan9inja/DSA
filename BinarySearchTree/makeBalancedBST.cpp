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

TreeNode<int>* inorderToBST(int s, int e, vector<int>& inorderVals) {
    if (s > e) return NULL;

    int mid = (s + e) / 2;
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVals[mid]);
    newRoot->left = inorderToBST(s, mid - 1, inorderVals);
    newRoot->right = inorderToBST(mid + 1, e, inorderVals);
    return newRoot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Inorder is always sorted
    vector<int> inorderVals;
    createInorder(root, inorderVals);
    int n = inorderVals.size();
    // delete root;

    return inorderToBST(0, n - 1, inorderVals);
}
