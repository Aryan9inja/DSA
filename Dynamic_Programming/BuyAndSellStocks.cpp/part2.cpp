#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& prices, int index, bool canBuy) {
        if (index == prices.size()) {
            return 0;
        }

        int profit = 0;
        if (canBuy) {
            int buying = -prices[index] + recursive(prices, index + 1, false);
            int skipping = recursive(prices, index + 1, true);
            profit = max(buying, skipping);
        } else {
            int selling = prices[index] + recursive(prices, index + 1, true);
            int skipping = recursive(prices, index + 1, false);
            profit = max(skipping, selling);
        }
        return profit;
    }

    int memoization(vector<int>& prices, int index, bool canBuy,
                    vector<vector<int>>& dp) {
        if (index == prices.size()) {
            return 0;
        }

        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        int profit = 0;
        if (canBuy) {
            int buying =
                -prices[index] + memoization(prices, index + 1, false, dp);
            int skipping = memoization(prices, index + 1, true, dp);
            profit = max(buying, skipping);
        } else {
            int selling =
                prices[index] + memoization(prices, index + 1, true, dp);
            int skipping = memoization(prices, index + 1, false, dp);
            profit = max(skipping, selling);
        }
        return dp[index][canBuy] = profit;
    }

    int tabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if (canBuy) {
                    int buying = -prices[index] + dp[index + 1][0];
                    int skipping = dp[index + 1][1];
                    profit = max(buying, skipping);
                } else {
                    int selling = prices[index] + dp[index + 1][1];
                    int skipping = dp[index + 1][0];
                    profit = max(skipping, selling);
                }
                dp[index][canBuy] = profit;
            }
        }
        return dp[0][1];
    }

    int spaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if (canBuy) {
                    int buying = -prices[index] + next[0];
                    int skipping = next[1];
                    profit = max(buying, skipping);
                } else {
                    int selling = prices[index] + next[1];
                    int skipping = next[0];
                    profit = max(skipping, selling);
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        // return recursive(prices, 0, true);

        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memoization(prices, 0, true, dp);

        // return tabulation(prices);

        return spaceOptimized(prices);
    }
};