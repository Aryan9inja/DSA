#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Calculate total prefix sum
        int prefix = 0;
        for (int x : stones)
            prefix += x;

        // At i = n, dp[n] = prefix[n] because no further moves can be made
        int best = prefix;

        // Process positions from n-1 down to 2
        for (int i = n - 1; i >= 2; i--) {
            prefix -= stones[i];       // Move prefix sum from index i+1 to i
            best = max(best, prefix - best); // best holds max(prefix[j] - dp[j])
        }

        return best;
    }
};