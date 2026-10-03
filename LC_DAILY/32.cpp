#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> boundaries;
        boundaries.push_back(-1);

        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                boundaries.push_back(i);
            }
            else {
                boundaries.pop_back();

                if (boundaries.empty()) {
                    // This ')' cannot be matched.
                    // It becomes the new boundary.
                    boundaries.push_back(i);
                }
                else {
                    maxLength = max(maxLength, i - boundaries.back());
                }
            }
        }

        return maxLength;
    }
};