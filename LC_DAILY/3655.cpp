#include<bits/stdc++.h>
using namespace std;

// Understood the freakin concept 
// But the code still is diabolical
// Unable to code myself

#define MOD 1000000007

class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sqrtN = 316; 

        // 1. Declare the diff array ONCE outside the loop
        // Size it to handle the largest possible step
        vector<long long> diff(n + sqrtN + 1);

        for (int step = 1; step <= sqrtN; ++step) {
            // 2. Instead of a new vector, just reset the relevant parts
            // Filling with 1 (the identity for multiplication)
            fill(diff.begin(), diff.begin() + n + step, 1);
            
            bool applied = false;
            for (auto& q : queries) {
                if (q[2] == step) {
                    int start = q[0];
                    int limit = q[1];
                    long long mult = q[3];

                    diff[start] = (diff[start] * mult) % MOD;

                    int end = start + ((limit - start) / step) * step + step;
                    if (end < n + step) {
                        diff[end] = (diff[end] * modInverse(mult)) % MOD;
                    }
                    applied = true;
                }
            }

            if (applied) {
                for (int i = 0; i < n; ++i) {
                    if (i >= step) {
                        diff[i] = (diff[i] * diff[i - step]) % MOD;
                    }
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }

        // Large offsets stay the same (O(1) extra space)
        for (auto& q : queries) {
            if (q[2] > sqrtN) {
                int idx = q[0];
                int limit = q[1];
                int offset = q[2];
                long long mult = q[3];

                while (idx <= limit) {
                    nums[idx] = (1LL * nums[idx] * mult) % MOD;
                    idx += offset;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};