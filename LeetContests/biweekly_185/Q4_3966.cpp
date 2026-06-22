#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[16][11][2][2];

    long long solve(const string& s, int idx, int prev, bool tight, bool leading, int k) {
        if (idx == s.length()) return 1;

        if (dp[idx][prev][tight][leading] != -1) {
            return dp[idx][prev][tight][leading];
        }

        int limit = tight ? (s[idx] - '0') : 9;
        long long ans = 0;

        for (int dig = 0; dig <= limit; dig++) {
            bool nextTight = tight && (dig == limit);
            bool nextLeading = leading && (dig == 0);

            if (leading) {
                int nextPrev = nextLeading ? 10 : dig;
                ans += solve(s, idx + 1, nextPrev, nextTight, nextLeading, k);
            }
            else {
                if (abs(dig - prev) <= k) {
                    ans += solve(s, idx + 1, dig, nextTight, nextLeading, k);
                }
            }
        }
        return dp[idx][prev][tight][leading] = ans;
    }

    long long goodIntegers(long long l, long long r, int k) {
        string right = to_string(r);
        memset(dp, -1, sizeof(dp));
        long long ansRight = solve(right, 0, 10, true, true, k);

        long long ansLeft = 0;
        if (l > 0) {
            string left = to_string(l - 1);
            memset(dp, -1, sizeof(dp));
            ansLeft = solve(left, 0, 10, true, true, k);
        }

        return ansRight - ansLeft;
    }
};