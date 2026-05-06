#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int getSize(Node* root) {
        if (root == NULL) return 0;

        int leftSide = getSize(root->left);

        int rightSide = getSize(root->right);

        return leftSide + rightSide + 1;
    }
};