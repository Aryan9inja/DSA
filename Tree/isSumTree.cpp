#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    pair<bool,int> isSumTreeFast(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0); // isSumTree, sum
            return p;
        }else if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data); // isSumTree, sum
            return p;
        }
        
        pair<bool,int> leftAns=isSumTreeFast(root->left);
        pair<bool,int> rightAns=isSumTreeFast(root->right);
        
        bool left=leftAns.first;
        bool right=rightAns.first;
        bool condition=root->data==leftAns.second+rightAns.second;
        
        pair<bool,int> ans;
        if(left && right && condition){
            ans.first=true;
            ans.second=2*root->data;
        }else{
            ans.first=false;
        }
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreeFast(root).first;
    }
};