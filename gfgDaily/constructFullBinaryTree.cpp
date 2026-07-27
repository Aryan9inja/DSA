#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* buildTree(vector<int>& pre, vector<int>& preMirror, int& preIndex, int left,
        int right, unordered_map<int, int>& mp, int n) {
        if (preIndex >= n || left > right)
            return nullptr;

        // Create current node
        Node* root = new Node(pre[preIndex++]);

        // If leaf node
        if (left == right)
            return root;

        // Find next preorder element index in preMirror
        int mirrorIndex = mp[pre[preIndex]];

        // Construct left and right subtree
        if (mirrorIndex >= left && mirrorIndex <= right) {

            // Construct left subtree
            root->left = buildTree(pre, preMirror, preIndex, mirrorIndex, right, mp, n);

            // Construct right subtree
            root->right =
                buildTree(pre, preMirror, preIndex, left + 1, mirrorIndex - 1, mp, n);
        }

        return root;
    }

    // Wrapper function to construct binary tree
    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();

        // Store indices of mirror preorder traversal
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[preMirror[i]] = i;
        }

        int preIndex = 0;

        return buildTree(pre, preMirror, preIndex, 0, n - 1, mp, n);
    }
};
