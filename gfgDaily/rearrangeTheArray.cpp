#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    // Computes (x^y) % MOD using binary exponentiation.
    long long modPow(int x, int y) {
        long long res = 1;

        while (y) {
            if (y & 1)
                res = (res * x) % MOD;

            x = (1LL * x * x) % MOD;
            y >>= 1;
        }

        return res;
    }

    // Returns the minimum operations required to restore
    // the array to its original state.
    int minOperations(vector<int>& b) {
        int n = b.size();

        vector<bool> vis(n, false);
        vector<int> cycles;

        // Find lengths of all disjoint cycles.
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int cur = i;

                while (!vis[cur]) {
                    vis[cur] = true;

                    // Convert to 0-based indexing.
                    cur = b[cur] - 1;
                    len++;
                }

                cycles.push_back(len);
            }
        }

        // Build SPF (Smallest Prime Factor) array.
        vector<int> spf(n + 1);
        for (int i = 0; i <= n; i++)
            spf[i] = i;

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        unordered_map<int, int> maxPower;

        // Store maximum exponent of every prime
        // appearing in any cycle length.
        for (int len : cycles) {
            unordered_map<int, int> freq;

            while (len > 1) {
                int p = spf[len];
                int cnt = 0;

                while (len % p == 0) {
                    len /= p;
                    cnt++;
                }

                freq[p] = cnt;
            }

            for (auto& it : freq) {
                maxPower[it.first] =
                    max(maxPower[it.first], it.second);
            }
        }

        // Reconstruct LCM modulo MOD.
        long long res = 1;

        for (auto& it : maxPower) {
            res = (res * modPow(it.first, it.second)) % MOD;
        }

        return (int)res;
    }
};
