#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubSeq(const string& word, vector<vector<int>>& pos) {
        int prevIdx = -1;

        for (const char& c : word) {
            vector<int>& indices = pos[c - 'a'];

            auto it = upper_bound(indices.begin(), indices.end(), prevIdx);

            if (it == indices.end()) {
                return false;
            }

            prevIdx = *it;
        }

        return true;
    }

    string findLongestWord(string& s, vector<string>& d) {
        vector<vector<int>> pos(26);

        for (int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string res = "";

        for (const string& word : d) {
            if (word.length() < res.length()) {
                continue;
            }

            if (isSubSeq(word, pos)) {
                if (word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }

        return res;
    }
};
