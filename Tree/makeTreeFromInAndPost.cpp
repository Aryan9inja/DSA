#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
    void createMapping(vector<int> &inorder,
    unordered_map<int,int> &nodeToInorderIndex){
        for(int i=0;i<inorder.size();i++){
            nodeToInorderIndex[inorder[i]]=i;
        }
    }
    
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &postOrderIndex,
    int inOrderStart, int inOrderEnd, unordered_map<int,int> &nodeToInorderIndex){
        if(postOrderIndex < 0 || inOrderStart>inOrderEnd){
            return NULL;
        }
        
        int element = postorder[postOrderIndex--];
        Node* root = new Node(element);
        
        int position = nodeToInorderIndex[element];
        
        root->right=solve(inorder,postorder,postOrderIndex,position+1,
        inOrderEnd,nodeToInorderIndex);
        root->left=solve(inorder,postorder,postOrderIndex,inOrderStart,
        position-1,nodeToInorderIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int postOrderIndex=postorder.size()-1;
        int inOrderStart=0;
        int inOrderEnd=inorder.size()-1;
        
        unordered_map<int,int> nodeToInorderIndex;
        createMapping(inorder,nodeToInorderIndex);
        
        Node* root=solve(inorder,postorder,postOrderIndex,inOrderStart,
        inOrderEnd,nodeToInorderIndex);
        
        return root;
    }
};