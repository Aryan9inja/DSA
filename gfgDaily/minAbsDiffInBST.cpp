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
    void inorder(Node* curr, Node*& prev, int& ans) {
        if (curr == nullptr) {
            return;
        }

        inorder(curr->left, prev, ans);

        if (prev != nullptr) {
            ans = min(ans, curr->data - prev->data);
        }
        prev = curr;

        inorder(curr->right, prev, ans);
    }

    int absDiff(Node* root) {
        Node* prev = nullptr;
        int ans = INT_MAX;

        inorder(root, prev, ans);
        return ans;
    }
};