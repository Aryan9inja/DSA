#include<bits/stdc++.h>
using namespace std;

class Solution {
    int memoization(vector<int>& dp, int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = (n - 1) * (memoization(dp, n - 1) + memoization(dp, n - 2));
    }

    int tabulation(int n) {
        vector<int> dp(n + 1);

        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }

    int spaceOptimal(int n) {
        if (n == 1) return 0;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 3; i <= n; i++) {
            int curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    /**
     * Derangement recurrence: D(n) = (n-1) * (D(n-1) + D(n-2))
     * Logic:
     * 1. Place item 1 in any of the (n-1) positions (k).
     * 2. If item k goes to position 1, we derange the remaining (n-2) items.
     * 3. If item k does not go to position 1, we derange the remaining (n-1) items.
     */
    int derangeCount(int n) {
        // O(n^2) and O(n) - recurssion
        /*
        if(n==1) return 0;
        if(n==2) return 1;
        return (n-1)*(derangeCount(n-1)+derangeCount(n-2));
        */

        // O(n) and O(n) - memoization (top-down dp)
        /*
        vector<int> dp(n+1, -1);
        return memoization(dp, n);
        */

        // O(n) and O(n) - tabulation (bottom-up dp)
        /*
        return tabulation(n);
        */

        // O(n) and O(1) - space optimal dp
        return spaceOptimal(n);
    }
};