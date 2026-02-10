#include <vector>
#include <iostream>
using namespace std;

// Node Structure
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
//Driver Code Ends

// Finding predecessor of key
Node* findPredecessor(Node* root, int key) {
    Node* predecessor = NULL;
    while (root) {
        if (key > root->data) {
            
            // potential predecessor
            predecessor = root;
            
            // look for larger predecessors
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

// Finding successor of key
Node* findSuccessor(Node* root, int key) {
    Node* successor = NULL;
    while (root) {
        if (key < root->data) {
            
            // potential successor
            successor = root;
            
            // look for smaller successor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// return vector with predecessor at index 0 
// and successor at index 1
vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = findPredecessor(root, key);
    Node* suc = findSuccessor(root, key);
    return {pre, suc};
}

//Driver Code Starts
int main() {
    
    // Create BST:
    //      50 
    //     /  \
    //   30     70
    //   / \    / \
    // 20  40  60  80
    
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 65;
    vector<Node*> result = findPreSuc(root, key);
    Node* pre = result[0];
    Node* suc = result[1];

    cout << (pre ? to_string(pre->data) : string("NULL")) << " "
     << (suc ? to_string(suc->data) : string("NULL"));

    return 0;
}