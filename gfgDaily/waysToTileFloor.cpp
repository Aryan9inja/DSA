#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int m, vector<int>& dp) {
        int MOD = 1000000007;
        if (n < m)
            return 1;

        if (n == m)
            return 2;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (solve(n - 1, m, dp) +
            solve(n - m, m, dp)) % MOD;
    }

    int countWays(int n, int m) {
        vector<int> dp(n + 1, -1);

        return solve(n, m, dp);
    }
};
