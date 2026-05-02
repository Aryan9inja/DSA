#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isGood(int n) {
        bool diff = false;
        int temp = n;
        int rotated = 0;
        int multiplier = 1;

        while (temp > 0) {
            int digit = temp % 10;
            int rotatedDigit = digit;

            if (digit == 0 || digit == 1 || digit == 8) {
                // Rotates to itself
                rotatedDigit = digit;
            } else if (digit == 2) {
                rotatedDigit = 5;
                diff = true;
            } else if (digit == 5) {
                rotatedDigit = 2;
                diff = true;
            } else if (digit == 6) {
                rotatedDigit = 9;
                diff = true;
            } else if (digit == 9) {
                rotatedDigit = 6;
                diff = true;
            } else {
                // 3, 4, 7 are invalid
                return false;
            }

            rotated += rotatedDigit * multiplier;
            multiplier *= 10;
            temp /= 10;
        }

        return diff;
    }

public:
    int rotatedDigits(int n) {
        // Brute
        /*
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int newNum = solve(i);
            if (isGood(i)){
                cnt++;
            }
        }
        return cnt;
        */

        // DIGIT DP
        // dp[n]==0 -> invalid
        // dp[n]==1 -> valid but not changed
        // dp[n]==2 -> valid as well as changed
        // CHECK LAST DIGIT -> n%10
        // AND CHECK PREFIX -> n/10
        vector<int> dp(n + 1, 0);
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8)
                    dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    cnt++;
                } else
                    dp[i] = 0;
            } else {
                int a = dp[i / 10];
                int b = dp[i % 10];

                if (a == 1 && b == 1)
                    dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    cnt++;
                } else
                    dp[i] = 0;
            }
        }
        return cnt;
    }
};