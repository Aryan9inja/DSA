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

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && nums[i + 1] > 0) {
                nums[i] += nums[i + 1];
            }
            if (nums[i] > 0) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}