#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    // right to left traversal
    void solve(Node* root, vector<int> &ans, int level){
        if(root==NULL){
            return;
        }
        
        // Insert first element at new level
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};