#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    long long count(long long x, vector<int>& coins) {
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    lcm = (lcm / gcd(lcm, (long long)coins[i])) * coins[i];

                    if (lcm > x) {
                        break;
                    }
                }
            }

            if (lcm > x) {
                continue;
            }

            long long multiples = x / lcm;

            if (bits & 1) {
                ans += multiples;
            }
            else {
                ans -= multiples;
            }
        }

        return ans;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();

        int minimumDenominator = 26;
        for (int c : coins) {
            minimumDenominator = min(minimumDenominator, c);
        }

        if (n == 1) {
            return (long long)minimumDenominator * k;
        }

        if (k == 1) {
            return minimumDenominator;
        }

        long long lo = minimumDenominator;
        long long hi = (long long)minimumDenominator * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }
};