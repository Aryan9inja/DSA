#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

static const ll MOD = 1e9 + 7;

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();

        set<int> candidates;
        candidates.insert(2);

        for (int num : nums) {
            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    if (d > 1) candidates.insert(d);
                    if (num / d > 1) candidates.insert(num / d);
                }
            }
        }

        ll maxDif = -1e18;
        ll bestK = -1;

        for (int k : candidates) {
            ll currMax = -1e18;
            ll sum = 0;

            for (int i = 0; i < n; i++) {
                ll val = (nums[i] % k == 0) ? nums[i] : -nums[i];

                sum += val;

                if (sum > currMax) currMax = sum;
                if (sum < 0) sum = 0;
            }

            if (currMax > maxDif) {
                maxDif = currMax;
                bestK = k;
            }
            else if (currMax == maxDif) {
                if (bestK == -1 || k < bestK) {
                    bestK = k;
                }
            }
        }

        if (bestK == -1) return 0;

        ll ans = (maxDif % MOD) * (bestK % MOD);
        ans = (ans % MOD + MOD) % MOD;

        return ans;
    }
};