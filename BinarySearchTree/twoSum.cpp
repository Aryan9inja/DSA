#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void createInorder(BinaryTreeNode<int>* root, vector<int> &in){
    BinaryTreeNode<int>* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            in.push_back(curr->data);
            curr=curr->right;
        }
        else{
            BinaryTreeNode<int>* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                in.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    // Inorder is always sorted
	vector<int> inorderVals;
    createInorder(root, inorderVals);

    int i=0, j=inorderVals.size()-1;

    while(i<j){
        int sum=inorderVals[i]+inorderVals[j];

        if(sum==target) return true;

        else if(sum>target) j--;

        else i++;
    }
    return false;
}