#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n, int m) {
        // A Knight can move in 8 directions, but
        // we only take downward directions to avoid
        // counting same positions twice
        int x_axis[]{ -2, -1, 1, 2 };
        int y_axis[]{ 1, 2, 2, 1 };

        // Total ways to place two Knights
        long long total = m * n;
        total = total * (total - 1);

        // Cunt attackig positions of a single
        // Knight
        long long ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int x = i + x_axis[k], y = j + y_axis[k];
                    if (x >= 0 && x < m && y >= 0 && y < n)

                        // Since (i, j) and (x, y) are attacking
                    // positions for each other, we cannot
                    // place either of the two at any of these
                        ret += 2;
                }
            }
        }

        return total - ret;
    }
};
