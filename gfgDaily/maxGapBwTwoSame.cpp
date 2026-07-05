#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCharGap(string& s) {
        vector<int> first(26, -1);
        int res = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            int ch = s[i] - 'a';

            if (first[ch] == -1) {
                first[ch] = i;
            }
            else {
                res = max(res, i - first[ch] - 1);
            }
        }

        return res;
    }
};
