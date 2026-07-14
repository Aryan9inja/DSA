#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll curr = 0;
        bool possible = true;

        ll i = 1;
        while (i <= n) {
            ll a;
            cin >> a;

            curr += a;
            if (curr < (i * (i + 1) / 2)) {
                possible = false;
            }

            i++;
        }

        if (possible) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}