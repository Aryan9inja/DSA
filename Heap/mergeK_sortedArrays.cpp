#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Insert first element of all arrays into heap
    for (int i = 0;i < k;i++) {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while (!minHeap.empty()) {
        Node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->row;
        int j = tmp->col;

        if (j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}
