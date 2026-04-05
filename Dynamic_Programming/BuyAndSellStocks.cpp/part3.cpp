#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& prices, int index, bool canBuy, int limit) {
        if (index == prices.size() || limit == 0) {
            return 0;
        }

        int profit = 0;
        if (canBuy) {
            int buying =
                -prices[index] + recursive(prices, index + 1, false, limit);
            int skipping = recursive(prices, index + 1, true, limit);
            profit = max(buying, skipping);
        } else {
            // Limit decrease because transaction complete after buy-sell cycle
            int selling =
                prices[index] + recursive(prices, index + 1, true, limit - 1);
            int skipping = recursive(prices, index + 1, false, limit);
            profit = max(skipping, selling);
        }
        return profit;
    }

    int memoization(vector<int>& prices, int index, bool canBuy, int limit,
                    vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || limit == 0) {
            return 0;
        }

        if (dp[index][canBuy][limit] != -1) {
            return dp[index][canBuy][limit];
        }

        int profit = 0;
        if (canBuy) {
            int buying = -prices[index] +
                         memoization(prices, index + 1, false, limit, dp);
            int skipping = memoization(prices, index + 1, true, limit, dp);
            profit = max(buying, skipping);
        } else {
            // Limit decrease because transaction complete after buy-sell cycle
            int selling = prices[index] +
                          memoization(prices, index + 1, true, limit - 1, dp);
            int skipping = memoization(prices, index + 1, false, limit, dp);
            profit = max(skipping, selling);
        }
        return dp[index][canBuy][limit] = profit;
    }

    int tabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (canBuy) {
                        int buying = -prices[index] + dp[index + 1][0][limit];
                        int skipping = dp[index + 1][1][limit];
                        profit = max(buying, skipping);
                    } else {
                        int selling = prices[index] + dp[index + 1][1][limit-1];
                        int skipping = dp[index + 1][0][limit];
                        profit = max(skipping, selling);
                    }
                    dp[index][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int spaceOptimal(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (canBuy) {
                        int buying = -prices[index] + next[0][limit];
                        int skipping = next[1][limit];
                        profit = max(buying, skipping);
                    } else {
                        int selling = prices[index] + next[1][limit-1];
                        int skipping = next[0][limit];
                        profit = max(skipping, selling);
                    }
                    curr[canBuy][limit] = profit;
                }
                next=curr;
            }
        }
        return next[1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        // return recursive(prices, 0, true, 2);

        // int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return memoization(prices, 0, true, 2, dp);

        // return tabulation(prices);

        return spaceOptimal(prices);
    }
};