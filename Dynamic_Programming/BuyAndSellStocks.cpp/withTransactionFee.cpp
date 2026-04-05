#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                    int selling = prices[index] + next[1] - fee;
                    int skipping = next[0];
                    profit = max(skipping, selling);
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};