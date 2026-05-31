#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long minPrice = 2e18;

        for (const auto& item : items) {
            minPrice = min(minPrice, (long long)item[1]);
        }

        vector<int> freq(n + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> M(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                M[f] += freq[m];
            }
        }

        vector<pair<long long, long long>> deals;
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            long long cap = M[f] - 1;

            if (cap > 0 && p < 2LL * minPrice) {
                deals.push_back({ p,cap });
            }
        }

        sort(deals.begin(), deals.end());

        long long totalItems = 0;

        for (const auto& deal : deals) {
            if (budget <= 0) break;

            long long p = deal.first;
            long long cap = deal.second;

            long long take = min(cap, budget / p);

            totalItems += 2LL * take;
            budget -= take * p;
        }

        totalItems += budget / minPrice;

        return totalItems;
    }
};