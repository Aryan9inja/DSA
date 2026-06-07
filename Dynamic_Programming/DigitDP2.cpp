#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

class Solution {
public:
    string s;
    int n;
    ll dp[20][12][2][2];

    ll solve(int pos, int prev, bool started, bool tight) {
        if (pos == n) {
            return 1;
        }

        // prev + 1 maps -1 to 0, 0-9 to 1-10
        if (dp[pos][prev + 1][started][tight] != -1) {
            return dp[pos][prev + 1][started][tight];
        }

        int limit = tight ? (s[pos] - '0') : 9;
        ll ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newStarted = started || (d != 0);

            if (newStarted && d == prev)
                continue;

            ans += solve(
                pos + 1,
                newStarted ? d : -1,
                newStarted,
                tight && (d == limit)
            );
        }

        return dp[pos][prev + 1][started][tight] = ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string input_s;
        cin >> input_s;

        Solution sol;
        sol.s = input_s;
        sol.n = input_s.size();
        memset(sol.dp, -1, sizeof(sol.dp));

        cout << sol.solve(0, -1, false, true) << endl;
    }
    return 0;
}