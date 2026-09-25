#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string& expr) {
        opStack.clear();
        setStack.clear();
        opStack.reserve(expr.size());

        char prevChar = '\0';
        for (int i = 0; i < (int)expr.size(); i++) {
            char c = expr[i];

            if (c == ',') {
                collapseUntilOpenBrace();
                opStack.push_back('+');
            }
            else if (c == '{') {
                if (needsImplicitConcat(prevChar)) opStack.push_back('*');
                opStack.push_back('{');
            }
            else if (c == '}') {
                collapseUntilOpenBrace();
                opStack.pop_back();
            }
            else {
                if (needsImplicitConcat(prevChar)) opStack.push_back('*');
                string word = readLetters(expr, i);
                setStack.push_back({ word });
            }

            prevChar = expr[i];
        }

        collapseUntilOpenBrace();

        return dedupedSorted(setStack.front());
    }

private:
    vector<char> opStack;
    vector<vector<string>> setStack;

    static bool needsImplicitConcat(char prevChar) {
        return prevChar == '}' || isalpha(prevChar);
    }

    static string readLetters(const string& expr, int& i) {
        string word;
        while (i < (int)expr.size() && isalpha(expr[i])) {
            word += expr[i];
            i++;
        }
        i--;
        return word;
    }

    void collapseUntilOpenBrace() {
        while (!opStack.empty() && opStack.back() != '{') {
            applyTopOperator();
        }
    }

    void applyTopOperator() {
        vector<string>& left = setStack[setStack.size() - 2];
        vector<string>& right = setStack.back();

        if (opStack.back() == '+') {
            left.insert(left.end(), right.begin(), right.end());
        }
        else { // '*'
            vector<string> combined;
            combined.reserve(left.size() * right.size());
            for (const string& l : left)
                for (const string& r : right)
                    combined.push_back(l + r);
            left = move(combined);
        }

        opStack.pop_back();
        setStack.pop_back();
    }

    static vector<string> dedupedSorted(vector<string> words) {
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        return words;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
    }();