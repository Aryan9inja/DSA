#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*
            This looks like a Minimax / DP game, but under the given constraints
            Alice is GUARANTEED to win.

            Why?
            1. Number of piles is even.
            2. Total number of stones is odd, so a tie is impossible.
            3. Before the game starts, Alice compares:
                   - Sum of stones at even indices.
                   - Sum of stones at odd indices.
            4. She chooses the parity (even or odd indices) with the larger sum.
            5. Since she moves first, she can always force herself to take
               every pile of that chosen parity, leaving the other parity for
           Bob.

            Therefore Alice always collects the larger total and wins,
            regardless of the actual pile values.

            Hence the answer is always true.
        */
        return true;
    }
};