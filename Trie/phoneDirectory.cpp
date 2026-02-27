#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
private:
    TrieNode* root;

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
        }

        insertUtil(child, word.substr(1));
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string &prefix){
        if(curr->isTerminal) temp.push_back(prefix);

        for(char ch='a';ch<='z';ch++){
            TrieNode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    vector<vector<string>> getSuggestions(string &str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char lastCh=str[i];
            prefix.push_back(lastCh);

            // check for last char
            TrieNode* curr=prev->children[lastCh-'a'];

            // if not found
            if(curr==NULL) break;

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();

    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insert(str);
    }

    return t->getSuggestions(queryStr);
}