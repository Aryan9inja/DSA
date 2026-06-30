#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        long long pref = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            pref += b[i] - a[i];
            if (pref < 0) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}