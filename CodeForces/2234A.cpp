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
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            cin >> ans[i];
        }

        sort(ans.begin(), ans.end(), greater<int>());

        if (n == 2) {
            cout << ans[0] << "\n";
            cout << ans[1] << "\n";
        }
        else {
            int i = 0, j = i + 1, k = i + 2;

            while (k < n) {
                if (ans[j] == 0 || ans[k] != ans[i] % ans[j]) {
                    cout << -1 << "\n";
                    break;
                }
                i++;
                j++;
                k++;
            }

            if (k >= n) {
                cout << ans[0] << "\n";
                cout << ans[1] << "\n";
            }
        }
    }

    return 0;
}