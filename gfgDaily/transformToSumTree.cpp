#include<bits/stdc++.h>
using namespace std;

// Structure for Tree Node
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
    int solve(Node* root) {
        if (root == nullptr) return 0;

        int originalData = root->data;

        root->data = solve(root->left) + solve(root->right);

        return root->data + originalData;
    }

    void toSumTree(Node* root) {
        solve(root);
    }
};