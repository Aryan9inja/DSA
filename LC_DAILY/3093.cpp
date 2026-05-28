#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        int children[26];
        int bestIdx; 
        
        TrieNode() {
            // -1 indicates no child exists yet
            fill(begin(children), end(children), -1);
            bestIdx = -1; // Fixed the uninitialized bug
        }
    };
    
    // The contiguous block of memory holding all our nodes
    vector<TrieNode> trie;

    void updateBestIndex(int nodeIdx, int newIdx, const vector<string>& wordsContainer) {
        if (trie[nodeIdx].bestIdx == -1) {
            trie[nodeIdx].bestIdx = newIdx;
            return;
        }
        
        int oldIdx = trie[nodeIdx].bestIdx;
        int oldLength = wordsContainer[oldIdx].length();
        int newLength = wordsContainer[newIdx].length();
        
        if (newLength < oldLength) {
            trie[nodeIdx].bestIdx = newIdx;
        } else if (newLength == oldLength && newIdx < oldIdx) {
            trie[nodeIdx].bestIdx = newIdx;
        }
    }

    void insert(const string& word, int index, const vector<string>& wordsContainer) {
        int curr = 0; // The root node is always at index 0
        updateBestIndex(curr, index, wordsContainer);
        
        for (int i = word.length() - 1; i >= 0; i--) {
            int charIndex = word[i] - 'a';
            
            // If the path doesn't exist, create a new node in our vector
            if (trie[curr].children[charIndex] == -1) {
                trie[curr].children[charIndex] = trie.size();
                trie.emplace_back(); 
            }
            
            curr = trie[curr].children[charIndex];
            updateBestIndex(curr, index, wordsContainer);
        }
    }

    int search(const string& query) {
        int curr = 0;
        for (int i = query.length() - 1; i >= 0; i--) {
            int charIndex = query[i] - 'a';
            if (trie[curr].children[charIndex] == -1) {
                break; // This matches exact search logic
            }
            curr = trie[curr].children[charIndex];
        }
        return trie[curr].bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Pre-allocate memory to prevent the vector from resizing itself during insertion.
        // The constraints say at most 5 * 10^5 characters total.
        trie.reserve(500005); 
        trie.emplace_back(); // Push the root node at index 0
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }
        
        return ans;
    }
};