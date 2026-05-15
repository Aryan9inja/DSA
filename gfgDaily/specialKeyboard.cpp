#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int optimalKeys(int n) {
        if (n <= 6)
            return n;

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        for (int i = 7; i <= n; i++) {
            for (int j = i - 3; j >= 1; j--) {
                // (i - j - 1) is the multiplier
                // If j is the point where we copy,
                // then i-j-1 is the (1 original + number of pastes)
                int current_total = (i - j - 1) * dp[j];

                if (current_total > dp[i]) {
                    dp[i] = current_total;
                }
            }
        }

        return dp[n];
    }
};
