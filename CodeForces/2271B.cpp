#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> cnt(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (a <= n + 1) {
                cnt[a]++;
            }
        }

        bool aliceWin = false;
        for (int val = 0; val <= n + 1; val++) {
            if (cnt[val] < 2 * k && cnt[val] == 2 * k - 1) {
                aliceWin = true;
                break;
            }
        }

        aliceWin ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}