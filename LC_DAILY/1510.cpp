#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squares;

        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        vector<bool> dp(n + 1, false);

        for (int x = 1; x <= n; x++) {
            for (int s : squares) {
                if (s > x)
                    break;

                if (!dp[x - s]) {
                    dp[x] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};