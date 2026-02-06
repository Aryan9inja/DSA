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
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        // horizontal distance, node ka data
        map<int,int> topNodes;
        // Node, horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            // If map entry for hd is not empty, do nothing
            if(topNodes.find(hd)==topNodes.end()){
                topNodes[hd]=frontNode->data;
            }
            
            if(frontNode->left){
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }
        }
        
        for(auto it:topNodes){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};