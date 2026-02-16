#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void inorderTraverse(Node* root, vector<int> &arr){
    if(root==NULL){
        return;
    }
    inorderTraverse(root->left,arr);
    arr.push_back(root->data);
    inorderTraverse(root->right,arr);
}

void preorderFill(Node* root, vector<int> &arr,int &idx){
    if(root==NULL) return;

    root->data=arr[idx++];
    preorderFill(root->left,arr,idx);
    preorderFill(root->right,arr,idx);
}

// Given BST is complete
// So structure of tree will not change
// to fulfill left<right and minHeap we will use preorder to fill the tree
void convertBSTtoMinHeap(Node* root){
    vector<int> inorderArr;

    inorderTraverse(root, inorderArr);

    int idx=0;
    preorderFill(root,inorderArr,idx);
}

void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}

int main() {
  
    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTtoMinHeap(root);
    preorderPrint(root);

    return 0;
}