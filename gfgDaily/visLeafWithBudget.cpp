#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int getCount(Node* root, int k) {

        if (!root)
            return 0;

        queue<Node*> q;
        q.push(root);

        int level = 1;
        int cnt = 0;

        while (!q.empty()) {
            int size = q.size();
            int leafCount = 0;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (!curr->left && !curr->right)
                    leafCount++;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            int canVisit = k / level;

            int take = min(leafCount, canVisit);

            cnt += take;
            k -= take * level;

            if (k < level)
                break;

            level++;
        }

        return cnt;
    }

};
