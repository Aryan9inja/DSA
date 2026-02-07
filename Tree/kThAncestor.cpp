#include<bits/stdc++.h>
using namespace std;

// Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};

// your task is to complete this function
class Solution {
    // vector approach
    bool findPath(Node* root, int target, vector<int> &path) {
        if (root == NULL) return false;

        // Add current node to path
        path.push_back(root->data);

        // If target is found, stop recursion
        if (root->data == target) return true;

        // Check left and right subtrees
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }

        // Backtrack: Remove current node if target not found in this branch
        path.pop_back();
        return false;
    }
    
    // Recursive approach
    Node* solve(Node* root, int &k, int node){
        if(root==NULL) return NULL;
        
        if(root->data==node) return root;
        
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);
        
        if(leftAns!=NULL && rightAns==NULL){
            k--;
            if(k<=0){
                k=INT_MAX; // This is done to lock the answer
                return root;
            }
            return leftAns;
        }
        
        if(rightAns!=NULL && leftAns==NULL){
            k--;
            if(k<=0){
                k=INT_MAX; // This is done to lock the answer
                return root;
            }
            return rightAns;
        }
        
        return NULL;
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        Node* ans = solve(root, k, node);
        // ans->data == node is edge case
        // because k>=1
        // so if same thing is returned it means it was root node
        // so value of k does not matter
        // as root node has no ancestors
        if(ans==NULL || ans->data==node){
            return -1;
        }
        return ans->data;
        
        // // vector appch
        // vector<int> path;
        // if (!findPath(root, node, path)) {
        //     return -1; // Node not found
        // }

        // int n = path.size();
        // int ancestorIndex = n - 1 - k;

        // // If index is out of bounds, k-th ancestor doesn't exist
        // if (ancestorIndex < 0) {
        //     return -1;
        // }

        // return path[ancestorIndex];
    }
};
