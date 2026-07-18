#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;

        for (int stone : stones)
            dp[stone] = {};

        dp[0].insert(0);

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        for (int stone : stones) {
            for (int k : dp[stone]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0 && stoneSet.count(stone + jump)) {
                        dp[stone + jump].insert(jump);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};