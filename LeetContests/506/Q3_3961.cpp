#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        long long base = 0;
        for (int i = 0; i < m; i++) {
            sort(units[i].begin(), units[i].end());
            base += units[i][0];
        }

        if (n == 1) return base;

        int mini = units[0][0];
        for (int i = 0; i < m; i++) {
            mini = min(mini, units[i][0]);
        }

        long long totalSum = 0;
        for (int i = 0; i < m; i++) {
            totalSum += units[i][1];
        }

        long long maxTotalSum = base;
        for (int i = 0; i < m; i++) {
            long long sum = totalSum - units[i][1] + mini;
            maxTotalSum = max(maxTotalSum, sum);
        }

        return maxTotalSum;
    }
};