#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int i, int prev) {
        if (i == arr.size())
            return 0;

        int keep = abs(arr[i] - prev) + solve(arr, i + 1, arr[i]);

        int change = abs(1 - prev) + solve(arr, i + 1, 1);

        return max(keep, change);
    }

    int maxDiffSum(vector<int>& arr) {
        /*
        int n = arr.size();

        int keep = solve(arr, 1, arr[0]);

        int change = solve(arr, 1, 1);

        return max(keep, change);
        */

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = 0; i < n - 1; i++) {
            // Case 1: Current element is changed to 1
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(1 - arr[i]));

            // Case 2: Current element remains as arr[i + 1]
            dp[i + 1][1] = max(dp[i][0] + abs(arr[i + 1] - 1), dp[i][1] + abs(arr[i + 1] - arr[i]));
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
