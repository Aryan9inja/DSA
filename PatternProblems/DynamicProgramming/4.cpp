#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return 1e9;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = 1e9;
        for (int coin : coins) {
            ans = min(ans, 1 + solve(coins, amount - coin, dp));
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -1);
        // int ans = solve(coins, amount, dp);
        // return ans >= 1e9 ? -1 : ans;

        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for (int a = 1; a <= amount; a++) {
            int ans = 1e9;
            for (int coin : coins) {
                int curr = a - coin;
                if(curr >= 0){
                    ans = min(ans, 1 + dp[curr]);
                }
            }
            dp[a] = ans;
        }

        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};