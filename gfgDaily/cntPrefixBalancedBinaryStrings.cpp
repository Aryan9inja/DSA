#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(long long a, long long b, int mod) {
        long long res = 1;

        while (b > 0) {
            // If b is odd, multiply the result
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    int prefixStrings(int n) {
        const int mod = 1000000007;

        // C0 = 1
        long long catalan = 1;

        for (int i = 1; i <= n; i++) {
            // Multiply by 2 * (2i - 1)
            catalan = (catalan * (2LL * (2 * i - 1))) % mod;

            // Divide by (i + 1) using modular inverse
            catalan = (catalan * power(i + 1, mod - 2, mod)) % mod;
        }

        return (int)catalan;
    }
};
