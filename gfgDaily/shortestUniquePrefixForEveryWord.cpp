#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    vector<string> findPrefixes(vector<string>& arr) {
        vector<string> ans;

        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            bool found = false;

            for (int len = 1; len <= word.size(); len++) {
                string prefix = word.substr(0, len);

                bool unique = true;

                // Compare with every other word
                for (int j = 0; j < arr.size(); j++) {
                    if (i == j)
                        continue;

                    if (arr[j].size() >= len &&
                    arr[j].substr(0, len) == prefix) {
                        unique = false;
                        break;
                    }
                }

                if (unique) {
                    ans.push_back(prefix);
                    found = true;
                    break;
                }
            }

            // In case no unique prefix exists
            if (!found)
                ans.push_back(word);
        }

        return ans;
    }
    */

    class Node {
    private:
        vector<Node*> children;
        int freq;
        char ch;

    public:
        Node(char x) {
            freq = 0;
            ch = x;
            children = vector<Node*>(26, nullptr);
        }

        void insert(string& word) {
            Node* curr = this;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = new Node(c);
                }
                curr = curr->children[c - 'a'];
                curr->freq++;
            }
        }

        int findPrefix(string& word) {
            Node* curr = this;
            for (int i = 0; i < word.length(); i++) {
                curr = curr->children[word[i] - 'a'];

                if (curr->freq == 1) {
                    return i;
                }
            }
            return word.length() - 1;
        }

        void deleteTrie(Node* root) {
            if (root == nullptr)
                return;

            for (int i = 0; i < 26; i++) {
                deleteTrie(root->children[i]);
                delete root->children[i];
            }
        }
    };

    vector<string> findPrefixes(vector<string>& arr) {
        int n = arr.size();

        Node* root = new Node('*');

        // Insert all words into the Trie
        for (int i = 0; i < n; i++) {
            root->insert(arr[i]);
        }

        // Vector to store result prefixes
        vector<string> result;

        // Find minimum unique prefix for each word
        for (int i = 0; i < n; i++) {
            string word = arr[i];

            // Get ending index of minimum prefix
            int endIndex = root->findPrefix(word);

            // Add substring from start to endIndex to result
            result.push_back(word.substr(0, endIndex + 1));
        }

        // Free up the trie space.
        root->deleteTrie(root);

        return result;
    }
};
