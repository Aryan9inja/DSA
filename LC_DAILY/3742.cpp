#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int k, int currCost, int i, int j) {
        if (i >= m || j >= n || currCost > k)
            return -1;

        if (i == m - 1 && j == n - 1)
            return 0;

        if (dp[i][j][currCost] != -2)
            return dp[i][j][currCost];

        int best = -1;

        // Try right
        if (j + 1 < n) {
            int nextVal = grid[i][j + 1];
            int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;

            if (currCost + nextCost <= k) {
                int sub = solve(grid, k, currCost + nextCost, i, j + 1);
                if (sub != -1)
                    best = max(best, nextVal + sub);
            }
        }

        // Try down
        if (i + 1 < m) {
            int nextVal = grid[i + 1][j];
            int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;

            if (currCost + nextCost <= k) {
                int sub = solve(grid, k, currCost + nextCost, i + 1, j);
                if (sub != -1)
                    best = max(best, nextVal + sub);
            }
        }

        return dp[i][j][currCost] = best;
    }

    int tabulation(vector<vector<int>>& grid, int k) {
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Base case
        for (int c = 0; c <= k; c++)
            dp[m - 1][n - 1][c] = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                for (int cost = 0; cost <= k; cost++) {
                    int best = -1;

                    if (j + 1 < n) {
                        int nextVal = grid[i][j + 1];
                        int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;
                        if (cost + nextCost <= k) {
                            int sub = dp[i][j + 1][cost + nextCost];
                            if (sub != -1)
                                best = max(best, nextVal + sub);
                        }
                    }

                    if (i + 1 < m) {
                        int nextVal = grid[i + 1][j];
                        int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;
                        if (cost + nextCost <= k) {
                            int sub = dp[i + 1][j][cost + nextCost];
                            if (sub != -1)
                                best = max(best, nextVal + sub);
                        }
                    }

                    dp[i][j][cost] = best;
                }
            }
        }

        return dp[0][0][0];
    }

    int spaceOptimal(vector<vector<int>>& grid, int k) {
        vector<vector<int>> curr(n, vector<int>(k + 1, -1));
        vector<vector<int>> prev(n, vector<int>(k + 1, -1)); // row below current

        for (int i = m - 1; i >= 0; i--) {
            // reset curr for this row
            for (int j = 0; j < n; j++) fill(curr[j].begin(), curr[j].end(), -1);

            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    for (int c = 0; c <= k; c++) curr[j][c] = 0;
                    continue;
                }
                for (int cost = 0; cost <= k; cost++) {
                    int best = -1;

                    // right: same row, j+1 already computed (j iterates right to left)
                    if (j + 1 < n) {
                        int nextVal = grid[i][j + 1];
                        int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;
                        if (cost + nextCost <= k) {
                            int sub = curr[j + 1][cost + nextCost];
                            if (sub != -1) best = max(best, nextVal + sub);
                        }
                    }

                    // down: row below = prev
                    if (i + 1 < m) {
                        int nextVal = grid[i + 1][j];
                        int nextCost = (nextVal == 1 || nextVal == 2) ? 1 : 0;
                        if (cost + nextCost <= k) {
                            int sub = prev[j][cost + nextCost];
                            if (sub != -1) best = max(best, nextVal + sub);
                        }
                    }

                    curr[j][cost] = best;
                }
            }
            swap(curr, prev); // prev becomes the row we just filled
        }

        return prev[0][0];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // -2 = unvisited sentinel
        // dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));
        // return solve(grid, k, 0, 0, 0);

        // return tabulation(grid, k);

        return spaceOptimal(grid, k);
    }
};