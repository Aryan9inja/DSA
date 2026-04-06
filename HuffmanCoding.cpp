#include<bits/stdc++.h>
using namespace std;

// Class to represent Huffman tree node
class Node {
public:
    // frequency
    int data;

    // smallest original index in subtree
    int index;

    Node* left, * right;

    // Leaf node
    Node(int d, int i) {
        data = d;
        index = i;
        left = right = nullptr;
    }

    // Internal node
    Node(Node* l, Node* r) {
        data = l->data + r->data;

        // important for tie-break
        index = min(l->index, r->index);
        left = l;
        right = r;
    }
};

// Custom min heap for Node class
class Compare {
public:
    bool operator() (Node* a, Node* b) {
        // smaller freq first
        if (a->data != b->data)
            return a->data > b->data;
        // when freq are equal
        return a->index > b->index;
    }
};

// Function to traverse tree in preorder
// manner and push the Huffman representation
// of each character.
void preOrder(Node* root, vector<string>& ans, string curr) {
    if (root == nullptr) return;

    // Leaf node represents a character.
    if (root->left == nullptr && root->right == nullptr) {
        // single character case
        if (curr == "") curr = "0";
        ans.push_back(curr);
        return;
    }

    preOrder(root->left, ans, curr + '0');
    preOrder(root->right, ans, curr + '1');
}

vector<string> huffmanCodes(string& s, vector<int> freq) {

    int n = s.length();

    // Min heap for Node class.
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        // include index
        Node* tmp = new Node(freq[i], i);
        pq.push(tmp);
    }

    // single character
    if (n == 1)
        return { "0" };

    // Construct Huffman tree.
    while (pq.size() >= 2) {

        // Left node
        Node* l = pq.top();
        pq.pop();

        // Right node
        Node* r = pq.top();
        pq.pop();

        // internal node with freq + index   
        Node* newNode = new Node(l, r);
        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    preOrder(root, ans, "");
    return ans;
}