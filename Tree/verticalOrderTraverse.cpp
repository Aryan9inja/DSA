#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Horizontal Diffrence, level, data
        map<int, map<int, vector<int> > > nodes;
        
        // Node, Horizontal Diffrence, level
        queue<pair<Node*, pair<int, int> > > q;
        
        // Answer vector
        vector<vector<int> > ans;
        
        if(root == NULL) return ans;
        
        // Add root node
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int horizontalDistance = temp.second.first;
            int level = temp.second.second;
            
            nodes[horizontalDistance][level].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(horizontalDistance-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(horizontalDistance+1,level+1)));
            }
        }
        
        for(auto i : nodes) {
            vector<int> col;
            for(auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};