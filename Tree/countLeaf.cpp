template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void inOrder(BinaryTreeNode<int>* root, int& count) {
    if (root == nullptr) return;

    inOrder(root->left, count);

    if (root->left == nullptr && root->right == nullptr) {
        count++;
    }

    inOrder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int>* root) {
    int count = 0;
    inOrder(root, count);
    return count;
}