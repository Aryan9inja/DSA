// Painting Fence Problem
// Constraint: No more than 2 adjacent fences can have the same color

#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

// Modular addition
int addUtil(int a, int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

// Modular multiplication
int mulUtil(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

/*
Core Idea:

For nth fence, we have 2 cases:
1. Same color as (n-1) ? allowed ONLY if (n-1) != (n-2)
   ? ways = f(n-2) * (k-1)

2. Different color than (n-1)
   ? ways = f(n-1) * (k-1)

So recurrence:
f(n) = (f(n-1) + f(n-2)) * (k-1)
*/

// Recursive solution (Exponential)
int recursive(int n, int k){
    if(n==1) return k; // One fence ? k choices

    if(n==2){
        // Either same color OR different color
        // k (same) + k*(k-1) (different)
        return addUtil(k, mulUtil(k,k-1));
    }

    int ans = addUtil(
        mulUtil(recursive(n-2,k), k-1), // same color case
        mulUtil(recursive(n-1,k), k-1)  // different color case
    );

    return ans;
}

// Memoization (Top-down DP)
int memoization(int n, int k, vector<int> &dp){
    if(n==1) return k;

    if(n==2){
        return addUtil(k, mulUtil(k,k-1));
    }

    if(dp[n]!=-1) return dp[n]; // reuse computed result

    dp[n] = addUtil(
        mulUtil(memoization(n-2,k,dp), k-1),
        mulUtil(memoization(n-1,k,dp), k-1)
    );

    return dp[n];
}

// Tabulation (Bottom-up DP)
int tabulation(int n, int k){
    vector<int> dp(n+1, 0);

    dp[1] = k;
    dp[2] = addUtil(k, mulUtil(k,k-1));

    // Build solution iteratively
    for(int i=3;i<=n;i++){
        dp[i] = addUtil(
            mulUtil(dp[i-2],k-1),
            mulUtil(dp[i-1],k-1)
        );
    }

    return dp[n];
}

// Space Optimized (only last 2 states needed)
int spaceOptimal(int n, int k){
    int prev2 = k; // f(n-2)
    int prev1 = addUtil(k, mulUtil(k,k-1)); // f(n-1)

    for(int i=3;i<=n;i++){
        int ans = addUtil(
            mulUtil(prev2,k-1),
            mulUtil(prev1,k-1)
        );

        // shift window
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    // return recursive(n,k);

    // vector<int> dp(n+1, -1);
    // return memoization(n,k,dp);

    // return tabulation(n,k);

    return spaceOptimal(n,k); // Best: O(n) time, O(1) space
}