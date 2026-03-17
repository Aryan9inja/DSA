#include <bits/stdc++.h> 
using namespace std;

#define MOD 1000000007

int solve(int nStairs, int i, vector<int>& dp) {
    if (i == nStairs) {
        return 1;
    }

    if (i > nStairs) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    dp[i] = (solve(nStairs, i + 1, dp) + solve(nStairs, i + 2, dp)) % MOD;
    return dp[i];
}

int solve2(int nStairs) {
    vector<int> dp(nStairs + 1);

    if (nStairs == 0) return 1;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3;i <= nStairs;i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[nStairs];
}

int solve3(int n) {
    // if(n==0) return 1;
    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2;i <= n;i++) {
        int curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int countDistinctWays(int nStairs) {
    // vector<int> dp(nStairs+1,-1);
    // int ans=solve(nStairs,0,dp);
    // return ans;
    return solve3(nStairs);
}
