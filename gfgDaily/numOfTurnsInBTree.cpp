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
    Node* findLCA(Node* root, int p, int q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->data == p || root->data == q) {
            return root;
        }

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right) {
            return root;
        }

        return left ? left : right;
    }

    bool findPath(Node* root, int x, string& path) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == x) {
            return true;
        }

        path.push_back('L');
        if (findPath(root->left, x, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, x, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

    int countTurns(const string& path) {
        int turns = 0;

        for (int i = 1; i < path.size(); i++) {
            if (path[i] != path[i - 1]) {
                turns++;
            }
        }

        return turns;
    }

    int numberOfTurns(Node* root, int p, int q) {
        Node* lca = findLCA(root, p, q);

        string path1 = "";
        string path2 = "";

        findPath(lca, p, path1);
        findPath(lca, q, path2);

        int turns = 0;
        if (lca->data == p || lca->data == q) {
            turns = (lca->data == p) ? countTurns(path2) : countTurns(path1);
        }
        else {
            turns = countTurns(path1) + countTurns(path2) + 1;
        }

        return turns == 0 ? -1 : turns;
    }
};
