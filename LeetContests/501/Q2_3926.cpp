#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (const string& chunk : chunks) s += chunk;

        unordered_map<string, int> wordCnt;
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            bool isValidHyphen = false;
            if (c == '-' && i > 0 && i + 1 < s.length()) {
                if ((s[i - 1] >= 'a' && s[i - 1] <= 'z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                    isValidHyphen = true;
                }
            }

            if ((c >= 'a' && c <= 'z') || isValidHyphen) {
                temp += c;
            }
            else {
                if (!temp.empty()) {
                    wordCnt[temp]++;
                    temp = "";
                }
            }
        }

        if (!temp.empty()) wordCnt[temp]++;

        vector<int> ans;
        for (const string& q : queries) {
            ans.push_back(wordCnt.count(q) ? wordCnt[q] : 0);
        }
        return ans;
    }
};