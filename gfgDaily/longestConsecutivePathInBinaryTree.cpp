#include<bits/stdc++.h>
using namespace std;

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
    void traverse(Node* curr, Node* parent, int currLen, int& longest) {
        if (curr == nullptr)
            return;

        if (parent && curr->data == parent->data + 1) {
            currLen++;
        }
        else {
            currLen = 1;
        }

        longest = max(longest, currLen);

        traverse(curr->left, curr, currLen, longest);
        traverse(curr->right, curr, currLen, longest);
    }

    int longestConsecutive(Node* root) {
        if (root == nullptr)
            return -1;

        int ans = 0;
        traverse(root, nullptr, 0, ans);

        return ans == 1 ? -1 : ans;
    }
};
