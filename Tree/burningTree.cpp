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
    Node* createMapping(Node* root, int target,
    unordered_map<Node*, Node*> &nodeToParent){
        queue<Node*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        Node* res=NULL;
        
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
            }
            
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, unordered_map<Node*, Node*> &nodeToParent){
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=true;
        
        int ans=0;
        
        while(!q.empty()){
            int size=q.size();
            bool flag=0; // To check if insertion in queue happened
            
            for(int i=0;i<size;i++){
                // process neibhoring nodes
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    visited[front->left]=1;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    visited[front->right]=1;
                    q.push(front->right);
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=1;
                    visited[nodeToParent[front]]=1;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
    
  public:
    int minTime(Node* root, int target) {
        // Create node to parent mapping for checking parent node
        // get the position of target node
        // burn the tree in minimum time
        
        unordered_map<Node*, Node*> nodeToParent;
        Node* targetNode=createMapping(root, target, nodeToParent);
        int ans=burnTree(targetNode, nodeToParent);
        return ans;
    }
};