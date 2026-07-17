#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int solve(int amount, vector<int>& coins, int i) {
        if (amount == 0) return 1;

        if (amount < 0 || i == n) return 0;

        if (memo[amount][i] != -1) return memo[amount][i];

        int include = 0;
        if (coins[i] <= amount) {
            include = solve(amount - coins[i], coins, i);
        }

        int exclude = solve(amount, coins, i + 1);

        return memo[amount][i] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        // Initialize memo table with -1
        memo.assign(amount + 1, vector<int>(n, -1));
        return solve(amount, coins, 0);
    }
};