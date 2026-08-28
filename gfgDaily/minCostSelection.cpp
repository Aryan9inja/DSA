#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int n;
    vector<vector<int>> dp;

    int solve(int i, int prev, vector<vector<int>> &mat) {
        if (i == n) {
            return 0;
        }

        if (dp[i][prev] != -1) {
            return dp[i][prev];
        }

        int ans = INT_MAX;

        for (int choice = 0; choice < 3; choice++) {
            if (choice != prev) {
                ans = min(ans, mat[i][choice] + solve(i + 1, choice, mat));
            }
        }

        return ans;
    }
    */

    int minCost(vector<vector<int>>& mat) {
        /*
        n = mat.size();
        dp.assign(n, vector<int>(3, -1));

        int solve0 = mat[0][0] + solve(1, 0, mat);
        int solve1 = mat[0][1] + solve(1, 1, mat);
        int solve2 = mat[0][2] + solve(1, 2, mat);

        return min({solve0, solve1, solve2});
        */

        /*
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = mat[0][0];
        dp[0][1] = mat[0][1];
        dp[0][2] = mat[0][2];

        for(int i=1; i<n; i++){
            dp[i][0] = mat[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = mat[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = mat[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
        */

        int n = mat.size();
        int prev0 = mat[0][0];
        int prev1 = mat[0][1];
        int prev2 = mat[0][2];

        for (int i = 1; i < n; i++) {
            int curr0 = mat[i][0] + min(prev1, prev2);
            int curr1 = mat[i][1] + min(prev0, prev2);
            int curr2 = mat[i][2] + min(prev0, prev1);

            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }

        return min({ prev0, prev1, prev2 });
    }
};
