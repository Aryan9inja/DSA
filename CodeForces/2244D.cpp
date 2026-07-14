#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int i = 0;

        vector<long long> a(n);
        while (i < n) {
            cin >> a[i];
            i++;
        }

        i = 0;
        vector<int> b(m);
        while (i < m) {
            cin >> b[i];
            i++;
        }

        sort(b.begin(), b.end());

        long long maxi = 0;
        int prevB = 0;

        i = 0;
        while (i < m) {
            long long currSegSum = 0;

            int j = prevB;
            while (j < b[i]) {
                currSegSum += a[j];
                j++;
            }

            maxi += abs(currSegSum);
            prevB = b[i];

            i++;
        }

        long long lastSegSum = 0;
        i = prevB;
        while (i < n) {
            lastSegSum += a[i];
            i++;
        }

        maxi += lastSegSum;

        cout << maxi << "\n";
    }

    return 0;
}