#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Edge based
    int height(Node* root) {
        // code here
        if (root == NULL) {
            return -1;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        int ans = max(leftH, rightH) + 1;
        return ans;
    }

    // Root based
    int height(Node* root) {
        // code here
        if (root == NULL) {
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        int ans = max(leftH, rightH) + 1;
        return ans;
    }
};