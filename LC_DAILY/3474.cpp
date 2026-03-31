#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string word(n + m - 1, '?');

        vector<bool> forced(n + m - 1, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?') {
                        word[i + j] = str2[j];
                        forced[i + j] = true;
                    } else if (word[i + j] != str2[j]) {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '?')
                word[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        if (!forced[i + j]) {
                            word[i + j] = (word[i + j] == 'a') ? 'b' : 'a';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed)
                        return "";
                }
            }
        }

        return word;
    }
};