#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";
        ans.reserve(s.length());

        for (char& c : s) {
            if (c == '(') {
                if (open) {
                    ans.push_back(c);
                }
                open++;
            }
            else {
                open--;
                if (open) {
                    ans.push_back(')');
                }
            }
        }

        return ans;
    }
};