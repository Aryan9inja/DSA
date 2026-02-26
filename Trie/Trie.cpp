#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
private:
    TrieNode* root;

    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i] != NULL)
                return true;
        return false;
    }

    // INSERT
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // SEARCH
    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';

        if (root->children[index] == NULL)
            return false;

        return searchUtil(root->children[index], word.substr(1));
    }

    // REMOVE (space optimized)
    bool removeUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            if (!root->isTerminal) {
                cout << "Word not found\n";
                return false;
            }

            root->isTerminal = false;
            cout << "Word removed\n";

            return !hasChildren(root);
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            cout << "Word not found\n";
            return false;
        }

        // Space Optimization
        bool shouldDeleteChild =
            removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;
        }

        return !root->isTerminal && !hasChildren(root);
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void search(string word) {
        bool res = searchUtil(root, word);
        if (res) {
            cout << "True\n";
        }
        else {
            cout << "False\n";
        }
    }

    void remove(string word) {
        removeUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insert("ARYAN");
    t->insert("IS");
    t->insert("THE");
    t->insert("ARYAB");

    cout<<"Is Aryan Present? ";
    t->search("ARYAN");

    t->remove("ARYAB");

    cout<<"Is Aryan Present? ";
    t->search("ARYAN");
}