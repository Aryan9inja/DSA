#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long max_val = nums.back();

    vector<long long> optimal_a;
    optimal_a.push_back(max_val);

    vector<long long> leftovers;
    long long target_mex = 0;

    for (long long x : nums) {
        if (x == target_mex) {
            optimal_a.push_back(x);
            target_mex++;
        }
        else {
            leftovers.push_back(x);
        }
    }

    for (long long x : leftovers) {
        optimal_a.push_back(x);
    }

    long long total_sum = 0;
    long long current_max = 0;
    long long current_mex = 0;

    vector<bool> seen(n + 2, false);

    for (int i = 0; i < n; i++) {
        long long x = optimal_a[i];

        current_max = max(current_max, x);
        if (x <= n) {
            seen[x] = true;
        }
        while (seen[current_mex]) {
            current_mex++;
        }

        total_sum += (current_max + current_mex);
    }

    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}