#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Concept - first element of preorder gives root
// inorder is LNR so we can get left and right of root from here
class Solution {
    void createMapping(vector<int> &inorder,
    unordered_map<int,int> &nodeToInorderIndex){
        for(int i=0;i<inorder.size();i++){
            nodeToInorderIndex[inorder[i]]=i;
        }
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &preOrderIndex,
    int inOrderStart, int inOrderEnd, unordered_map<int,int> &nodeToInorderIndex,
    int size){
        if(preOrderIndex>=size || inOrderStart>inOrderEnd){
            return NULL;
        }
        
        int element = preorder[preOrderIndex++];
        Node* root = new Node(element);
        
        int position = nodeToInorderIndex[element];
        
        root->left=solve(inorder,preorder,preOrderIndex,inOrderStart,
        position-1,nodeToInorderIndex,size);
        root->right=solve(inorder,preorder,preOrderIndex,position+1,
        inOrderEnd,nodeToInorderIndex,size);
        
        return root;
    }
    
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex=0;
        int inOrderStart=0;
        int inOrderEnd=inorder.size()-1;
        int size=inorder.size();
        
        unordered_map<int,int> nodeToInorderIndex;
        createMapping(inorder,nodeToInorderIndex);
        
        Node* root=solve(inorder,preorder,preOrderIndex,inOrderStart,
        inOrderEnd,nodeToInorderIndex,size);
        
        return root;
    }
};