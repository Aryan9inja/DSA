#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0;i < 26;i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

        // assuming word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(root, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // assuming word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            return false;
        }

        return searchUtil(root, word.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();
    t->insert("ARYAN");
    cout << "Is ARYAN present ?" << "\n";
    bool isPresent = t->search("ARYAN");
    if(isPresent){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
    return 0;
}