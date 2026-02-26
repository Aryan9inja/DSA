#include<bits/stdc++.h>
using namespace std;

// Approach 1 - O(M*N) , O(M)
// M - Matched characters
// N - Total strings
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";

    // For iterating through the first string
    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];
        bool isMatch=true;

        // For iterating through rest of strings
        for(int j=1;j<n;j++){
            if(arr[j].length() < i || arr[j][i]!=ch){
                isMatch=false;
                break;
            }
        }
        if(isMatch==false){
            break;
        }else{
            ans.push_back(ch);
        }
    }
    return ans;
}

// Approach 2 - Trie approach - O(M*N), O(M*N)
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCnt;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        childCnt=0;
        isTerminal = false;
    }
};

class Trie{
private:
    TrieNode* root;

    // INSERT
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCnt++;
        }

        insertUtil(child, word.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string &str, string &ans){
        for(char ch : str){
            if(root->childCnt==1){
                ans.push_back(ch);

                // Aage bdho
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal) break;
        }
    }
};

string longestCommonPrefixTrie(vector<string> &arr, int n)
{
    Trie* t=new Trie();

    for(string s : arr){
        t->insert(s);
    }

    string first=arr[0];
    string ans="";

    t->lcp(first,ans);
    return ans;
}