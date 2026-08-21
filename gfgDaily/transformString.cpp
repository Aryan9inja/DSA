#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int transform(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();

        if (n != m)
            return -1;

        unordered_map<char, int> freq;
        for (char c : s1) {
            freq[c]++;
        }

        for (int i = 0; i < m; i++) {
            char ch = s2[i];
            if (freq.count(ch)) {
                freq[ch]--;
            }
        }

        for (auto& it : freq) {
            if (it.second != 0) {
                return -1;
            }
        }

        int res = 0;
        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            while (i >= 0 && s1[i] != s2[j]) {
                i--;
                res++;
            }

            i--;
            j--;
        }

        return res;
    }
};
