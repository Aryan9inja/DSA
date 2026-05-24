// LC 1143 - Longest Common Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp) {
        if (i >= t1.length() || j >= t2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = t1[i] == t2[j];

        int ans = 0;
        if (match) {
            ans = 1 + solve(t1, t2, i + 1, j + 1, dp);
        } else {
            int case1 = solve(t1, t2, i + 1, j, dp);
            int case2 = solve(t1, t2, i, j + 1, dp);

            ans = max(case1, case2);
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(text1, text2, 0, 0, dp);

        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool match = text1[i] == text2[j];

                int ans = 0;
                if (match) {
                    ans = 1 + next[j+1];
                } else {
                    int case1 = next[j];
                    int case2 = curr[j+1];

                    ans = max(case1, case2);
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return curr[0];
    }
};