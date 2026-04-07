#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursive(string& str, string& pattern, int i, int j) {
        if (i < 0 && j < 0)
            return true;
        else if (i >= 0 && j < 0)
            return false;
        else if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pattern[k] != '*')
                    return false;
            }
            return true;
        }

        // match
        if (str[i] == pattern[j] || pattern[j] == '?') {
            return recursive(str, pattern, i - 1, j - 1);
        } else if (pattern[j] == '*') {
            bool empty = recursive(str, pattern, i, j - 1);
            bool match = recursive(str, pattern, i - 1, j); // * -> *b
            return empty || match;
        }
        // no match
        else {
            return false;
        }
    }

    // Not GOOD
    bool memoized(string& str, string& pattern, int i, int j,
                  vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        else if (i > 0 && j == 0)
            return false;
        else if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (pattern[k - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // match
        if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
            return dp[i][j] = memoized(str, pattern, i - 1, j - 1, dp);
        } else if (pattern[j - 1] == '*') {
            bool empty = memoized(str, pattern, i, j - 1, dp);
            bool match = memoized(str, pattern, i - 1, j, dp); // * -> *b
            return dp[i][j] = (empty || match);
        }
        // no match
        else {
            return false;
        }
    }

    bool tabulation(string& str, string& pattern) {
        int n = str.length();
        int m = pattern.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = false;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // match
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    bool empty = dp[i][j - 1];
                    bool match = dp[i - 1][j]; // * -> *b
                    dp[i][j] = (empty || match);
                }
                // no match
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }

    bool spaceOptimal(string& str, string& pattern) {
        int n = str.length();
        int m = pattern.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);

        prev[0] = true;

        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '*') {
               prev[j] =prev[j - 1];
            } else {
               prev[j] = false;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // match
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (pattern[j - 1] == '*') {
                    bool empty = curr[j - 1];
                    bool match = prev[j]; // * -> *b
                    curr[j] = (empty || match);
                }
                // no match
                else {
                    curr[j] = false;
                }
            }
            prev=curr;
        }
        return prev[m];
    }

public:
    bool isMatch(string& s, string& p) {
        // return recursive(s, p, s.length()-1, p.length()-1);

        // vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1,
        // -1)); return memoized(s, p, s.length(), p.length(), dp);

        // return tabulation(s, p);

        return spaceOptimal(s, p);
    }
};