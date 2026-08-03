#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int count(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        vector<vector<int>> factors(m + 1);
        vector<vector<int>> multiples(m + 1);

        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j += i) {
                factors[j].push_back(i);

                if (j != i) {
                    multiples[i].push_back(j);
                }
            }
        }

        for (int val = 1; val <= m; val++) {
            dp[1][val] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int curr = 1; curr <= m; curr++) {
                for (int prev : factors[curr]) {
                    dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % mod;
                }

                for (int prev : multiples[curr]) {
                    dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % mod;
                }
            }
        }

        int ans = 0;

        for (int val = 1; val <= m; val++) {
            ans = (ans + dp[n][val]) % mod;
        }

        return ans;
    }
};
