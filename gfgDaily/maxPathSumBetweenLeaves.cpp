#include<bits/stdc++.h>
using namespace std;

struct Node {
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
    int maxPathSumUtil(Node* root, int& res) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return root->data;

        int leftSum = maxPathSumUtil(root->left, res);
        int rightSum = maxPathSumUtil(root->right, res);

        if (root->left && root->right) {

            // Combine both root-to-leaf paths through the current node.
            res = max(res, leftSum + rightSum + root->data);
            return max(leftSum, rightSum) + root->data;
        }

        if (root->left)
            return leftSum + root->data;

        return rightSum + root->data;
    }

    int maxPathSum(Node* root) {
        if (root == nullptr)
            return -1;

        int res = INT_MIN;
        maxPathSumUtil(root, res);

        return res == INT_MIN ? -1 : res;
    }
};
