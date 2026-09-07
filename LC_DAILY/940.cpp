#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();

        vector<int> dp(n + 1);
        vector<int> last(26, -1);

        dp[0] = 1; // Empty subsequence

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            dp[i + 1] = (2 * dp[i]) % MOD;

            if (last[c] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[c]] + MOD) % MOD;
            }

            last[c] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; // remove empty
    }
};