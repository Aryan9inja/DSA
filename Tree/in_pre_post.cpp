#include <iostream>
#include <queue>
#include <stack>

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->right = nullptr;
        this->left = nullptr;
    }
};

node* buildTree(node* root) {
    std::cout << "Enter the data:\n";
    int data;
    std::cin >> data;
    root = new node(data);

    if (data == -1) {
        return nullptr;
    }

    std::cout << "Inserting in left of" << data << ":\n";
    root->left = buildTree(root->left);
    std::cout << "Inserting in right of" << data << ":\n";
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(node* root){
    if(root==nullptr) return;

    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node* root){
    if(root==nullptr) return;

    std::cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==nullptr) return;

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    std::cout<<root->data<<" ";
}

int main() {
    node* root = nullptr;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // InOrderTraversal
    inOrderTraversal(root);
    std::cout<<"\n";
    
    // PreOrderTraversal
    preOrderTraversal(root);
    std::cout<<"\n";
    
    // PostOrderTraversal
    postOrderTraversal(root);
    std::cout<<"\n";
    return 0;
}