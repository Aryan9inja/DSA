#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_sum = -1e9;

        for (int i = 0; i < m; i++) {
            int curr_dp = grid[i][0];
            for (int j = 1; j < n; j++) {
                max_sum = max(max_sum, curr_dp + grid[i][j]);
                curr_dp = max(grid[i][j], curr_dp + grid[i][j]);
            }
        }

        for (int j = 0; j < n; j++) {
            int curr_dp = grid[0][j];
            for (int i = 1; i < m; i++) {
                max_sum = max(max_sum, curr_dp + grid[i][j]);
                curr_dp = max(grid[i][j], curr_dp + grid[i][j]);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                max_sum = max(max_sum, grid[i][j]);
            }
        }

        return max_sum;
    }
};