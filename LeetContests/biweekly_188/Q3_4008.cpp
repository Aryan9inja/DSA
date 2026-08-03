#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<ll> diff(n + 1, 0);
        for (const auto& boost : boosts) {
            int l = boost[0];
            int r = boost[1];
            ll v = boost[2];

            diff[l] += v;
            diff[r + 1] -= v;
        }

        vector<ll> bonus(n, 0);
        ll currBonus = 0;
        for (int i = 0; i < n; i++) {
            currBonus += diff[i];
            bonus[i] = currBonus;
        }

        ll l = 0;
        ll r = 0;
        for (const int& m : monsters) {
            r += (ll)m;
        }

        ll ans = r;

        auto possible = [&](ll strength) {
            ll currStrength = strength;
            for (int i = 0; i < n; i++) {
                if (currStrength + bonus[i] < monsters[i]) return false;

                currStrength = max(0LL, currStrength - monsters[i]);
            }
            return true;
            };

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (possible(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};