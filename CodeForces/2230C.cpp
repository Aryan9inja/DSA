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

        long long ones = 0;
        long long S = 0;
        long long M = 0;
        long long C = 0;

        for (int i = 0; i < n; i++) {
            long long count;
            cin >> count;
            if (count == 1) {
                ones++;
            }
            else {
                C++;
                S += count;
                M += (count - 2) / 2;
            }
        }

        long long ans = 0;

        if (C == 0) {
            ans = 0;
        }
        else if (C == 1) {
            ans = S + min(ones, S / 2);
        }
        else {
            ans = S + min(ones, M);
        }

        if (ans < 3) {
            cout << 0 << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }

    return 0;
}