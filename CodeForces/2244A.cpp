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

        int maxi = 0;
        int curr = 0;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                curr++;
                maxi = max(maxi, curr);
            }
            else {
                curr = 0;
            }
        }

        cout << (maxi + 1) / 2 << "\n";
    }

    return 0;
}