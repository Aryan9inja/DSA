#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    long long nCr(long long n, long long r) {
        if (r<0 || r>n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2)r = n - r;

        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }

public:
    int countValidSequences(int n, int k) {
        if (n < k) return 0;

        long long total = nCr(n - 1, k - 1);

        long long ods = 0;

        if ((n - k) % 2 == 0) {
            ods = nCr((n + k - 2) / 2, k - 1);
        }

        long long ans = (total - ods + MOD) % MOD;
        return ans;
    }
};