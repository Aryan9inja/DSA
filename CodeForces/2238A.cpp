#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int A = 0, B = 0;
        for (int i = 0; i < n; i++) {
            A += a[i];
            B += b[i];
        }

        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                valid = false;
                break;
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool canForm = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                canForm = false;
                break;
            }
        }

        if (!canForm) cout << -1 << "\n";
        else {
            if (valid) cout << A - B << "\n";
            else cout << A - B + c << "\n";
        }
    }

    return 0;
}