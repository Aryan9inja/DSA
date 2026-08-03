#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n, INT_MIN);

        // solve(0) returns Alice's score minus Bob's score
        int score_diff = solve(stoneValue, 0, memo);

        if (score_diff > 0) return "Alice";
        if (score_diff < 0) return "Bob";
        return "Tie";
    }

private:
    int solve(const vector<int>& stoneValue, int i, vector<int>& memo) {
        int n = stoneValue.size();

        if (i >= n) {
            return 0;
        }

        if (memo[i] != INT_MIN) {
            return memo[i];
        }

        int max_diff = INT_MIN;
        int current_stone_sum = 0;

        for (int k = 0; k < 3 && i + k < n; ++k) {
            current_stone_sum += stoneValue[i + k];

            int diff = current_stone_sum - solve(stoneValue, i + k + 1, memo);
            max_diff = max(max_diff, diff);
        }

        return memo[i] = max_diff;
    }
};