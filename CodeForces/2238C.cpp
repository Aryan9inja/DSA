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
        long long res = n;

        vector<int> p(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> p[i];
        }

        vector<int> Heights(n + 1, 0);

        vector<int> maxH1(n + 1, -1);
        vector<int> maxH2(n + 1, -1);

        for (int i = n; i >= 2; i--) {
            int height = Heights[i];

            int parent = p[i];

            if (height > maxH1[parent]) {
                maxH2[parent] = maxH1[parent];
                maxH1[parent] = height;
            }
            else if (height > maxH2[parent]) {
                maxH2[parent] = height;
            }

            Heights[parent] = maxH1[parent] + 1;
        }

        for (int i = 1; i <= n; i++)
            if (maxH2[i] != -1)
                res += (maxH2[i] + 1);

        cout << res << "\n";
    }

    return 0;
}