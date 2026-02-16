#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int cntNodes(Node* root){
        if(root==NULL) return 0;
        
        int ans=cntNodes(root->left)+cntNodes(root->right)+1;
        return ans;
    }
    
    // check if complete binary tree
    bool isCBT(Node* root, int index, int cnt){
        if(root==NULL) return true;
        
        if(index>=cnt) return false;
        else{
            bool left=isCBT(root->left,2*index+1,cnt);
            bool right=isCBT(root->right,2*index+2,cnt);
            return left && right;
        }
    }
    
    bool isMaxOrder(Node* root){
        // leaf node
        if(!root->left && !root->right){
            return true;
        }
        
        // only left present
        if(root->right==NULL){
            return root->data > root->left->data;
        }else{
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            return left && right && 
                root->data > root->left->data &&
                root->data > root->right->data;
        }
    }
    
  public:
    bool isHeap(Node* root) {
        int index=0;
        int totalCnt=cntNodes(root);
        
        if(isCBT(root,index,totalCnt) && isMaxOrder(root)){
            return true;
        }
        return false;
    }
};