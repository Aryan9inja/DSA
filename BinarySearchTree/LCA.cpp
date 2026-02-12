#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left, * right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : data(x), left(left), right(right) {}
};

TreeNode* LCAinaBST(TreeNode* root, TreeNode* P, TreeNode* Q) {
    // O(n), O(n)
    if(root==NULL) return NULL;

    if(root->data > P->data && root->data > Q->data){
        // left part
        return LCAinaBST(root->left, P, Q);
    }

    if(root->data < P->data && root->data < Q->data){
        // right part
        return LCAinaBST(root->right, P, Q);
    }

    // Else root is LCA
    return root;
}

TreeNode* LCA_IN_BST(TreeNode* root, TreeNode* P, TreeNode*Q){
    // O(n), O(1)
    while (root != NULL) {
        if (root->data > P->data && root->data > Q->data) {
            // left part
            root = root->left;
        }
        else if (root->data < P->data && root->data < Q->data) {
            // right part
            root = root->right;
        }
        else {
            return root;
        }
    }
}