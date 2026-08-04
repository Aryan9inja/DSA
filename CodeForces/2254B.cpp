#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int x = 1;
        int i = 1;
        while(i<n) {
            if (s[i] != s[i - 1]) x++;
            i++;
        }

        int ans = x;
        for (i = 1; i < n - 1; i++) {
            if (s[i] == s[i - 1] || s[i] == s[i + 1]) continue;

            if (s[i - 1] == s[i + 1]) {
                ans = x - 2;
                break;
            }

            ans = min(ans, x - 1);
        }

        cout << ans << "\n";
    }

    return 0;
}