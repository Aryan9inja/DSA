#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int M, int idx) {
        if (idx >= n) {
            return 0;
        }

        if (idx + M * 2 >= n) {
            return suffix[idx];
        }

        if (dp[idx][M] != -1) {
            return dp[idx][M];
        }

        int maxi = 0;
        for (int i = 1; i <= 2 * M && idx + i <= n; i++) {
            int nextM = max(M, i);
            int curr = suffix[idx] - solve(nextM, idx + i);
            maxi = max(maxi, curr);
        }

        return dp[idx][M] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(1, 0);
    }
};