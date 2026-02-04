#include<stdio.h>
#include<algorithm>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// O(n^2)
class Solution1 {
    int height(Node* root) {
        // code here
        if(root == NULL){
            return -1;
        }
        
        int leftH=height(root->left);
        int rightH=height(root->right);
        
        int ans = max(leftH,rightH)+1;
        return ans;
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL) return true;
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }else{
            return false;
        }
    }
};

// O(n)
class Solution2 {
    pair<bool,int> isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0); // IsBalanced, Height
            return p;         
        }
        
        pair<int,int> left=isBalancedFast(root->left);
        pair<int,int> right=isBalancedFast(root->right);
        
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool diff=abs(left.second-right.second)<=1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first=true;
        }else{
            ans.second=false;
        }
        return ans;
    }
  public:
    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
    }
};