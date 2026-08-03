// https://www.cipherschools.com/practice/problems/distinct-divisible-subarrays
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long countDistinctDivisibleSubarrays(vector<int>& nums, int k) {
    unordered_map<ll, ll> cnt;

    cnt[0] = 1;

    ll ans = 0;
    ll pref = 0;

    for (int& n : nums) {
        pref += n;

        int rem = ((pref % k) + k) % k;

        ans += cnt[rem];

        cnt[rem]++;
    }

    int n = nums.size();
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && nums[j] == nums[i]) {
            j++;
        }

        ll len = j - i;
        ll val = nums[i];

        for (ll L = 1; L <= len; L++) {
            if ((L * val) % k == 0) {
                ll occ = len - L + 1;
                ans -= (occ - 1);
            }
        }

        i = j;
    }

    return ans;
}