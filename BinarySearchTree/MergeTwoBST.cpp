#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left, * right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : data(x), left(left), right(right) {}
};

class Solution {
private:
    void BstToSortedArray(TreeNode* root, vector<int>& sorted) {
        if (root == NULL) {
            return;
        }

        BstToSortedArray(root->left, sorted);
        sorted.push_back(root->data);
        BstToSortedArray(root->right, sorted);
    }

    vector<int> mergeSortedArrays(vector<int>& sorted1, vector<int>& sorted2) {
        vector<int> ans;
        int n1 = sorted1.size();
        int n2 = sorted2.size();

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (sorted1[i] < sorted2[j]) {
                ans.push_back(sorted1[i++]);
            }
            else {
                ans.push_back(sorted2[j++]);
            }
        }

        while (i < n1) {
            ans.push_back(sorted1[i++]);
        }

        while (j < n2) {
            ans.push_back(sorted2[j++]);
        }

        return ans;
    }

    TreeNode* inorderToBST(int s, int e, vector<int>& inorderVals) {
        if (s > e) return NULL;

        int mid = (s + e) / 2;
        TreeNode* newRoot = new TreeNode(inorderVals[mid]);
        newRoot->left = inorderToBST(s, mid - 1, inorderVals);
        newRoot->right = inorderToBST(mid + 1, e, inorderVals);
        return newRoot;
    }

    void BstToDLL(TreeNode* root, TreeNode*& head) {
        if (root == NULL) {
            return;
        }

        BstToDLL(root->right, head);
        root->right = head;

        if (head != NULL) head->left = root;

        head = root;

        BstToDLL(root->left, head);
    }

    TreeNode* mergeSortedLL(TreeNode* head1, TreeNode* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        TreeNode* head = NULL;
        TreeNode* tail = NULL;
        while (head1 != NULL && head2 != NULL) {
            if (head1->data < head2->data) {
                if (head == NULL) {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            }
            else {
                if (head == NULL) {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }

        while (head1 != NULL) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }

        while (head2 != NULL) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }

        if (head != NULL) head->left = NULL;
        return head;
    }

    TreeNode* SortedLL_ToBST(TreeNode*& head, int n) {
        if (n <= 0 || head == NULL) {
            return NULL;
        }

        TreeNode* leftSubtree = SortedLL_ToBST(head, n / 2);
        TreeNode* root = head;
        root->left = leftSubtree;
        head = head->right;
        root->right = SortedLL_ToBST(head, n - (n / 2) - 1);
        return root;
    }

    int LL_size(TreeNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->right;
        }
        return cnt;
    }

public:
    // O(m+n), O(m+n)
    TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
        // Store inorder of both BST
        vector<int> sorted1, sorted2;
        BstToSortedArray(root1, sorted1);
        BstToSortedArray(root2, sorted2);

        // Merge to sorted arrays
        vector<int> mergedArray = mergeSortedArrays(sorted1, sorted2);

        // Create BST from sorted arrays (inorder)
        TreeNode* root = inorderToBST(0, mergedArray.size() - 1, mergedArray);
        return root;
    }

    // O(m+n), O(h1+h2)
    TreeNode* mergeBST_InPlace(TreeNode* root1, TreeNode* root2) {
        // Convert BST's to sorted LL
        TreeNode* head1 = NULL, * head2 = NULL;
        BstToDLL(root1, head1);
        BstToDLL(root2, head2);

        // Merge two sorted LL
        TreeNode* head = mergeSortedLL(head1, head2);

        // Create BST from sorted LL
        int n = LL_size(head);
        TreeNode* root = SortedLL_ToBST(head, n);
        return root;
    }
};

// --- Test helpers and main ---
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Prepare first pair of BSTs
    TreeNode* r1 = NULL;
    int vals1[] = {100, 50, 150, 25, 75};
    for (int v : vals1) r1 = insertBST(r1, v);

    TreeNode* r2 = NULL;
    int vals2[] = {80, 60, 120, 110, 130};
    for (int v : vals2) r2 = insertBST(r2, v);

    cout << "mergeBST (new tree from arrays) inorder: ";
    TreeNode* m1 = sol.mergeBST(r1, r2);
    printInorder(m1);
    cout << '\n';

    // Recreate trees for in-place merge (since in-place modifies nodes)
    TreeNode* r1b = NULL;
    for (int v : vals1) r1b = insertBST(r1b, v);
    TreeNode* r2b = NULL;
    for (int v : vals2) r2b = insertBST(r2b, v);

    cout << "mergeBST_InPlace (reused nodes) inorder: ";
    TreeNode* m2 = sol.mergeBST_InPlace(r1b, r2b);
    printInorder(m2);
    cout << '\n';

    return 0;
}