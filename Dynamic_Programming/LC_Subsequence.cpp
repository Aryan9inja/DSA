#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(string& a, string& b, int i, int j) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }

        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + recursive(a, b, i + 1, j + 1);
        } else {
            int case1 = recursive(a, b, i + 1, j);
            int case2 = recursive(a, b, i, j + 1);
            ans = max(case1, case2);
        }
        return ans;
    }

    int memoization(string& a, string& b, int i, int j,
                    vector<vector<int>>& dp) {
        if (i == a.length() || j == b.length()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + memoization(a, b, i + 1, j + 1, dp);
        } else {
            int case1 = memoization(a, b, i + 1, j, dp);
            int case2 = memoization(a, b, i, j + 1, dp);
            ans = max(case1, case2);
        }
        return dp[i][j] = ans;
    }

    int tabulation(string& a, string& b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    int case1 = dp[i+1][j];
                    int case2 = dp[i][j+1];
                    ans = max(case1, case2);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int spaceOptimal(string& a, string& b) {
        if (a.size() < b.size()) return spaceOptimal(b, a);

        int n = a.size();
        int m = b.size();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[j+1];
                } else {
                    int case1 = next[j];
                    int case2 = curr[j+1];
                    ans = max(case1, case2);
                }
                curr[j] = ans;
            }
            next=curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string& text1, string& text2) {
        // return recursive(text1, text2, 0, 0);

        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memoization(text1, text2, 0, 0, dp);

        // return tabulation(text1, text2);

        return spaceOptimal(text1, text2);
    }
};