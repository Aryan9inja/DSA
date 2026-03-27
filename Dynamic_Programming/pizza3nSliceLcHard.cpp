#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(int idx, int endIdx, vector<int>& slices, int n) {
        if (n == 0 || idx > endIdx) {
            return 0;
        }

        int take = slices[idx] + recursive(idx + 2, endIdx, slices, n - 1);
        int notTake = 0 + recursive(idx + 1, endIdx, slices, n);

        return max(take, notTake);
    }

    int memoization(int idx, int endIdx, vector<int>& slices, int n,
        vector<vector<int>>& dp) {
        if (n == 0 || idx > endIdx) {
            return 0;
        }

        if (dp[n][idx] != -1)
            return dp[n][idx];

        int take =
            slices[idx] + memoization(idx + 2, endIdx, slices, n - 1, dp);
        int notTake = 0 + memoization(idx + 1, endIdx, slices, n, dp);

        return dp[n][idx] = max(take, notTake);
    }

    int tabulation(vector<int>& slices) {
        int k = slices.size();
        int limit = k / 3;

        // Size k+2 to handle the idx+2 offset safely
        vector<vector<int>> dp1(limit + 1, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(limit + 1, vector<int>(k + 2, 0));

        // Case 1: Can take first, cannot take last (0 to k-2)
        for (int n = 1; n <= limit; n++) {
            for (int idx = k - 2; idx >= 0; idx--) {
                int take = slices[idx] + dp1[n - 1][idx + 2];
                int notTake = dp1[n][idx + 1];
                dp1[n][idx] = max(take, notTake);
            }
        }
        int case1 = dp1[limit][0];

        // Case 2: Cannot take first, can take last (1 to k-1)
        for (int n = 1; n <= limit; n++) {
            for (int idx = k - 1; idx >= 1; idx--) {
                int take = slices[idx] + dp2[n - 1][idx + 2];
                int notTake = dp2[n][idx + 1];
                dp2[n][idx] = max(take, notTake);
            }
        }
        int case2 = dp2[limit][1];

        return max(case1, case2);
    }

    int spaceOptimal(vector<int>& slices) {
        int k = slices.size();
        int limit = k / 3;

        // Size k+2 to handle the idx+2 offset safely
        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        // Case 1: Can take first, cannot take last (0 to k-2)
        for (int idx = k - 2; idx >= 0; idx--) {
            for (int n = 1; n <= limit; n++) {
                int take = slices[idx] + next1[n - 1];
                int notTake = curr1[n];
                prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[limit];

        // Case 2: Cannot take first, can take last (1 to k-1)
        for (int idx = k - 1; idx >= 1; idx--) {
            for (int n = 1; n <= limit; n++) {
                int take = slices[idx] + next2[n - 1];
                int notTake = curr2[n];
                prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[limit];

        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // int case1 = recursive(0, k-2, slices, k/3);
        // int case2 = recursive(1, k-1, slices, k/3);
        // return max(case1, case2);

        // int k = slices.size();
        // vector<vector<int>> dp1(k / 3 + 1, vector<int>(k, -1));
        // int case1 = memoization(0, k - 2, slices, k / 3, dp1);
        // vector<vector<int>> dp2(k / 3 + 1, vector<int>(k, -1));
        // int case2 = memoization(1, k - 1, slices, k / 3, dp2);
        // return max(case1, case2);

        // return tabulation(slices);

        return spaceOptimal(slices);
    }
};