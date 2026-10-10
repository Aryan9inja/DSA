#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            cout << 0 << "\n";
            continue;
        }

        if (a >= b && !((a - b) & 1)) {
            cout << a << "\n";
            continue;
        }

        if (a + 1 >= b && !((a - b + 1) & 1)) {
            cout << a + 1 << "\n";
            continue;
        }

        cout << -1 << "\n";
    }

    return 0;
}