#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        if (n == 1) return cost[0];
        if (n == 2) return cost[0] + cost[1];

        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 != 0) {
                ans += cost[i];
            }
        }

        return ans;
    }
};