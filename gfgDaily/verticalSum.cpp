#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node* left;
    Node* right;
	Node(int item)
	{
		data = item;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
	public:
	void verticalSumUtil(Node *node, int hd, map<int, int> &mp) {
		
		// Base case
		if (node == nullptr)
			return;
		
		// Recur for left subtree
		verticalSumUtil(node->left, hd - 1, mp);
		
		// Add val of current node to
		// map entry of corresponding hd
		mp[hd] += node->data;
		
		// Recur for right subtree
		verticalSumUtil(node->right, hd + 1, mp);
	}
	
	// Function to find vertical sum
	vector<int> verticalSum(Node *root) {
		
		// a map to store sum of nodes for each
		// horizontal distance
		map <int, int> mp;
		
		// populate the map
		verticalSumUtil(root, 0, mp);
		
		vector<int> result;
		// Prints the values stored by VerticalSumUtil()
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			result.push_back(it->second);
		}
		return result;
	}
};
