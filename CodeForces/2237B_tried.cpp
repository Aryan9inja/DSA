#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (sortedA[i] > b[i]) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        vector<bool> used(n, false);
        vector<int> perm(n);

        for (int pos = n - 1; pos >= 0; pos--) {

            long long limit = (pos == 0 ? -1 : b[pos - 1]);

            bool mustTakeLarge = false;

            for (int k = 0; k < n; k++) {
                if (!used[k] && a[k] > limit) {
                    mustTakeLarge = true;
                    break;
                }
            }

            int chosen = -1;

            for (int idx = n - 1; idx >= 0; idx--) {

                if (used[idx]) continue;
                if (a[idx] > b[pos]) continue;

                if (mustTakeLarge && a[idx] <= limit) {
                    continue;
                }

                chosen = idx;
                break;
            }

            perm[pos] = chosen;
            used[chosen] = true;
        }

        long long inversions = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (perm[i] > perm[j]) {
                    inversions++;
                }
            }
        }

        cout << inversions << '\n';
    }

    return 0;
}