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
        string a;
        cin >> a;

        string b;
        cin >> b;

        vector<int> even_a;
        vector<int> odd_a;
        vector<int> even_b;
        vector<int> odd_b;

        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                if (i & 1) odd_a.push_back(i / 2);
                else even_a.push_back(i / 2);
            }
            if (b[i] == '1') {
                if (i & 1) odd_b.push_back(i / 2);
                else even_b.push_back(i / 2);
            }
        }

        if (even_a.size() != even_b.size() || odd_a.size() != odd_b.size()) {
            cout << -1 << "\n";
            continue;
        }

        long long ans = 0;

        for (int i = 0; i < even_a.size(); ++i) {
            ans += abs(even_a[i] - even_b[i]);
        }

        for (int i = 0; i < odd_a.size(); ++i) {
            ans += abs(odd_a[i] - odd_b[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}