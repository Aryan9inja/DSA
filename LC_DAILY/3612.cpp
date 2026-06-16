#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                res.push_back(c);
            }
            else if (c == '*' && res.size() >= 1) {
                res.pop_back();
            }
            else if (c == '#') {
                res.append(res);
            }
            else {
                reverse(res.begin(), res.end());
            }
        }

        return res;
    }
};