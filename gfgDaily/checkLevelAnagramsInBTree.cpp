#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }

        queue<Node*> q1;
        queue<Node*> q2;

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n = q1.size();
            int m = q2.size();

            if (n != m)
                return false;

            unordered_map<int, int> freq;

            for (int i = 0; i < n; i++) {
                Node* n1 = q1.front();
                Node* n2 = q2.front();

                q1.pop();
                q2.pop();

                freq[n1->data]++;
                freq[n2->data]--;

                if (n1->left != nullptr) {
                    q1.push(n1->left);
                }
                if (n1->right != nullptr) {
                    q1.push(n1->right);
                }
                if (n2->left != nullptr) {
                    q2.push(n2->left);
                }
                if (n2->right != nullptr) {
                    q2.push(n2->right);
                }
            }

            for (const auto& x : freq) {
                if (x.second != 0) {
                    return false;
                }
            }
        }

        return q1.empty() && q2.empty();
    }
};
