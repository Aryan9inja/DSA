#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int n;

    cin >> n;
    cin >> s;

    if (s[0] == '1') {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') ans++;
        }
        cout << ans << "\n";
        return;
    }

    int x = 0;
    while (x < n && s[x] == '0') {
        x++;
    }

    if (x == n) {
        cout << 0 << "\n";
        return;
    }

    int zeros = 0;
    for (int i = x; i < n; i++) {
        if (s[i] == '0') zeros++;
    }

    int ans = zeros;
    int ones = 0;

    for (int i = x; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        }
        else {
            zeros--;
        }
        ans = min(ans, ones + zeros);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}