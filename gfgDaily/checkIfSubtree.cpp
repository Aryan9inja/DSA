#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

class Solution {
private:
    bool isIdentical(Node *root1, Node *root2){
        // Both null
        if(root1 == nullptr && root2 == nullptr) return true;
        
        // One null
        if(root1 == nullptr || root2 == nullptr) return false;
        
        return (
            root1->data == root2->data &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right)
        );
    }
    
public:
    bool isSubTree(Node *root1, Node *root2) {
        if(root2 == nullptr) return true;
        
        if(root1 == nullptr) return false;
        
        if(isIdentical(root1, root2)){
            return true;
        }
        
        return (isSubTree(root1->left, root2) || isSubTree(root1->right, root2));
    }
};