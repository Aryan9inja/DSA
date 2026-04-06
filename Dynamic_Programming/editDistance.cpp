#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(string& a, string& b, int i, int j) {
        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        int ans = 0;
        if (a[i] == b[j]) {
            return recursive(a, b, i + 1, j + 1);
        } else {
            int inserted = 1 + recursive(a, b, i, j + 1);
            int deleted = 1 + recursive(a, b, i + 1, j);
            int replaced = 1 + recursive(a, b, i + 1, j + 1);

            ans = min(inserted, min(deleted, replaced));
        }
        return ans;
    }

    int memoization(string& a, string& b, int i, int j,
                    vector<vector<int>>& dp) {
        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (a[i] == b[j]) {
            return memoization(a, b, i + 1, j + 1, dp);
        } else {
            int inserted = 1 + memoization(a, b, i, j + 1, dp);
            int deleted = 1 + memoization(a, b, i + 1, j, dp);
            int replaced = 1 + memoization(a, b, i + 1, j + 1, dp);

            ans = min(inserted, min(deleted, replaced));
        }
        return dp[i][j] = ans;
    }

    int tabulation(string& a, string& b) {
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j < m; j++) {
            dp[n][j] = m - j;
        }

        for (int i = 0; i < n; i++) {
            dp[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i+1][j+1];
                } else {
                    int inserted = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replaced = 1 + dp[i+1][j+1];

                    ans = min(inserted, min(deleted, replaced));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int spaceOptimal(string& a, string& b) {
        int n = a.length();
        int m = b.length();

        if(n==0) return m;
        if(m==0) return n;

        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);

        for (int j = 0; j < m; j++) {
            next[j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                curr[m]=n-i; // This is the catch
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = next[j+1];
                } else {
                    int inserted = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replaced = 1 + next[j+1];

                    ans = min(inserted, min(deleted, replaced));
                }
                curr[j] = ans;
            }
            next=curr;
        }
        return next[0];
    }

public:
    int minDistance(string& word1, string& word2) {
        // return recursive(word1, word2, 0, 0);

        // int n = word1.length();
        // int m = word2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memoization(word1, word2, 0, 0, dp);

        // return tabulation(word1, word2);

        return spaceOptimal(word1, word2);
    }
};