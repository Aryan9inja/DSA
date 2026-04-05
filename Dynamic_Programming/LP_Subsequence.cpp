#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int spaceOptimal(string& a, string& b) {
        if (a.size() < b.size())
            return spaceOptimal(b, a);

        int n = a.size();
        int m = b.size();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    int case1 = next[j];
                    int case2 = curr[j + 1];
                    ans = max(case1, case2);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    // LCS of string and its reverse
    // will give longest palindromic subsequence
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        return spaceOptimal(s, rev);
    }
};