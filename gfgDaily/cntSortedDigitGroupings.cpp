#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string& s, int index, int prevSum, vector<vector<int>>& memo) {
        // Base case: if entire string is processed
        if (index == s.length()) {
            return 1;
        }

        // If already computed, return memoized value
        if (memo[index][prevSum] != -1) {
            return memo[index][prevSum];
        }

        int currSum = 0;
        int total = 0;

        // Try all possible groupings starting from index
        for (int i = index; i < s.length(); i++) {
            // Add current digit to sum
            currSum += s[i] - '0';

            // Recurse only if non-decreasing sum condition holds
            if (currSum >= prevSum) {
                total += countWays(s, i + 1, currSum, memo);
            }
        }

        // Memoize and return
        memo[index][prevSum] = total;
        return total;
    }

    // Function to initialize memo and call the DP
    int validGroups(string& s) {
        int n = s.length();

        // memo[i][j]: number of ways from index i with prev sum j
        vector<vector<int>> memo(n + 1, vector<int>(n * 9, -1));

        return countWays(s, 0, 0, memo);
    }
};