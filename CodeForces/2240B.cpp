#include<bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long free = (r - 1) * m + (c - 1) * n - (r - 1) * (c - 1);

        long long ans = 1;
        long long base = 2;
        while (free > 0) {
            if (free % 2 == 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            free /= 2;
        }

        cout << ans << "\n";
    }

    return 0;
}