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
    // O (N.H) - TC
    // O (H) - SC
    void solve(Node* root, int k, vector<int> &path, int &count){
        if(root==NULL) return;
        
        path.push_back(root->data);
        
        // check for k sum
        int sum = 0;
        int size = path.size();
        for(int i = size-1 ; i >= 0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        
        solve(root->left, k, path, count);
        solve(root->right, k, path, count);
        
        path.pop_back();
    }
    
    void solveOptimal(Node* root, int k, unordered_map<int,int> &prefix_sums, int currSum, int &count){
        if(root==NULL) return;
        
        currSum+=root->data;
        
        if(currSum==k){
            count++;
        }
        
        // Check if (current_sum - k) exists in our map
        // This represents a sub-path within the current branch that sums to k
        if(prefix_sums.find(currSum-k)!=prefix_sums.end()){
            count+=prefix_sums[currSum-k];
        }
        
        prefix_sums[currSum]++;
        
        solveOptimal(root->left, k, prefix_sums, currSum, count);
        solveOptimal(root->right, k, prefix_sums, currSum, count);
        
        prefix_sums[currSum]--;
    }
    
  public:
    int countAllPaths(Node *root, int k) {
        // vector<int> path;
        unordered_map<int,int> prefix_sums;
        int currSum=0;
        int count = 0;
        // solve(root, k, path, count);
        solveOptimal(root, k, prefix_sums, currSum, count);
        return count;
    }
};