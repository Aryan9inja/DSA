#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int i = 1;

        vector<int> a(n + 1);
        while (i <= n) {
            cin >> a[i];
            i++;
        }

        int g = std::gcd(x, y);
        i = 1;

        bool possible = true;
        while (i <= n) {
            if (abs(a[i] - i) % g != 0) {
                possible = false;
                break;
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
