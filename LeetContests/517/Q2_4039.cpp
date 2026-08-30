#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int sumDecoded(vector<long long>& nums) {
        long long total = 0;

        for (long long n : nums) {
            int width = n % 10;
            long long d = n / 10;

            long long temp = d;
            int totalDigits = 0;
            while (temp > 0) {
                totalDigits++;
                temp /= 10;
            }

            int yDig = totalDigits - width;
            long long div = 1;
            for (int i = 0; i < yDig; i++) {
                div *= 10;
            }

            long long x = d / div;
            long long y = d % div;

            total = (total + modPow(x, y)) % mod;
        }

        return total;
    }
};