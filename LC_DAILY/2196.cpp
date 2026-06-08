#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;

        // 0 -> Node not touched
        // 1 -> Potential root
        // -1 -> Has a parent
        unordered_map<int, int> root;

        for (auto& d : descriptions) {
            // Creating nodes that don't exist
            if (mp[d[0]] == 0) {
                TreeNode* temp = new TreeNode(d[0]);
                mp[d[0]] = temp;
            }

            if (mp[d[1]] == 0) {
                TreeNode* temp = new TreeNode(d[1]);
                mp[d[1]] = temp;
            }

            // Connecting nodes
            if (d[2] == 1) {
                mp[d[0]]->left = mp[d[1]];
            }
            else {
                mp[d[0]]->right = mp[d[1]];
            }

            // Checking root
            if (root[d[0]] != -1) {
                root[d[0]] = 1;
            }
            root[d[1]] = -1;
        }

        int val = 0;

        for (auto& it : root) {
            if (it.second == 1) {
                val = it.first;
                break;
            }
        }

        return mp[val];
    }
};