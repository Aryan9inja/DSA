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
        vector<int> x(n);

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            x[i] = temp - (i + 1);
        }

        sort(x.begin(), x.end());

        x.erase(unique(x.begin(), x.end()), x.end());

        int maxi = 1;
        int curr = 1;

        for (int i = 1; i < x.size(); i++) {
            if (x[i] == x[i - 1] + 1) {
                curr++;
            }
            else {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        maxi = max(maxi, curr);

        cout << maxi << "\n";
    }

    return 0;
}