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
    void solve(TreeNode* root, int row, int col, vector<tuple<int, int, int>>& nodes) {
        if (root == NULL) return;
        nodes.emplace_back(col, row, root->val);

        solve(root->left, row + 1, col - 1, nodes);
        solve(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col, row, val
        vector<tuple<int, int, int>> nodes;
        solve(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (auto [col, row, val] : nodes) {
            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }
};