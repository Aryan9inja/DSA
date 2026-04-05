#include<bits/stdc++.h>
using namespace std;

class Solution {
    int lastWay(vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    if (canBuy) {
                        int buying = -prices[index] + next[0][limit];
                        int skipping = next[1][limit];
                        profit = max(buying, skipping);
                    } else {
                        int selling = prices[index] + next[1][limit - 1];
                        int skipping = next[0][limit];
                        profit = max(skipping, selling);
                    }
                    curr[canBuy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][k];
    }

    int recursive(int k, vector<int>& prices, int operations, int idx) {
        if (idx == prices.size() || operations == 2 * k) {
            return 0;
        }

        int profit = 0;
        if (!(operations & 1)) {
            // Even means buy allowed
            int buying =
                -prices[idx] + recursive(k, prices, operations + 1, idx + 1);
            int skipping = recursive(k, prices, operations, idx + 1);
            profit = max(buying, skipping);
        } else {
            int selling =
                prices[idx] + recursive(k, prices, operations + 1, idx + 1);
            int skipping = recursive(k, prices, operations, idx + 1);
            profit = max(selling, skipping);
        }

        return profit;
    }

    int memoization(int k, vector<int>& prices, int operations, int idx,
                    vector<vector<int>>& dp) {
        if (idx == prices.size() || operations == 2 * k) {
            return 0;
        }

        if (dp[idx][operations] != -1) {
            return dp[idx][operations];
        }

        int profit = 0;
        if (!(operations & 1)) {
            // Even means buy allowed
            int buying = -prices[idx] +
                         memoization(k, prices, operations + 1, idx + 1, dp);
            int skipping = memoization(k, prices, operations, idx + 1, dp);
            profit = max(buying, skipping);
        } else {
            int selling = prices[idx] +
                          memoization(k, prices, operations + 1, idx + 1, dp);
            int skipping = memoization(k, prices, operations, idx + 1, dp);
            profit = max(selling, skipping);
        }

        return dp[idx][operations] = profit;
    }

    int tabulation(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int operations = 0; operations < 2 * k; operations++) {
                int profit = 0;
                if (!(operations & 1)) {
                    // Even means buy allowed
                    int buying = -prices[idx] + dp[idx + 1][operations + 1];
                    int skipping = dp[idx + 1][operations];
                    profit = max(buying, skipping);
                } else {
                    int selling = prices[idx] + dp[idx + 1][operations + 1];
                    int skipping = dp[idx + 1][operations];
                    profit = max(selling, skipping);
                }

                dp[idx][operations] = profit;
            }
        }
        return dp[0][0];
    }

    int spaceOptimal(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int operations = 0; operations < 2 * k; operations++) {
                int profit = 0;
                if (!(operations & 1)) {
                    // Even means buy allowed
                    int buying = -prices[idx] + next[operations + 1];
                    int skipping = next[operations];
                    profit = max(buying, skipping);
                } else {
                    int selling = prices[idx] + next[operations + 1];
                    int skipping = next[operations];
                    profit = max(selling, skipping);
                }

                curr[operations] = profit;
            }
            next=curr;
        }
        return next[0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        // return lastWay(prices, k);

        // return recursive(k, prices, 0, 0);

        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        // return memoization(k, prices, 0, 0, dp);

        // return tabulation(k, prices);

        return spaceOptimal(k, prices);
    }
};