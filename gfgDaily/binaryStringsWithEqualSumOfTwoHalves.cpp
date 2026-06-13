#include<bits/stdc++.h>
using namespace std;

#include <iostream>

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Fast Fourier / Binary Exponentiation: O(log B)
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    // Modular Inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int computeValue(int n) {
        long long numerator = 1;
        long long denominator = 1;

        // Compute (2n)! and n! in a single pass
        for (int i = 1; i <= 2 * n; i++) {
            numerator = (numerator * i) % MOD;
            if (i == n) {
                denominator = numerator; // At i = n, numerator is exactly n!
            }
        }

        // denom = (n! * n!) % MOD
        long long totalDenom = (denominator * denominator) % MOD;

        // Result = (2n)! * (denominator)^-1 % MOD
        long long ans = (numerator * modInverse(totalDenom)) % MOD;

        return ans;
    }
};