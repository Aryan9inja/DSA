#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRec(int n, int sum,
        vector<vector<int>>& memo) {
        if (n == 0) {
            return sum == 0;
        }

        if (sum == 0) {
            return 1;
        }

        if (memo[n][sum] != -1) {
            return memo[n][sum];
        }

        int ans = 0;

        for (int i = 0; i <= 9; i++) {
            if (sum - i >= 0) {
                ans += countRec(n - 1,
                    sum - i, memo);
            }
        }

        return memo[n][sum] = ans;
    }

    int countWays(int n, int sum) {
        vector<vector<int>> memo(n + 1,
            vector<int>(sum + 1, -1));

        int ans = 0;

        // Traverse through digits 1-9 as the first
        // digit cannot be zero for n-digit numbers.
        for (int i = 1; i <= 9; i++) {
            if (sum - i >= 0) {
                ans += countRec(n - 1, sum - i, memo);
            }
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};
