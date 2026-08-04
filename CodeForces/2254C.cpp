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
        string a, b;
        cin >> a >> b;

        int even_a = 0, odd_a = 0;
        int even_b = 0, odd_b = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (i & 1) odd_a++;
                else even_a++;
            }
            if (b[i] == '1') {
                if (i & 1) odd_b++;
                else even_b++;
            }
        }

        if (even_a == even_b && odd_a == odd_b) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}