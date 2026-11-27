#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int min_p;
    vector<int> freeCnt;
    vector<int> prices;
    vector<vector<int>> memo;

    int solve(int idx, int budget) {
        if (idx == n)
            return budget / min_p;

        if (memo[idx][budget] != -1) {
            return memo[idx][budget];
        }

        // skip
        int maxItems = solve(idx + 1, budget);

        // buy
        if (prices[idx] <= budget) {
            int itemsAquired = 1 + freeCnt[idx];
            maxItems = max(maxItems,
                itemsAquired + solve(idx + 1, budget - prices[idx]));
        }

        return memo[idx][budget] = maxItems;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        freeCnt.assign(n, 0);
        prices.assign(n, 0);
        min_p = 1501;

        for (int i = 0; i < n; i++) {
            prices[i] = items[i][1];
            min_p = min(min_p, prices[i]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        memo.assign(n, vector<int>(budget + 1, -1));

        return solve(0, budget);
    }
};