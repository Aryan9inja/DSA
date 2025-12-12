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

void levelOrderTraversal(node* root) {
    std::queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            // Purana level complete ho gya hai
            std::cout << "\n";
            if (!q.empty()) {
                // queue still have some child nodes
                q.push(nullptr);
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

void reverseLevelOrderTraversal(node* root) {
    std::queue<node*> q;
    std::stack<node*> st;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        st.push(curr);

        if (curr == nullptr) {
            if (!q.empty())
                q.push(nullptr);
        }
        else {
            if (curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
        }
    }

    while (!st.empty()) {
        if (st.top() == nullptr) {
            std::cout << "\n";
        }
        else {
            std::cout << st.top()->data << " ";
        }
        st.pop();
    }
}

int main() {
    node* root = nullptr;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // level order
    std::cout << "Printing the level order traversal output\n";
    levelOrderTraversal(root);

    // reverse level order
    std::cout << "Printing the reverse level order traversal output\n";
    reverseLevelOrderTraversal(root);
    return 0;
}