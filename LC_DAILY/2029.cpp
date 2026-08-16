#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int count[3] = { 0, 0, 0 };

        // Only remainder modulo 3 matters
        for (int i = 0; i < stones.size(); i++) {
            stones[i] %= 3;
            count[stones[i]]++;
        }

        // Even number of remainder-0 stones
        if (count[0] % 2 == 0) {
            // Alice needs both types
            // of non-zero remainders
            return count[1] != 0 && count[2] != 0;
        }

        // Odd number of remainder-0 stones
        // requires a sufficient imbalance
        // between remainder-1 and remainder-2
        return abs(count[2] - count[1]) >= 3;
    }
};