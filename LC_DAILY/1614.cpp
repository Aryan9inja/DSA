#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        string x = "";
        for (char& c : s) {
            if (c == '(') {
                x.push_back(c);
            }
            if (c == ')') {
                x.pop_back();
            }
            ans = max(ans, (int)x.length());
        }

        return ans;
    }
};