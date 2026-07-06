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

        vector<int> a(n);
        for (int& e : a) cin >> e;

        vector<long long> c(n);
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) ones++;
            else if (a[i] == 2) twos++;
            else threes++;
            c[i] = (long long)ones + twos - threes;
        }

        vector<long long> sufMax(n, LLONG_MIN);
        sufMax[n - 2] = c[n - 2];
        for (int k = n - 3; k >= 1; k--) {
            sufMax[k] = max(c[k], sufMax[k + 1]);
        }

        bool isPossible = false;

        ones = 0, twos = 0, threes = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (a[i] == 1) ones++;
            else if (a[i] == 2) twos++;
            else threes++;

            if (ones >= twos + threes) {
                if (sufMax[i + 1] >= c[i]) {
                    isPossible = true;
                    break;
                }
            }
        }

        cout << (isPossible ? "YES" : "NO") << "\n";
    }

    return 0;
}