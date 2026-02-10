#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Purana level complete ho gya hai
            std::cout << "\n";
            if (!q.empty()) {
                // queue still have some child nodes
                q.push(NULL);
            }
        }

        else {
            std::cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) return;

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    std::cout << root->data << " ";
}

Node* addToBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->right = addToBST(root->right, data);
    else
        root->left = addToBST(root->left, data);

    return root;
}

void insertInput(Node*& root) {
    cout << "Enter input for the BST\n";
    cout << "Usage -> List of numbers ending with -1\n";

    int data;
    cin >> data;
    while (data != -1) {
        root = addToBST(root, data);
        cin >> data;
    }

    cout << "Binary tree has been constructed\n";
}

Node* minVal(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int x) {
    if (root == NULL) return NULL;

    if (root->data == x) {
        //--- 0 child ---
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //--- 1 child ---

        // Left child
        if(root->left && !root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        // Right child
        if(!root->left && root->right){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //--- 2 child ---
        if(root->left && root->right){
            // Return min value from right subtree 
            // Or return max val from left subtree
            Node* mini=minVal(root->right);
            root->data=mini->data;
            root->right=deleteFromBST(root->right,mini->data);
        }
    }
    else if(root->data>x){
        root->left=deleteFromBST(root->left,x);
        return root;
    }else{
        root->right=deleteFromBST(root->right,x);
        return root;
    }
}

int main() {
    Node* root = NULL;

    // Insert and construct BST
    insertInput(root);

    cout << "\nPrinting BST (Level Order)\n";
    levelOrderTraversal(root);

    cout << "\nPrinting BST (In Order)\n";
    inOrderTraversal(root);

    cout << "\nPrinting BST (Pre Order)\n";
    preOrderTraversal(root);

    cout << "\nPrinting BST (Post Order)\n";
    postOrderTraversal(root);

    cout << "\nMinimum Val is " << minVal(root)->data << "\n";
    cout << "\nMaximum Val is " << maxVal(root)->data << "\n";

    int deletionVal;
    cout<< "\nEnter a value to be deleted\n";
    cin>>deletionVal;
    cout<<"Deleting "<<deletionVal;
    root=deleteFromBST(root,deletionVal);
    cout << "\nPrinting BST (Level Order)\n";
    levelOrderTraversal(root);

    return EXIT_SUCCESS;
}