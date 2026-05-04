#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int reverseDigit(int x) {
        int temp = 0;
        while (x > 0) {
            int dig = x % 10;
            x /= 10;

            temp = temp * 10 + dig;
        }
        return temp;
    }

    bool isPrime(int x) {
        if (x == 1) return false;
        for (int i = 2; i < x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

public:
    int sumOfPrimesInRange(int n) {
        int r = reverseDigit(n);

        int l = min(n, r);
        int h = max(n, r);

        int ans = 0;
        for (int i = l; i <= h; i++) {
            if (isPrime(i)) ans += i;
        }

        return ans;
    }
};