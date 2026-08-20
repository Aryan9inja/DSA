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
    int maxi;

    int solve(Node* root) {
        if (root == nullptr) {
            return INT_MAX;
        }

        int leftMin = solve(root->left);
        int rightMin = solve(root->right);

        int currentMin = min({ root->data, leftMin, rightMin });

        if (leftMin != INT_MAX) {
            maxi = max(maxi, root->data - leftMin);
        }
        if (rightMin != INT_MAX) {
            maxi = max(maxi, root->data - rightMin);
        }

        return currentMin;
    }

    int maxDiff(Node* root) {
        maxi = INT_MIN;
        solve(root);
        return maxi;
    }
};
