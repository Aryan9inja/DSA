// Count numbers from 1 → N divisible by K.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string s;
    int n;
    int k;
    vector<vector<vector<vector<ll>>>> dp;

    int solve(int pos, int rem, bool tight, bool started) {
        if (pos == n) {
            return (started && rem == 0) ? 1 : 0;
        }

        if (dp[pos][rem][tight][started] != -1) {
            return dp[pos][rem][tight][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        int ans = 0;
        for (int d = 0; d <= limit; d++) {
            bool newStarted = started || (d != 0);
            int newRem;
            if (!newStarted)
                newRem = 0;
            else
                newRem = (rem * 10 + d) % k;

            ans += solve(
                pos + 1,
                newRem,
                tight && (d == limit),
                newStarted
            );
        }

        return dp[pos][rem][tight][started] = ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solution s;
        cin >> s.s;
        cin >> s.k;
        s.n = s.s.size();
        s.dp.assign(s.n, vector<vector<vector<ll>>>(s.k, vector<vector<ll>>(2, vector<ll>(2, -1))));

        cout << s.solve(0, 0, true, false) << "\n";
    }

    return 0;
}