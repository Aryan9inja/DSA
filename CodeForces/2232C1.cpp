#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        vector<int> dp(x + 1, -1);

        dp[x] = 0;

        for (char c : u) {
            vector<int> next_dp = dp;

            for (int j = 0; j <= x; ++j) {
                if (dp[j] == -1) continue;

                int partial_seats = (x - j) * s - dp[j];

                if (c == 'I' || c == 'A') {
                    if (j > 0) {
                        next_dp[j - 1] = max(next_dp[j - 1], dp[j] + 1);
                    }
                }

                if (c == 'E' || c == 'A') {
                    if (partial_seats > 0) {
                        next_dp[j] = max(next_dp[j], dp[j] + 1);
                    }
                }
            }
            dp = move(next_dp);
        }

        int max_seated = 0;
        for (int j = 0; j <= x; ++j) {
            max_seated = max(max_seated, dp[j]);
        }

        cout << max_seated << "\n";
    }

    return 0;
}