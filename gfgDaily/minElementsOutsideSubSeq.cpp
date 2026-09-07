#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int incLast, int decLast, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (idx == arr.size()) {
            return 0;
        }

        if (dp[idx][incLast + 1][decLast + 1] != -1) {
            return dp[idx][incLast + 1][decLast + 1];
        }

        int& ans = dp[idx][incLast + 1][decLast + 1];

        ans = 1 + solve(idx + 1, incLast, decLast, arr, dp);

        if (incLast == -1 || arr[idx] > arr[incLast]) {
            ans = min(ans, solve(idx + 1, idx, decLast, arr, dp));
        }

        if (decLast == -1 || arr[idx] < arr[decLast]) {
            ans = min(ans, solve(idx + 1, incLast, idx, arr, dp));
        }

        return ans;
    }

    int minCount(vector<int>& arr) {
        int n = arr.size();

        vector<vector<vector<int>> > dp(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        return solve(0, -1, -1, arr, dp);
    }
};
