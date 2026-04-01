#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(int n) {
        if (n <= 1)
            return 1;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // i-1 left side of B.Tree
            // n-i right side of B.Tree
            ans += recursive(i - 1) * recursive(n - i);
        }

        return ans;
    }

    int memoization(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // i-1 left side of B.Tree
            // n-i right side of B.Tree
            ans += recursive(i - 1) * recursive(n - i);
        }

        return dp[n] = ans;
    }

    int tabulation(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // j-1 left side of B.Tree
                // i-j right side of B.Tree
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }

public:
    int numTrees(int n) {
        // return recursive(n);

        // vector<int> dp(n + 1, -1);
        // return memoization(n, dp);

        return tabulation(n);
    }
};