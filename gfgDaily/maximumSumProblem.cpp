#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(int n) {
        if (n < 12)
            return n;
        vector<int> dp(n + 1);

        for (int i = 0; i < 12; i++) {
            dp[i] = i;
        }

        for (int i = 12; i <= n; i++) {
            int sum = dp[i / 2] + dp[i / 3] + dp[i / 4];
            dp[i] = max(i, sum);
        }

        return dp[n];
    }
};
