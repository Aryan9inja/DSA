#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Traverse the entire right chain
            while (curr) {
                ans.push_back(curr->data);

                // Left child starts a new diagonal
                if (curr->left) {
                    q.push(curr->left);
                }

                curr = curr->right;
            }
        }

        return ans;
    }
};